#!/bin/bash

service ssh start;

useradd "$SSH_USER" && $(echo "$SSH_USER:$SSH_PASS" | chpasswd);
usermod -a -G sudo "$SSH_USER";
ln -sf /usr/share/zoneinfo/Europe/Moscow /etc/localtime;

chown -R www-data:www-data /var/www/;

envsubst '${DOMAIN_NAME}' < /etc/nginx/sites-available/default.template > /etc/nginx/sites-available/default;

#service nginx start;

#exec bash
exec /usr/sbin/nginx -g "daemon off;"
