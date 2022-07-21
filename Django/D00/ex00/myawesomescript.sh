#! /bin/sh

if [ "$#" -eq  "0" ]
    then
    echo "Use an argument."
else
	curl -s $* | grep -Eo '(http|https)://[^"]+'
fi