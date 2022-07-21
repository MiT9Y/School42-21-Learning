from django.shortcuts import render
from . import models
from . import forms

def insert_row(data):
    try:
        movies = models.Movies(
            episode_nb=data[0],
            title=data[1],
            director=data[2],
            producer=data[3],
            release_date=data[4]
        )
        movies.save(force_insert=True)
#        models.Movies.objects.create(
#            episode_nb=data[0],
#            title=data[1],
#            director=data[2],
#            producer=data[3],
#            release_date=data[4]
#        )
        return(data[1] + ": OK")
    except Exception as e:
        return(data[1] + ": " + str(e))

def insert(request):
    res = []
    res.append(insert_row(('1', 'The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19')))
    res.append(insert_row(('2', 'Attack of the Clones', 'George Lucas', 'Rick McCallum',  '2002-05-16')))
    res.append(insert_row(('3', 'Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19')))
    res.append(insert_row(('4', 'A New Hope', 'George Lucas', 'Gary Kurtz, Rick McCallum',  '1977-05-25')))
    res.append(insert_row(('5', 'The Empire Strikes Back', 'Irvin Kershner', 'Gary Kutz, Rick McCallum', '1980-05-17')))
    res.append(insert_row(('6', 'Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, George Lucas, Rick McCallum', '1983-05-25')))
    res.append(insert_row(('7', 'The Force Awakens', 'J. J. Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11')))
    return render(request, 'ex05/templates/insert.html', {'res': res})

def select(request):
    try:
        res = models.Movies.objects.all().order_by('episode_nb')
    except:
        res = 0
    return render(request, 'ex05/templates/select.html', {'res': res})

def delete(request):
    if request.method == 'POST':
        if forms.delete_form(request.POST).is_valid():
            res = models.Movies.objects.get(episode_nb = request.POST['subject'])
            res.delete()
    try:
        res = models.Movies.objects.all().values_list("episode_nb", "title").order_by('episode_nb')
        if len(res) > 0:
            form = forms.delete_form()
            form.fields['subject'].choices = res
        else:
            form = 0
    except Exception:
        form = 0
    return render(request, 'ex05/templates/delete.html', {'form':form})

