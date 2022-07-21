from django.shortcuts import render
import psycopg2

def create_sql(request):
    try :
        connection = psycopg2.connect(
            database = 'formationdjango',
            host='localhost',
            user='djangouser',
            password='secret',
        )
    except Exception as e:
        return render(request, 'ex00/templates/index.html', {'res': e})
    cursor = connection.cursor()
    try :
        cursor.execute("""CREATE TABLE IF NOT EXISTS ex00_movies (
        title VARCHAR(64) UNIQUE NOT NULL,
        episode_nb INT PRIMARY KEY,
        opening_crawl TEXT ,
        director VARCHAR(32) NOT NULL,
        producer VARCHAR(128) NOT NULL,
        release_date DATE NOT NULL
        );
        """)
    except Exception as e:
        connection.close()
        return render(request, 'ex00/templates/index.html', {'res': e})
    connection.commit()
    connection.close()
    return render(request, 'ex00/templates/index.html', {'res': 'OK'})