FROM debian:buster

RUN		apt update && apt install ssh -y && apt install mc -y && apt install sudo -y; \
		apt install mariadb-server -y;

COPY	./conf/50-server.cnf /etc/mysql/mariadb.conf.d
COPY	./tools/docker-entrypoint.sh /usr/bin

RUN		chmod a+x /usr/bin/docker-entrypoint.sh

VOLUME	[ "/var/lib/mysql" ]

EXPOSE	22
EXPOSE	3306

ENTRYPOINT	["/usr/bin/docker-entrypoint.sh"]