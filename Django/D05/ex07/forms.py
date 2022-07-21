from django import forms

class upadte_form(forms.Form):
    subject = forms.ChoiceField(label='Titles')
    comment = forms.CharField(label='Comments', widget=forms.Textarea)
    is_valid = lambda event: True
    