from django.shortcuts import HttpResponse, render

def index(request):
    return render(request, 'ex00/templates/index.html')
#    return HttpResponse("Hello, world. You're at the polls index.")
