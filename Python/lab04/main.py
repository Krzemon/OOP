import time
import sys
import random
import numpy as np

# Liczba powtórzeń i liczba elementów do testu
powt = 1
N = 10000

# Funkcje do testowania różnych metod budowania zestawów
def forStatement():
    result = []
    for i in range(N):
        result.append(i)
    return result

def listComprehension():
    return [i for i in range(N)]

def mapFunction():
    return list(map(lambda x: x, range(N)))

def generatorExpression():
    return list(i for i in range(N))

def numpyArray():
    return np.arange(N)

# Funkcja do testowania wydajności
def tester(testFunction):
    start_time = time.time_ns()
    for _ in range(powt):
        testFunction()
    end_time = time.time_ns()
    return (end_time - start_time) / powt

# Funkcja do generowania losowych liczb i obliczeń
def generate_and_process_lists():
    list1 = [random.randint(0, 19) for _ in range(100)]
    list2 = [random.randint(0, 19) for _ in range(100)]

    # Tworzymy listę krotek, spełniających warunek
    result = [(a, b) for a, b in zip(list1, list2) if 3 < a + b < 15]
    
    # Można też użyć filter i zip, aby uzyskać te same wyniki
    result_filter_zip = list(filter(lambda x: 3 < sum(x) < 15, zip(list1, list2)))

    return result, result_filter_zip

def fit_line_with_uncertainty(x_vals, y_vals):
    # Obliczanie sum potrzebnych do wzorów
    n = len(x_vals)
    
    sum_x = sum(x_vals)
    sum_y = sum(y_vals)
    sum_x_squared = sum(x**2 for x in x_vals)
    sum_xy = sum(x * y for x, y in zip(x_vals, y_vals))
    
    # Współczynnik nachylenia (a)
    a = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x**2)
    
    # Współczynnik wyrazu wolnego (b)
    b = (sum_y - a * sum_x) / n
    
    # Obliczanie błędów (niepewności)
    residuals = [y - (a * x + b) for x, y in zip(x_vals, y_vals)]
    sum_squared_residuals = sum(residual**2 for residual in residuals)
    mean_x = sum_x / n
    sum_x_diff_squared = sum((x - mean_x)**2 for x in x_vals)
    
    # Niepewność współczynnika nachylenia
    sigma_a = np.sqrt((1 / (n - 2)) * (sum_squared_residuals / sum_x_diff_squared))
    
    # Niepewność wyrazu wolnego
    sigma_b = sigma_a * np.sqrt(sum_x_squared / (n * sum_x_diff_squared))
    
    return a, b, sigma_a, sigma_b

def myreduce(func, seq):
    result = seq[0]
    for item in seq[1:]:
        result = func(result, item)
    return result

if __name__ == "__main__":
    print("Task 1")
    # Pomiar czasu dla różnych metod
    print(sys.version)

    # Lista testowych funkcji
    test = [forStatement, listComprehension, mapFunction, generatorExpression, numpyArray]
    for testFunction in test:
        print(testFunction.__name__.ljust(20), '=>', tester(testFunction))

    print("Task 2")
    result, result_filter_zip = generate_and_process_lists()

    # Wypisujemy przykłady wyników
    print(f"Przykład wyników z listy składanej: {result[:5]}")
    print(f"Przykład wyników z filter + zip: {result_filter_zip[:5]}")

    print("Task 3")
    # Przykładowe dane
    x_vals = [1, 2, 3, 4, 5]
    y_vals = [2, 4, 5, 4, 5]

    # Wywołanie funkcji
    a, b, sigma_a, sigma_b = fit_line_with_uncertainty(x_vals, y_vals)

    print(f"Współczynnik nachylenia a: {a}")
    print(f"Współczynnik wyrazu wolnego b: {b}")
    print(f"Niepewność współczynnika nachylenia σ_a: {sigma_a}")
    print(f"Niepewność wyrazu wolnego σ_b: {sigma_b}")

    print("Task 4")
    # Test z dodawaniem
    add_result = myreduce(lambda x, y: x + y, [1, 2, 3, 4, 5])
    print(f"Sumowanie: {add_result}")

    # Test z mnożeniem
    mul_result = myreduce(lambda x, y: x * y, [1, 2, 3, 4, 5])
    print(f"Mnożenie: {mul_result}")

    print("Task 5")
    # Przykładowa lista dwuelementowych punktów
    punkty = [[1, 2], [3, 4], [5, 6], [7, 8]]

    # Używamy myreduce i lambda do utworzenia list x-ów i y-ów
    x, y = myreduce(
        lambda acc, point: (acc[0] + [point[0]], acc[1] + [point[1]]),
        [([], [])] + punkty
    )

    print("x =", x)
    print("y =", y)