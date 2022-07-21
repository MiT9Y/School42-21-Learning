from concurrent.futures import Executor
from django.views.generic.base import RedirectView, TemplateView
from . import models
from django import forms
from django.contrib.auth.forms import UserCreationForm
from django.views.generic.edit import FormView, CreateView
from django.contrib.auth.models import User
from django.shortcuts import render, reverse
from django.contrib.auth import authenticate, login, logout
from django.contrib import messages
from django.views.generic import DetailView
from django.http import HttpResponse, HttpRequest, HttpResponseRedirect
from typing import Any
from django.urls import reverse_lazy

def get_user_data(request):
    if not request.user.is_authenticated:
        name = 'Anonymous'
        f_login = 0
    else:
        name = request.user.username
        f_login = 1
    return (name, f_login)

class Home(RedirectView):
    pattern_name = 'articles'

class Articles(TemplateView):
    template_name = 'articles.html'

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['articles'] = models.Article.objects.all()
        context['user'] = get_user_data(self.request)
        return context

class Logout(RedirectView):
    template_name = 'articles.html'

    def get(self, request):
        logout(request)
        return HttpResponseRedirect(reverse('articles'))

class Login(FormView):

    template_name = 'login.html'

    class LoginForm(forms.Form):
        name = forms.CharField(label='Name', max_length=32)
        password = forms.CharField(label='Password', max_length=32, widget=forms.PasswordInput)

    def get(self, request, *args, **kwargs):
        return render(request, self.template_name, {'form': self.LoginForm(), 'user':get_user_data(self.request)})

    def post(self, request, *args, **kwargs):
        form = self.LoginForm(request.POST)
        if form.is_valid():
            u_name = form.cleaned_data.get("name")
            u_pass = form.cleaned_data.get("password")
            try:
                User.objects.get(username=str(u_name))
                user = authenticate(username = u_name, password = u_pass)
                if user is not None:
                    login(request, user)
                    return HttpResponseRedirect(reverse('articles'))
                else:
                    messages.error(request, 'Incorrect password')
            except:
                messages.error(request, 'User not found')
        return render(request, self.template_name, {'form' :form, 'user':get_user_data(self.request)})

class Publish(CreateView):

    template_name = 'publish.html'

    class PublishForm(forms.Form):
        title = forms.CharField(label='Title', max_length=64)
        synopsis = forms.CharField(label='Synopsis', max_length=312)
        content = forms.CharField(label='Content', widget=forms.Textarea)

    def get(self, request, *args, **kwargs):
        return render(request, self.template_name, {'form': self.PublishForm(), 'user':get_user_data(self.request)})

    def post(self, request, *args, **kwargs):
        form = self.PublishForm(request.POST)
        if form.is_valid():
            if not self.request.user.is_authenticated:
                return HttpResponseRedirect(reverse('articles'))
            try:
                f_title = form.cleaned_data.get("title")
                f_synopsis = form.cleaned_data.get("synopsis")
                f_content = form.cleaned_data.get("content")
                article = models.Article.objects.create(
                    title = f_title,
                    author = request.user,
                    synopsis = f_synopsis,
                    content = f_content
                )
                article.save()
                return HttpResponseRedirect(reverse('articles'))
            except Exception as e:
                messages.error(request, 'Error: ' + str(e))
        return render(request, self.template_name, {'form' :form, 'user':get_user_data(self.request)})

class Detail(DetailView):
    model = models.Article
    template_name = 'details.html'

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['user'] = get_user_data(self.request)
        return context

class Publications(TemplateView):
    template_name = 'publications.html'

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['articles'] = models.Article.objects.filter(author=self.request.user)
        context['user'] = get_user_data(self.request)
        return context
    
    def get(self, request, *args, **kwargs):
        if not self.request.user.is_authenticated:
            return HttpResponseRedirect(reverse('articles'))
        else:
            return super().get(request, *args, **kwargs)

class Favourites(TemplateView):
    template_name = 'favourites.html'

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['articles'] = models.UserFavouriteArticle.objects.filter(user=self.request.user)
        context['user'] = get_user_data(self.request)
        return context
    
    def get(self, request, *args, **kwargs):
        if not self.request.user.is_authenticated:
            return HttpResponseRedirect(reverse('articles'))
        else:
            return super().get(request, *args, **kwargs)

class Register(CreateView):
    template_name = "register.html"
    success_url = reverse_lazy('articles')

    class RegisterForm(UserCreationForm):
        class Meta:
            model = User
            fields = ("username",  "password1", "password2")

    form_class = RegisterForm

    def get(self, request: HttpRequest, *args: str, **kwargs: Any) -> HttpResponse:
        if self.request.user.is_authenticated:
            return HttpResponseRedirect(reverse('articles'))
        return super().get(request, *args, **kwargs)

    def form_valid(self, form: RegisterForm):
        user = form.save()
        login(self.request, user)
        return super().form_valid(form)

    def form_invalid(self, form):
        messages.error(
            self.request, "Unsuccessful registration. Invalid information.")
        return super().form_invalid(form)

class Init(TemplateView):
    template_name = 'init.html'

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        try:
            u1 = User.objects.get(username='u1')
        except:
            u1 = User.objects.create_user('u1', None, '1')
            u1.save()
        try:
            u2 = User.objects.get(username='u2')
        except:
            u2 = User.objects.create_user('u2', None, '1')
            u2.save()
        try:
            u3 = User.objects.get(username='u3')
        except:
            u3 = User.objects.create_user('u3', None, '1')
            u3.save()
        try:
            models.Article.objects.all().delete()            
            article = models.Article.objects.create(
                title = 'Django (web framework)',
                author = u1,
                synopsis = """Django (/ˈdʒæŋɡoʊ/ JANG-goh; sometimes stylized as django)[6] 
                    is a Python-based web framework, free and open-source, 
                    that follows the model–template–views (MTV) architectural pattern.[7][8] 
                    It is maintained by the Django Software Foundation (DSF), 
                    an independent organization established in the US as a 501(c)(3) non-profit.""",
                content = """Django (/ˈdʒæŋɡoʊ/ JANG-goh; sometimes stylized as django)[6] 
                    is a Python-based web framework, free and open-source, 
                    that follows the model–template–views (MTV) architectural pattern.[7][8] 
                    It is maintained by the Django Software Foundation (DSF), 
                    an independent organization established in the US as a 501(c)(3) non-profit."""            
                    )
            article.save()
            article = models.Article.objects.create(
                title = 'Nginx',
                author = u2,
                synopsis = """Nginx (pronounced "engine X"[9] /ˌɛndʒɪnˈɛks/ EN-jin-EKS), stylized as NGIИX,
                    is a web server that can also be used as a reverse proxy, load balancer, 
                    mail proxy and HTTP cache. The software was created by Igor Sysoev and publicly 
                    released in 2004.[10] Nginx is free and open-source software, released under the 
                    terms of the 2-clause BSD license. A large fraction of web servers use Nginx,[11] 
                    often as a load balancer.[12] """,
                content = """Nginx (pronounced "engine X"[9] /ˌɛndʒɪnˈɛks/ EN-jin-EKS), stylized as NGIИX,
                    is a web server that can also be used as a reverse proxy, load balancer, 
                    mail proxy and HTTP cache. The software was created by Igor Sysoev and publicly 
                    released in 2004.[10] Nginx is free and open-source software, released under the 
                    terms of the 2-clause BSD license. A large fraction of web servers use Nginx,[11] 
                    often as a load balancer.[12] """            
                    )
            article.save()
            fav_article = models.UserFavouriteArticle.objects.create(user = u1, article = article)
            fav_article.save()
            article = models.Article.objects.create(
                title = 'HTML',
                author = u3,
                synopsis = """The HyperText Markup Language or HTML is the standard markup language 
                    for documents designed to be displayed in a web browser. It can be assisted by 
                    technologies such as Cascading Style Sheets (CSS) and scripting languages such 
                    as JavaScript.""",
                content = """The HyperText Markup Language or HTML is the standard markup language 
                    for documents designed to be displayed in a web browser. It can be assisted by 
                    technologies such as Cascading Style Sheets (CSS) and scripting languages such 
                    as JavaScript."""
                    )
            article.save()
            article = models.Article.objects.create(
                title = 'JavaScript',
                author = u1,
                synopsis = """JavaScript (/ˈdʒɑːvəskrɪpt/),[10] often abbreviated JS, is 
                    a programming language that is one of the core technologies of the World Wide Web, 
                    alongside HTML and CSS.[11] Over 97% of websites use JavaScript on the client 
                    side for web page behavior,[12] often incorporating third-party libraries.[13] 
                    All major web browsers have a dedicated JavaScript engine to execute the code 
                    on users' devices. """,
                content = """JavaScript (/ˈdʒɑːvəskrɪpt/),[10] often abbreviated JS, is 
                    a programming language that is one of the core technologies of the World Wide Web, 
                    alongside HTML and CSS.[11] Over 97% of websites use JavaScript on the client 
                    side for web page behavior,[12] often incorporating third-party libraries.[13] 
                    All major web browsers have a dedicated JavaScript engine to execute the code 
                    on users' devices. """            
                    )
            article.save()
            article = models.Article.objects.create(
                title = 'Cat',
                author = u3,
                synopsis = """The cat (Felis catus) is a domestic species of small carnivorous mammal.[1][2] 
                    It is the only domesticated species in the family Felidae and is often referred to as 
                    the domestic cat to distinguish it from the wild members of the family.""",
                content = """he cat (Felis catus) is a domestic species of small carnivorous mammal.[1][2] 
                    It is the only domesticated species in the family Felidae and is often referred to as 
                    the domestic cat to distinguish it from the wild members of the family."""            
                    )
            article.save()
            fav_article = models.UserFavouriteArticle.objects.create(user = u1, article = article)
            fav_article.save()
            text = 'Init data: OK'
        except Exception as e:
            text = 'Init data ERROR: ' + str(e)
        context['text'] = text
        return context
