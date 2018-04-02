# Take in user string to be split
s = input("string(Please use quotation marks): ")

# Initialize an empty dictionary to store words and their count value
word_dict = {}
# Variable to count word occurances
count = 0

# Analyze string by words split by spaces
for word1 in s.split(' '):
        # Store all the keys in the dict
	word_dict[word1] = count
        # Iterate through the string again and compare it to itself
	for word2 in s.split():
                # If there is a repead of the word, increment the count
		if word1 == word2:
			count += 1
			word_dict[word1] = count

# Print out the contents of the dictionary
for word, count in word_dict.items():
    print word,
    print count


