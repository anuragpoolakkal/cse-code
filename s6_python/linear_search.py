import random

def linear_search(list, num):
    count = 0
    
    for x in list:
        flag = False
        count += 1
        if x == num:
            return count

    return count

total_count = 0

for i in range(0,100):    
    random_number = random.randint(1,100)
    random_list = []
    for i in range(1,11):
        rand_num = random.randint(1,10)
        random_list.append(rand_num)
    total_count += linear_search(random_list, random_number)

print(total_count / 100)