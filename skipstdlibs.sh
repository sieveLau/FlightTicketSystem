#!/usr/bin/sh
# configure gdb to skip standard libraries

find /usr/include/c++ -type f > temp.txt
sed -i 's/^/skip file /' temp.txt
cat temp.txt >> ~/.gdbinit
