from wsgiref import validate
from django import forms

class delete_form(forms.Form):
    subject = forms.ChoiceField(label='Titles')
    is_valid = lambda event: True
    