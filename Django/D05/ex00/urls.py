from django.urls import path

from . import views

urlpatterns = [
    path('init/', views.create_sql, name='create_sql'),
]