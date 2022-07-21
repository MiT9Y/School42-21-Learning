from . import forms
from django.shortcuts import render
import psycopg2

def create(request):
    try :
        connection = psycopg2.connect(
            database = 'formationdjango',
            host='localhost',
            user='djangouser',
            password='secret',
        )
    except Exception as e:
        return render(request, 'ex06/templates/create.html', {'res': e})
    cursor = connection.cursor()
    try :
        cursor.execute("""CREATE TABLE IF NOT EXISTS ex06_movies (
        title VARCHAR(64) UNIQUE NOT NULL,
        episode_nb INT PRIMARY KEY,
        opening_crawl TEXT ,
        director VARCHAR(32) NOT NULL,
        producer VARCHAR(128) NOT NULL,
        release_date DATE NOT NULL,
        created TIMESTAMP DEFAULT NOW(),
        updated TIMESTAMP DEFAULT NOW()
        );
        """)
        connection.commit()
        cursor.execute("""DROP TRIGGER IF EXISTS update_films_changetimestamp ON ex06_movies;""")
        connection.commit()
        cursor.execute("""CREATE OR REPLACE FUNCTION update_changetimestamp_column()
        RETURNS TRIGGER AS $$
        BEGIN
        NEW.updated = now();
        NEW.created = OLD.created;
        RETURN NEW;
        END;
        $$ language 'plpgsql';
        CREATE TRIGGER update_films_changetimestamp BEFORE UPDATE
        ON ex06_movies FOR EACH ROW EXECUTE PROCEDURE
        update_changetimestamp_column();""")
        connection.commit()
    except Exception as e:
        return render(request, 'ex06/templates/create.html', {'res': e})
    connection.commit()
    connection.close()
    return render(request, 'ex06/templates/create.html', {'res': 'OK'})

def insert_row(data, connection):    
    cursor = connection.cursor()
    try:
        cursor.execute("""INSERT INTO ex06_movies(episode_nb ,title, director, producer, release_date)
            VALUES
        (""" + data[0] + ", '" + data[1] + "', '" + data[2] + "', '" +data[3] + "', '" + data[4] +"')")
        connection.commit()
        return(data[1] + ": OK")
    except Exception as e:
        connection.commit()
        return(data[1] + ": " + str(e))

def insert(request):
    try :
        connection = psycopg2.connect(
            database = 'formationdjango',
            host='localhost',
            user='djangouser',
            password='secret',
        )
    except Exception as e:
        return render(request, 'ex06/templates/insert.html', {'res': [e]})
    res = []
    res.append(insert_row(('1', 'The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19'), connection))
    res.append(insert_row(('2', 'Attack of the Clones', 'George Lucas', 'Rick McCallum',  '2002-05-16'), connection))
    res.append(insert_row(('3', 'Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19'), connection))
    res.append(insert_row(('4', 'A New Hope', 'George Lucas', 'Gary Kurtz, Rick McCallum',  '1977-05-25'), connection))
    res.append(insert_row(('5', 'The Empire Strikes Back', 'Irvin Kershner', 'Gary Kutz, Rick McCallum', '1980-05-17'), connection))
    res.append(insert_row(('6', 'Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, George Lucas, Rick McCallum', '1983-05-25'), connection))
    res.append(insert_row(('7', 'The Force Awakens', 'J. J. Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11'), connection))
    connection.close()
    return render(request, 'ex06/templates/insert.html', {'res': res})

def select(request):
    try :
        connection = psycopg2.connect(
            database = 'formationdjango',
            host='localhost',
            user='djangouser',
            password='secret',
        )
    except Exception as e:
        return render(request, 'ex06/templates/select.html', {'res': 0})
    cursor = connection.cursor()
    try:
        cursor.execute("""SELECT episode_nb ,title, opening_crawl, director, producer, release_date, created, updated FROM ex06_movies ORDER BY episode_nb""")
        res = cursor.fetchall()
    except Exception as e:
        res = 0
    connection.close()
    return render(request, 'ex06/templates/select.html', {'res': res})

def update(request):
    try :
        connection = psycopg2.connect(
            database = 'formationdjango',
            host='localhost',
            user='djangouser',
            password='secret',
        )
    except Exception as e:
        return render(request, 'ex06/templates/delete.html', {'res': 0})
    cursor = connection.cursor()
    if request.method == 'POST':
        if forms.upadte_form(request.POST).is_valid():
            cursor = connection.cursor()
            cursor.execute("UPDATE ex06_movies SET opening_crawl = '" + request.POST['comment'] + "' WHERE episode_nb = " + request.POST['subject'])
            connection.commit()
    try:
        cursor.execute("""SELECT episode_nb ,title FROM ex06_movies ORDER BY episode_nb""")
        res = cursor.fetchall()        
        if len(res) > 0:
            form = forms.upadte_form()
            form.fields['subject'].choices = res
        else:
            form = 0
    except Exception:
        form = 0
    return render(request, 'ex06/templates/update.html', {'form':form})
