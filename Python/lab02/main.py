import random

def is_prime(n):
    """Sprawdza, czy liczba n jest liczbą pierwszą."""
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def create_prime_dict():
    """Tworzy słownik 50-elementowy z kluczami jako losowe liczby i wartościami isPrime."""
    prime_dict = {}
    while len(prime_dict) < 50:
        key = random.randint(0, 99)
        if key not in prime_dict:  # Sprawdzamy, czy klucz już istnieje
            prime_dict[key] = is_prime(key)
    return prime_dict

def create_index_dict(random_list):
    """Tworzy słownik z indeksami wystąpień wartości z listy."""
    index_dict = {}
    for index, value in enumerate(random_list):
        index_dict.setdefault(value, []).append(index)
    return index_dict

def create_random_dict(size):
    """Tworzy słownik o rozmiarze size z losowymi wartościami."""
    return {i: random.randint(2, 15) for i in range(1, size + 1)}

def create_even_odd_dict(random_values):
    """Tworzy dwa słowniki dla wartości parzystych i nieparzystych."""
    even_dict = {}
    odd_dict = {}
    for index, value in enumerate(random_values):
        if value % 2 == 0:
            even_dict.setdefault(value, []).append(index)
        else:
            odd_dict.setdefault(value, []).append(index)
    return even_dict, odd_dict

def process_odd_dict(odd_dict):
    """Tworzy nowy słownik na podstawie odd_dict."""
    new_dict = {}
    for key, indices in odd_dict.items():
        if any(i % 3 == 0 for i in indices):
            new_dict[key] = indices
        else:
            new_dict[key] = (max(indices), min(indices))
    return new_dict

def main():
    # 1. Tworzenie słownika liczb pierwszych
    prime_dict = create_prime_dict()
    print("Słownik liczb pierwszych:", prime_dict)

    # 2. Lista 100 losowych wartości
    random_list = [random.randint(0, 10) for _ in range(100)]
    print("Lista losowych wartości:", random_list)
    index_dict = create_index_dict(random_list)
    print("Słownik z indeksami wystąpień:", index_dict)

    # 3. Słownik losowy z zamienionymi kluczami i wartościami
    size = 10  # Rozmiar słownika
    random_dict = create_random_dict(size)
    print("Słownik losowy:", random_dict)

    tuple_list = [(value, key) for key, value in random_dict.items()]
    swapped_dict = {value: key for key, value in random_dict.items()}
    
    print("Lista krotek (wartość, klucz):", tuple_list)
    print("Słownik po zamianie kluczy z wartościami:", swapped_dict)

    # 4. Lista 100 losowych wartości z przedziału [0, 20)
    random_values = [random.randint(0, 19) for _ in range(100)]
    even_dict, odd_dict = create_even_odd_dict(random_values)
    
    print("Lista losowych wartości (0-20):", random_values)
    print("Słownik parzystych wartości:", even_dict)
    print("Słownik nieparzystych wartości:", odd_dict)

    new_dict = process_odd_dict(odd_dict)
    print("Nowy słownik z wartościami:", new_dict)

    # 5. Dwa słowniki z zamienionymi kluczami i wartościami
    dict1 = {i: random.randint(1, 100) for i in range(1, 11)}
    dict2 = {i: random.randint(1, 100) for i in range(1, 11)}

    swapped_dict1 = {value: key for key, value in dict1.items()}
    swapped_dict2 = {value: key for key, value in dict2.items()}

    common_keys_dict = {}
    for key in swapped_dict1.keys() & swapped_dict2.keys():
        common_keys_dict[key] = (swapped_dict1[key], swapped_dict2[key])

    print("Pierwszy słownik:", dict1)
    print("Drugi słownik:", dict2)
    print("Słownik ze wspólnymi kluczami i wartościami:", common_keys_dict)

if __name__ == "__main__":
    main()
