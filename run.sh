#!/bin/bash

# Generate a random sequence of numbers
num_elements=49
num_runs=0
random_sequence=$(seq 0 $num_elements | sort -R | tr '\n' ' ')

# Run push_swap with the generated sequence as arguments
./a.out $random_sequence
