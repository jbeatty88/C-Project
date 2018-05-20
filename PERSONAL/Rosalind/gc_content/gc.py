def highest_gc_content_of(filename):
    file = open(filename)
    lines = file.readlines()
    file.close()

    first_genome = []
    first_genome.append(lines[1])
    first_genome.append(lines[2])
    fg = ''.join(first_genome)
    
    for i in range(0, int(len(fg))):
	print(fg[i])
