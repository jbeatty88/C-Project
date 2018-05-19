def rabbitPairs(months, offspring):
    if int(months) == 1:
        return 1
    elif int(offspring) == 2:
        return offspring

    one_gen = int(rabbitPairs(months - 1, offspring))
    two_gen = int(rebbitPairs(months - 2, offspring))

    if int(months) <= 4:
        return one_gen + two_gen

    return one_gen + (two_gen * offspring)
