#!/bin/bash

gcc -o nums numbers.c
./nums
gcc -o max calc_max.c

echo -n "" > 3_nums
while IFS= read -r line
do
./push_swap $line | wc -l >> 3_nums
done < "./test_3"
echo "
-------3-------"
./max 3_nums

echo -n "" > 5_nums
while IFS= read -r line
do
./push_swap $line | wc -l >> 5_nums
done < "./test_5"
echo "
-------5-------"
./max 5_nums

echo -n "" > 100_nums
while IFS= read -r line
do
./push_swap $line | wc -l >> 100_nums
done < "./test_100"
echo "
------100------"
./max 100_nums

echo -n "" > 500_nums
while IFS= read -r line
do
./push_swap $line | wc -l >> 500_nums
done < "./test_500"
echo "
------500------"
./max 500_nums