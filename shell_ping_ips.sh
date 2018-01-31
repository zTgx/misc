#!/bin/bash

#Author : beautifularea
#Date   : 1/31/2018

#echo $$
#ping -c 1 ddddwww.baidu.com
#echo $?
#if [ $? -eq 0 ]; then
#    echo 'this host not known' 
#fi

#read lines from ips.txt, then ping each ip, print cannot reach ips.

while read line
do
    #echo $line #ip
    #echo $0 "'s pid = " $$ #shell pid
    timeout 1 ping -c 1 $line > /dev/null #set timeout , and ping
    ret=$? #save ping return status to ret
    if [ $ret -ne 0 ]; then 
        echo "this ip is not known : " $line
    fi
done < $1 #read file from $1(first param)

exit 1
