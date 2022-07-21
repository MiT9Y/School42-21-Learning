from django.urls import path, re_path

from . import views

urlpatterns = [
    re_path(r'^django/', views.django),
    re_path(r'^display/', views.display),
    re_path(r'^templates/', views.templates),
]