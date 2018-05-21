def highest_gc_content_of(filename):
    # Open input file
    file = open(filename)
    # Read in each line
    lines = file.readlines()
    # Close file
    file.close()

    # Create an empty dictionary 
    first_genome = []
    # Append the first sequence
    first_genome.append(lines[1])
    first_genome.append(lines[2])
    # Join them together
    fg = ''.join(first_genome)

    # Print each char
    for i in range(0, int(len(fg))):
	print(fg[i])

    # Take file input and sort it Key:Value

    # Take the average GC of each one

    # Output the largest avg
