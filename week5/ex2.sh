#!/bin/bash
while ! ln newfile.txt newfile.txt.lock 
do
sleep 1
done
for i in {1..10}
do
y=$(cat newfile.txt |tail -n 1)
y=$((y+1))
echo $y>>newfile.txt
done
rm newfile.txt.lock
echo "it is ready"
