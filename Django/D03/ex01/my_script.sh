#!/bin/sh

python3 -m pip --version
rm -R local_lib 2> /dev/null
mkdir -p local_lib
python3 -m pip install --target=local_lib git+https://github.com/jaraco/path.git --log install.log
if [ -d local_lib/path/ ]; then
	python3 my_program.py
fi
