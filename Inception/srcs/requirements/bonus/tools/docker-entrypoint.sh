#!/bin/bash

service ssh start;

useradd "$SSH_USER" && $(echo "$SSH_USER:$SSH_PASS" | chpasswd);
usermod -a -G sudo $SSH_USER;
ln -sf /usr/share/zoneinfo/Europe/Moscow /etc/localtime;

exec /usr/sbin/proftpd -4 -n -c /etc/proftpd/proftpd.conf;
