sequence = input('Sequence: ')

adenine_count = 0
cytosine_count = 0
guanine_count = 0
thymine_count = 0

for nucleobase in sequence:
    if nucleobase == 'A':
	    adenine_count += 1
    elif nucleobase == 'C':
	    cytosine_count += 1
    elif nucleobase == 'G':
	    guanine_count += 1
    elif nucleobase == 'T':
	    thymine_count += 1
    else:
	    print('There are only for choices for a nucleobase')


print adenine_count,
print cytosine_count,
print guanine_count,
print thymine_count
        
