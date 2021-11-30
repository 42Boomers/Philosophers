#!/bin/bash
make -C philo

echo -e "\nThe only one should die fast:"
./philo/philosophers 1 800 200 200

#echo -e "\nNo one should die:"
#sleep 1
#./philo/philosophers 5 800 200 200

#echo -e "\nNo one should die:"
#sleep 1
#./philo/philosophers 4 410 200 200

echo -e "\nOne should die:"
./philo/philosophers 4 310 200 100

echo -e "\nNo one should die and we stop when they all eat 7 times"
./philo/philosophers 5 800 200 200 7
