from statistics import mode
from django.shortcuts import render, redirect, HttpResponse
import random
from django.conf import settings
from . import forms, models
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.models import User
from django.forms.utils import ErrorList

def get_user_data(request):
    if not request.user.is_authenticated:
        if 'user' not in request.session:
            request.session['user'] = random.choice(settings.NAMES)
            request.session.set_expiry(42)
        name = request.session.get('user')
        f_login = 0
    else:
        name = request.user.username
        request.session.set_expiry(240)
        f_login = 1
    return (name, f_login)

def home_page(request):
    form = None
    if request.user.is_authenticated:
        if request.method == 'POST':
            form = forms.Comment(request.POST)
            if form.is_valid():
                text = form.cleaned_data.get('comm')
                tip1 = models.Tips.objects.create(contentue=text, auteur=request.user.username)
                tip1.save()
        else:
            form = forms.Comment()
    tips = models.Tips.objects.all().order_by('-date')
    return render(request, 'index.html', {'user':get_user_data(request), 'tips':tips, 'form':form})

def http_registration(request):
    if request.user.is_authenticated:
        return redirect('/')
    if request.method == 'POST':
        form = forms.Registration(request.POST)
        if form.is_valid():
            u_name, u_pass = form.reg_clean_chk()
            if u_name is not None and u_pass is not None:
                user = User.objects.create_user(u_name, None, u_pass)
                user.save()
                user = authenticate(username = u_name, password = u_pass)
                if user is not None:
                    login(request, user)
                    return redirect('/')
    else:
        form = forms.Registration()
    return render(request, 'registration.html', {'user':get_user_data(request), 'form': form})

def http_login(request):
    if request.user.is_authenticated:
        return redirect('/')
    if request.method == 'POST':
        form = forms.Login(request.POST)
        if form.is_valid():
            u_name = form.data.get("name")
            u_pass = form.cleaned_data.get("password")
            try:
                User.objects.get(username=str(u_name))
                user = authenticate(username = u_name, password = u_pass)
                if user is not None:
                    login(request, user)
                    return redirect('/')
                else:
                    form._errors['password'] = ErrorList()
                    form._errors['password'].append("Incorrect password")
            except:
                form._errors['name'] = ErrorList()
                form._errors['name'].append("User not found")
    else:
        form = forms.Login()
    return render(request, 'login.html', {'user':get_user_data(request), 'form': form})

def http_logout(request):
    if request.user.is_authenticated:
        logout(request)
    return redirect('/')

def http_del(request):
    if request.user.is_authenticated:
        id = request.GET.get('id')
        if id is not None and id.isnumeric():
            try:
                tip = models.Tips.objects.get(id=id)
                print(request.user.has_perm('auth.delete_tips'))
                name = request.user.username
                if request.user.has_perm('auth.delete_tips') or request.user.username == tip.auteur:
                    tip.delete()
            except:
                pass
    return redirect('/')

def http_like(request):
    if request.user.is_authenticated:
        id = request.GET.get('id')        
        if id is not None and id.isnumeric():
            try:
                tip = models.Tips.objects.get(id=id)
            except:
                return redirect('/')
            name = request.user.username
            try:
                voice = models.Voices.objects.get(id_trip = tip.id, auteur = name)
            except:
                voice = models.Voices.objects.create(id_trip = tip.id, auteur = name)
            if voice.voice == 1:
                voice.voice = 0
                tip.up -= 1
            else:
                if voice.voice == 0:
                    tip.up += 1
                else:
                    tip.up += 1
                    tip.down -= 1
                voice.voice = 1
            tip.save()
            voice.save()
    return redirect('/')

def http_dis_like(request):
    if request.user.is_authenticated:
        id = request.GET.get('id')
        if id is not None and id.isnumeric():
            try:
                tip = models.Tips.objects.get(id=id)
            except:
                return redirect('/')
            name = request.user.username
            try:
                voice = models.Voices.objects.get(id_trip = tip.id, auteur = name)
            except:
                voice = models.Voices.objects.create(id_trip = tip.id, auteur = name)
            if voice.voice == -1:
                voice.voice = 0
                tip.down -= 1
            else:
                if voice.voice == 0:
                    tip.down += 1
                else:
                    tip.up -= 1
                    tip.down += 1
                voice.voice = -1
            tip.save()
            voice.save()
    return redirect('/')

def http_get_user_name (request):
    if not request.user.is_authenticated:
        if 'user' not in request.session:
            request.session['user'] = random.choice(settings.NAMES)
            request.session.set_expiry(42)
        name = request.session.get('user')
    else:
        name = request.user.username
    return HttpResponse(name)