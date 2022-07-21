from django.shortcuts import render

import logging

from . import forms

logger = logging.getLogger(__name__)

def index(request):
    if request.method == 'POST':
        form = forms.Form_ex02(request.POST)
        if form.is_valid():
            logger.critical(form.cleaned_data['subject'])
    else:
        form = forms.Form_ex02()
    try:
        file = open("ex02/journal.log", "r")
        cont = file.readlines()
        file.close()
    except:
        print("Wrong file ")   
    return render(request, 'ex02/templates/index.html', {'form':form, 'cont':cont})