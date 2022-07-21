from django.db import models

class Tips(models.Model):
    id = models.AutoField(primary_key=True)
    contentue = models.TextField()
    auteur = models.CharField(max_length=64)
    date = models.DateTimeField(auto_now=True)
    up = models.IntegerField(default=0)
    down = models.IntegerField(default=0)


class Voices(models.Model):
    id_trip = models.IntegerField(default=0)
    auteur = models.CharField(max_length=64)
    voice = models.IntegerField(default=0)