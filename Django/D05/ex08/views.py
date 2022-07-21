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
        return render(request, 'ex08/templates/create.html', {'res': e})
    cursor = connection.cursor()
    try :
        cursor.execute("""CREATE TABLE IF NOT EXISTS ex08_planets (
        id serial PRIMARY KEY,
        name VARCHAR(64) UNIQUE NOT NULL,
        climate TEXT,
        diameter INT,
        orbital_period INT,
        population BIGINT,
        rotation_period INT,
        surface_water REAL,
        terrain VARCHAR(128) );""")
        connection.commit()

        cursor.execute("""CREATE TABLE IF NOT EXISTS ex08_people (
        id serial PRIMARY KEY,
        name VARCHAR(64) UNIQUE NOT NULL,
        birth_year VARCHAR(32),
        gender VARCHAR(32),
        eye_color VARCHAR(32),
        hair_color VARCHAR(32),
        height INT,
        mass REAL,
        homeworld VARCHAR(64) REFERENCES ex08_planets (name));""")
        connection.commit()
    except Exception as e:
        connection.close()
        return render(request, 'ex08/templates/create.html', {'res': e})
    connection.close()
    return render(request, 'ex08/templates/create.html', {'res': 'OK'})

def insert(request):
    try :
        connection = psycopg2.connect(
            database = 'formationdjango',
            host='localhost',
            user='djangouser',
            password='secret',
        )
    except Exception as e:
        return render(request, 'ex08/templates/insert.html', {'res': None, 'all_err': e})
    res = []
    cursor = connection.cursor()
    try:
        f_planets = open('ex08/planets.csv', 'r')
        cursor.copy_from(f_planets, 'ex08_planets', sep='\t', null='NULL', columns=(
            'name', 'climate', 'diameter', 'orbital_period', 'population', 'rotation_period', 'surface_water', 'terrain'
        ))
        res.append("Copy planets: OK")
        f_planets.close()
    except Exception as e:
        f_planets.close()
        res.append("Copy planets: " + str(e))
    connection.commit()

    try:
        f_people = open('ex08/people.csv', 'r')
        cursor.copy_from(f_people, 'ex08_people', sep='\t', null='NULL', columns=(
            'name', 'birth_year', 'gender', 'eye_color', 'hair_color', 'height', 'mass', 'homeworld'
        ))
        res.append("Copy people: OK")
        f_people.close()
    except Exception as e:
        f_people.close()
        res.append("Copy people: " + str(e))

    connection.commit()
    connection.close()
    return render(request, 'ex08/templates/insert.html', {'res': res, 'all_err': None})

def select(request):
    try :
        connection = psycopg2.connect(
            database = 'formationdjango',
            host='localhost',
            user='djangouser',
            password='secret',
        )
    except:
        return render(request, 'ex08/templates/select.html', {'res': 0})
    cursor = connection.cursor()
    try:
        cursor.execute("""
            SELECT t2.name, t1.name, t1.climate
            FROM ex08_planets t1 right join ex08_people t2 on t1.name = t2.homeworld
            order by t2.name        
/*            SELECT t2.name, t1.name, t1.climate
            FROM ex08_planets t1, ex08_people t2
            where t1.name = t2.homeworld and climate like '%windy%'
            order by t2.name*/
        """)
        res = cursor.fetchall()
    except Exception as e:
        res = 0
    connection.close()
    return render(request, 'ex08/templates/select.html', {'res': res})