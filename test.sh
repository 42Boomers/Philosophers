#!/bin/bash
make

echo -e "\nThe only one should die fast:"
./philosophers 1 800 200 200

#echo -e "\nNo one should die:"
#sleep 1
#./philosophers 5 800 200 200

#echo -e "\nNo one should die:"
#sleep 1
#./philosophers 4 410 200 200

echo -e "\nOne should die:"
./philosophers 4 310 200 100

echo -e "\nNo one should die and we stop when they all eat 7 times"
./philosophers 5 800 200 200 7
