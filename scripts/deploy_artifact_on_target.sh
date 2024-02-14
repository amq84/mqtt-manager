#!/bin/bash

path=$PWD
echo $1
echo $2
cd ..
cd $1
echo $path

for FILE in *
    do 
    echo Trying to install artifacts on target $FILE
    echo Install library at $path/../$2 on target $FILE :/usr/lib
    scp -o StrictHostKeyChecking=no $path/../$2 root@$FILE:/usr/lib/
    if ((!$?))
    then
        echo Install executable $path/$3 on target $FILE :"~"
        scp -o StrictHostKeyChecking=no $path/$3 root@$FILE:~/
        if ((!$?))
        then
            echo Succesfully deployed artifacts on target
        else
            echo Unable to Install on target
            exit 
        fi
    else   
        echo Unable to Install on target
        exit 
    fi
done