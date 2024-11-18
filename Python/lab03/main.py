import random

def generate_dict(expression):
    n = random.randint(0, 20)
    result = {}
    for _ in range(n):
        key = round(random.uniform(0, 1), 3)
        value = '{:.3f}'.format(eval(expression.replace('x', str(key))))
        result[key] = value
    return result

def common_elements(*args):
    common_elements = set(args[0])
    for seq in args[1:]:
        common_elements &= set(seq)
    else:
        return list(common_elements)
    
def zip_sequences(seq1, seq2, fill_none=True):
    return [(seq1[i], seq2[i] if i < len(seq2) else None) for i in range(max(len(seq1), len(seq2)))] if fill_none else [(seq1[i], seq2[i]) for i in range(min(len(seq1), len(seq2)))]


def find_extreme(*args, find_max=False):
    return max(args) if find_max else min(args)

def apply_func_to_find(extreme_func, *args, find_max=False):
    return extreme_func(*args, find_max=find_max)

def coin_change(amount, denominations=(10, 5, 2)):
    result = {}
    for coin in denominations:
        count = amount // coin
        if count > 0:
            result[coin] = count
            amount -= count * coin
    return result

import random

def guess_number(target, low, high, method='r'):
    steps = 0
    while low <= high:
        if method == 'r':
            guess = random.randint(low, high)
        elif method == 'b':
            guess = (low + high) // 2
        else:
            raise ValueError("Invalid method. Use 'r' or 'b'.")
        
        steps += 1
        if guess == target:
            return steps
        elif guess < target:
            low = guess
        else:
            high = guess
    return steps

def main():
    print("Test 1 - generate_dict")
    print(generate_dict('x**2'))  # Wyrażenie kwadratowe

    print("Test 2 - common_elements")
    print(common_elements([1, 2, 3], [2, 3, 4], [3, 5, 6]))

    print("Test 3 - zip_sequences")
    print(zip_sequences([1, 2, 3, 4, 5], [4, 5, 6, 8]))
    print(zip_sequences([1, 2, 3, 4, 5], [4, 5, 6, 8], False))  # Dopełnianie None
    # print(zip_sequences([1, 2, 3, 4], [4, 5, 6, 8, 9])) to nie działa, bo pierwsza lista jest krótsza
    
    print("Test 4 - find_extreme")
    print(find_extreme(1, 5, 3, 7, 9))  # Najmniejsza
    print(find_extreme(1, 5, 3, 7, 9, find_max=True))  # Największa

    print("Test 5 - apply_func_to_find")
    print(apply_func_to_find(find_extreme, 1, 5, 3, 7, 9))  # Najmniejsza
    print(apply_func_to_find(find_extreme, 1, 5, 3, 7, 9, find_max=True))  # Największa

    print("Test 6 - coin_change")
    print(coin_change(28))  # Kwota 28 z nominałami 10, 5, 2

    print("Test 7 - guess_number")
    print(guess_number(202, 1, 5000))  # Przeszukiwanie przedziału 1-100 z losowaniem
    print(guess_number(202, 1, 5000, method='b'))  # Przeszukiwanie przedziału 1-100 metodą dzielenia na pół

if __name__ == '__main__':
    main()