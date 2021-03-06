"""d07 URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from ex import views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('articles/', views.Articles.as_view(), name='articles'),
    path('', views.Home.as_view(), name='home'),
    path('init_data/', views.Init.as_view(), name='init'),
    path('login/', views.Login.as_view(), name='login'),
    path('logout/', views.Logout.as_view(), name='logout'),
    path('article/<int:pk>/', views.Detail.as_view(), name='detail'),
    path('publications/', views.Publications.as_view(), name='publications'),
    path('favourites/', views.Favourites.as_view(), name='favourites'),
    path('register/', views.Register.as_view(), name='register'),
    path('publish/', views.Publish.as_view(), name='publish'),
]
