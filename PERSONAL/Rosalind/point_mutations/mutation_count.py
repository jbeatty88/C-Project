import numpy as np
import sys

input_file = sys.argv[1]
seq_arr = np.array([])

with open(input_file, 'r') as dna_seq:
    sequences = dna_seq.readlines()
    
for line in sequences:
    seq_arr = np.append(seq_arr, line)

print(seq_arr[1:] = seq_arr[:-1])

