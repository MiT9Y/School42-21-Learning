from django.shortcuts import render

def django(request):
#    return HttpResponse("Hello, world. You're at the polls index.")
    return render(request, 'ex01/templates/django.html', {})

def display(request):
    return render(request, 'ex01/templates/display.html', {})

def templates(request):
    return render(request, 'ex01/templates/templates.html', {})
