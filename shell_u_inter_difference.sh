#!/bin/bash
#并， 交， 差

first=$1
second=$2

echo "***************** union ******************"
sort -m <(sort $first | uniq) <(sort $second | uniq) | uniq
echo 

echo "****************** intersaction ****************"
sort -m <(sort $first | uniq) <(sort $second | uniq) | uniq -u
echo

echo "****************** difference ******************"
echo
sort -m <(sort $first | uniq) <(sort $second | uniq) | uniq -d
echo 

#echo to file 
# > result.txt
