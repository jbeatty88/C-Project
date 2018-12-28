def rabbonacci(months, offspring):
	if int(months) == 1:
		return 1;
	elif int(months) == 2:
		return int(offspring)
	one_gen = rabbonacci(int(months) - 1, offspring)
	two_gen = rabbonacci(int(months) - 2, offspring)

	if int(months) <= 4:
		return int(one_gen) + int(two_gen)
	return int(one_gen) + (int(two_gen) * int(offspring))
