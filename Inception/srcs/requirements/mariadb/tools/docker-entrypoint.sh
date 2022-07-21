#!/bin/bash

service ssh start;

service mysql start;
mysql -u root -e "DELETE FROM mysql.user WHERE User <> 'root';"
mysql -u root -e "DELETE FROM mysql.db WHERE User <> 'root';"
mysql -u root -e "DELETE FROM mysql.tables_priv WHERE User <> 'root';"
mysql -u root -e "DELETE FROM mysql.columns_priv WHERE User <> 'root';"
mysql -u root -e "FLUSH PRIVILEGES;"
mysql -u root -e "CREATE USER '$SA_USER'@'%' IDENTIFIED BY '$SA_PASS';"
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO '$SA_USER'@'%' WITH GRANT OPTION;"
mysql -u root -e "CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS';"
mysql -u root -e "GRANT ALL PRIVILEGES ON \`$WP_DB_NAME\`.* TO '$DB_USER'@'%';"
mysql -u root -e "CREATE USER '$DB_USER2'@'%' IDENTIFIED BY '$DB_PASS2';"
mysql -u root -e "GRANT EXECUTE, SELECT, SHOW VIEW ON \`$WP_DB_NAME\`.* TO '$DB_USER2'@'%';"
mysql -u root -e "FLUSH PRIVILEGES;"
service mysql stop;

useradd "$SSH_USER" && $(echo "$SSH_USER:$SSH_PASS" | chpasswd);
usermod -a -G sudo "$SSH_USER";
ln -sf /usr/share/zoneinfo/Europe/Moscow /etc/localtime;

mkdir -p /run/mysqld;
chmod a+rw /run/mysqld;

exec usr/sbin/mysqld --basedir=/usr --datadir=/var/lib/mysql --plugin-dir=/usr/lib/x86_64-linux-gnu/mariadb19/plugin --user=mysql --skip-log-error --pid-file=/run/mysqld/mysqld.pid --socket=/var/run/mysqld/mysqld.sock
