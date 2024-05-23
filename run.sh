#!/bin/bash

# Generate a random sequence of numbers
num_elements=499
num_runs=0
random_sequence=$(seq 0 $num_elements | sort -R | tr '\n' ' ')

# Run push_swap with the generated sequence as arguments
./a.out $random_sequence
#res=$(./a.out $random_sequence | wc -l)
#if [ "$res" -ge 1 ]; then
 # echo "ko"
 # echo "test:$random_sequence"
#fi
#if [ "$res" -ge 5500 ]; then
#  echo "ko"
#else
#  echo "ok"
#fi