from django import forms
from django.forms.utils import ErrorList
from django.contrib.auth.models import User

class Comment(forms.Form):
    comm = forms.CharField(label="You comment: ", widget=forms.Textarea)

class Login(forms.Form):
    name = forms.CharField(label='User name', max_length=64)
    password = forms.CharField(label='Password', max_length=64, widget=forms.PasswordInput)

class Registration(forms.Form):
    name = forms.CharField(label='User name', max_length=64)
    password_new = forms.CharField(label='Password', max_length=64, widget=forms.PasswordInput)
    password_check = forms.CharField(label='Repeat password', max_length=64, widget=forms.PasswordInput)

    def reg_clean_chk(self):
        p1 = self.cleaned_data.get("password_new")
        p2 = self.cleaned_data.get("password_check")
        res_p = p1
        if p1 and p2 and p1 != p2:
            self._errors['password_check'] = ErrorList()
            self._errors['password_check'].append("Passwords don't match")
            res_p = None
        res_n = self.data.get("name")
        try:
            User.objects.get(username=str(res_n))
            self._errors['name'] = ErrorList()
            self._errors['name'].append("User already exits")
            res_n = None
        except:
            self.cleaned_data.get("name")
        return res_n, res_p
