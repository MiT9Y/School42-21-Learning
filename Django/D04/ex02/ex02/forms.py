from django import forms

class Form_ex02(forms.Form):
    subject = forms.CharField(label='context', max_length=1000)
    