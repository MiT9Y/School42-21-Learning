FROM debian:buster

RUN		apt update && apt install ssh -y && apt install mc -y && apt install sudo proftpd -y;

COPY	./tools/docker-entrypoint.sh /usr/bin
COPY	./conf/proftpd.conf /etc/proftpd

RUN		chmod a+x /usr/bin/docker-entrypoint.sh

VOLUME	[ "/ftp" ]

EXPOSE	20-21
EXPOSE	22
EXPOSE	30000-30010

ENTRYPOINT	["/usr/bin/docker-entrypoint.sh"]