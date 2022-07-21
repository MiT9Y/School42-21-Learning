from django.urls import path

from . import views

urlpatterns = [
    path('init/', views.create, name='create'),
    path('populate/', views.insert, name='insert'),
    path('display/', views.select, name='select'),
    path('remove/', views.delete, name='delete'),
]