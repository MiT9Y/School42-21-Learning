FROM debian:buster

RUN		apt update && apt install ssh -y && apt install mc -y && apt install sudo -y;
RUN		apt update && apt install -y nginx openssl gettext-base;
RUN 	openssl req -newkey rsa:2048 -nodes -x509 -days 365 \
		-subj "/C=RU/ST=Moscow/L=Moscow/O=msimon/CN=msimon.42.fr" \
		-keyout etc/ssl/key.key  \
		-out etc/ssl/cert.cert && \
		chmod a+r /etc/ssl/*

COPY	./tools/docker-entrypoint.sh /usr/bin
COPY	./conf/nginx.conf /etc/nginx/sites-available/default.template

RUN		chmod a+x /usr/bin/docker-entrypoint.sh

VOLUME	[ "/var/www/" ]

EXPOSE	22
EXPOSE	80
EXPOSE	443

ENTRYPOINT	["/usr/bin/docker-entrypoint.sh"]