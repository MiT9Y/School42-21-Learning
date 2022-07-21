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
        return render(request, 'ex02/templates/create.html', {'res': e})
    cursor = connection.cursor()
    try :
        cursor.execute("""CREATE TABLE IF NOT EXISTS ex02_movies (
        title VARCHAR(64) UNIQUE NOT NULL,
        episode_nb INT PRIMARY KEY,
        opening_crawl TEXT ,
        director VARCHAR(32) NOT NULL,
        producer VARCHAR(128) NOT NULL,
        release_date DATE NOT NULL
        );
        """)
    except Exception as e:
        return render(request, 'ex02/templates/create.html', {'res': e})
    connection.commit()
    connection.close()
    return render(request, 'ex02/templates/create.html', {'res': 'OK'})

def insert_row(data, connection):    
    cursor = connection.cursor()
    try:
        cursor.execute("""INSERT INTO ex02_movies(episode_nb ,title, director, producer, release_date)
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
        return render(request, 'ex02/templates/insert.html', {'res': [e]})
    res = []
    res.append(insert_row(('1', 'The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19'), connection))
    res.append(insert_row(('2', 'Attack of the Clones', 'George Lucas', 'Rick McCallum',  '2002-05-16'), connection))
    res.append(insert_row(('3', 'Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19'), connection))
    res.append(insert_row(('4', 'A New Hope', 'George Lucas', 'Gary Kurtz, Rick McCallum',  '1977-05-25'), connection))
    res.append(insert_row(('5', 'The Empire Strikes Back', 'Irvin Kershner', 'Gary Kutz, Rick McCallum', '1980-05-17'), connection))
    res.append(insert_row(('6', 'Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, George Lucas, Rick McCallum', '1983-05-25'), connection))
    res.append(insert_row(('7', 'The Force Awakens', 'J. J. Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11'), connection))
    connection.close()
    return render(request, 'ex02/templates/insert.html', {'res': res})

def select(request):
    try :
        connection = psycopg2.connect(
            database = 'formationdjango',
            host='localhost',
            user='djangouser',
            password='secret',
        )
    except Exception as e:
        return render(request, 'ex02/templates/select.html', {'res': 0})
    cursor = connection.cursor()
    try:
        cursor.execute("""SELECT episode_nb ,title, opening_crawl, director, producer, release_date FROM ex02_movies ORDER BY episode_nb""")
        res = cursor.fetchall()
    except Exception as e:
        res = 0
    connection.close()
    return render(request, 'ex02/templates/select.html', {'res': res})
