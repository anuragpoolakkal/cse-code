import random

def linear_search (list, key, size):
    for i in range (0, size):
        if (list[i] == key):
            return i + 1
    return size + 1

def generate_random_list (size):
    list = []
    for i in range (size):
        list.append(random.randrange(size))
    return list

def analyse (count):
    total_comparisons = 0
    for i in range (0, count):
        random_list = generate_random_list(count)
        random_element = random.randrange(count)
        comparisons = linear_search (random_list, random_element, count)
        total_comparisons += comparisons
    print("Analysis", total_comparisons/count)

analyse (1000)