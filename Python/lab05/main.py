import random

def natural_numbers():
    """Generator zwracający kolejne liczby naturalne."""
    i = 1
    while True:
        yield i
        i += 1

def perfect_numbers(sequence):
    """
    Generator zwracający liczby doskonałe z podanej sekwencji.
    Liczba doskonała to liczba naturalna będąca sumą swoich dzielników właściwych.
    """
    def is_perfect(n):
        """Sprawdza, czy liczba n jest doskonała."""
        if n < 2:
            return False
        divisors = [i for i in range(1, n) if n % i == 0]
        return sum(divisors) == n

    for number in sequence:
        if is_perfect(number):
            yield number

def limited_values(sequence, limit):
    """
    Generator zwracający wartości z podanej sekwencji.
    Działanie kończy się, gdy napotkana wartość przekracza limit.
    """
    for value in sequence:
        if value > limit:
            break
        yield value

def u_i_generator(a):
    """
    Oblicza wartość u_i na podstawie poprzednich wartości.
    zwraca wartość x_i, u_i oraz ln(x_i).
    """
    import math
    i = 0
    x_0 = 1
    u_0 = 0
    x_m1 = x_0
    u_im1 = u_0
    if i == 0:
        yield x_0, u_0, math.log(x_0)
        i = 1
    while True:
        x_i = x_0 + i * a
        u_i = u_im1 + a / x_m1
        if x_i > 1.5:
            break
        yield x_i, u_i, math.log(x_i)
        i += 1
        x_m1 = x_i
        u_im1 = u_i

def sum_partitions(n):
    """Generator zwracający wszystkie możliwe sumy składników, które sumują się do n."""
    stack = [(n, 1, [])]
    
    while stack:
        target, start, current = stack.pop()
        
        if target == 0:
            if len(current) > 1 or current[0] != n:
                yield current
        else:
            for i in range(start, target+1):
                stack.append((target - i, i, current + [i]))

def number_generator():
    current_value = random.uniform(0.5, 10)
    yield current_value
    
    while True:
        change = random.choice([-1, 1]) * random.uniform(0.4, 1)
        next_value = current_value + change
        
        if next_value < 0.1:
            break
        
        yield next_value
        current_value = next_value

def frange(start, stop=None, step=1):
    """Generator działający podobnie do range, ale dla liczb zmiennoprzecinkowych."""
    temp = 1
    if step == 0:
       raise ValueError("step cannot be zero")
    if start == stop:
        return list(start)
    if stop is None:
        stop = start
        start = 0
        temp = -1 # domyslnie dekrementujemy
    elif stop < start and step > 0 or stop > start and step < 0:
        return []

    epsilon = 1e-10
    current = start

    if start < stop:
        while current < stop:
            yield current
            current += step
    elif start > stop:
        while current > stop:
            yield current
            current += step*temp


if __name__ == '__main__':
    print("Task 1")
    # 1. Kolejne liczby naturalne
    gen_natural = natural_numbers()
    print(next(gen_natural))  # 1
    print(next(gen_natural))  # 2

    # 2. Liczby doskonałe z sekwencji
    sequence = range(1, 30)
    gen_perfect = perfect_numbers(sequence)
    print(list(gen_perfect))  # [6, 28]

    # 3. Sekwencja przerywana limitem
    sequence = [1, 2, 3, 10, 5, 6]
    gen_limited = limited_values(sequence, 4)
    print(list(gen_limited))  # [1, 2, 3]

    print("Task 2")
    # sequence_2 = range(1, 10000)
    # gen_perfect_10000 = perfect_numbers(sequence_2)
    # print(list(gen_perfect_10000))  # [6, 28, 496, 8128]

    print("Task 3")
    for x_i, u_i, log_x in u_i_generator(0.05):
        print(f"x_i = {x_i:<10.7f}| u_i = {u_i:<10.7f}| log_x = {log_x:<10.7f}")

    print("Task 4")
    # Przykład użycia
    n = 4
    for partition in sum_partitions(n):
        print(partition)

    print("Task 5")
    gen = number_generator()

    for value in gen:
        print(value)

    print("Task 6")
    print(list(frange(8)))               # range(8)
    print(list(frange(-8)))              # range(-8)
    print(list(frange(1, 8)))            # range(1, 8)
    print(list(frange(8, 1)))            # range(8, 1)
    print(list(frange(1, 8, 2)))         # range(1, 8, 2)
    print(list(frange(1, 8, -2)))        # range(1, 8, -2)
    print(list(frange(8, 1, 2)))         # range(8, 1, 2)
    print(list(frange(8, 1, -2)))        # range(8, 1, -2)