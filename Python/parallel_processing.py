import multiprocessing
import time

# Funkcja do obliczania sumy kwadratów
def sum_of_squares(start, end):
    print(f"Process {multiprocessing.current_process().name} is calculating from {start} to {end}")
    total = 0
    for i in range(start, end):
        total += i * i
    print(f"Process {multiprocessing.current_process().name} finished. Total sum of squares: {total}")
    return total

# Funkcja do uruchamiania wielu procesów
def parallel_processing():
    # Zakresy do obliczeń
    ranges = [(1, 10000), (10000, 20000), (20000, 30000), (30000, 40000)]

    # Tworzenie listy procesów
    processes = []
    results = []

    # Tworzenie i uruchamianie procesów
    for start, end in ranges:
        process = multiprocessing.Process(target=sum_of_squares, args=(start, end))
        processes.append(process)
        process.start()

    # Oczekiwanie na zakończenie wszystkich procesów
    for process in processes:
        process.join()

    # Zbieranie wyników z procesów (jeśli procesy miałyby zwracać wartości, np. przez Queue)
    # Inny sposób to użycie Pool() do zarządzania procesami i zbierania wyników.
    print("All processes completed.")

if __name__ == "__main__":
    start_time = time.time()
    parallel_processing()
    print(f"Total execution time: {time.time() - start_time} seconds")
