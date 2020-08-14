import random

def get_birthdays(people):
    return [random.randint(1, 365) for i in range(people)]

def get_probability(people):
    dates = get_birthdays(people)

    match = []
    for date in dates:
        if dates.count(date) > 1 and not date in match:
            match.append(date)

    if len(match) >= 1:
        return 1
    return 0

def calculate_for_n(n):
    correct = 0
    for i in range(1000):
        correct += get_probability(n)
    return 100 * correct / 1000

for people_amount in range(366):
    print(people_amount, calculate_for_n(people_amount))

# if there are 23 people, we will have more than 50%
# if there are more than 366, we will have more than 100%

# print(calculate_for_n(366))