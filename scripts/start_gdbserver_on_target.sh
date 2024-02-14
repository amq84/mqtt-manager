#!/bin/bash
cd ..
cd $1

for FILE in *
    do 
    echo Trying to start gdbserver on $FILE
    ssh  root@$FILE "gdbserver :10000 ~/./$2"
    echo $?
done

