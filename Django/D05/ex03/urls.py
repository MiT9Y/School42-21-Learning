from django.urls import path

from . import views

urlpatterns = [
    path('populate/', views.insert, name='insert'),
    path('display/', views.select, name='select'),
]