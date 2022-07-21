from django.shortcuts import render

def index(request):
    names = ('noir', 'rouge', 'bleu', 'vert')
    data = [float(i) / 49.0 for i  in range(0, 50, 1)]
    return render(request, 'ex03/templates/index.html', {'data':data, 'names':names})
