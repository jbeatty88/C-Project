dna = input('DNA Sequence: ')

dna_reverse = list(reversed(dna))

for i in range(0, len(dna_reverse)):
	if dna_reverse[i] == 'T':
		dna_reverse[i] = 'A'
	elif dna_reverse[i] == 'A':
		dna_reverse[i] = 'T'
	elif dna_reverse[i] == 'G':
		dna_reverse[i] = 'C'
	elif dna_reverse[i] == 'C':
		dna_reverse[i] = 'G'

dna_reverse_complement = ''.join(dna_reverse)

print(dna_reverse_complement)
