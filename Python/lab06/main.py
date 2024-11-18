import numpy as np
import os
import zipfile

def operacje_na_pliku(nazwa_pliku, n):
    with open(nazwa_pliku, 'r') as plik:
        linie = plik.readlines()
        
        # n początkowych wierszy
        print('Początkowe wiersze:')
        for i in range(min(n, len(linie))):
            print(linie[i].strip())

        # n końcowych wierszy
        print('\nKońcowe wiersze:')
        for i in range(max(0, len(linie) - n), len(linie)):
            print(linie[i].strip())

        # co n-ty wiersz
        print('\nCo n-ty wiersz:')
        for i in range(0, len(linie), n):
            print(linie[i].strip())

        # n-te słowo ze wszystkich wierszy
        print('\nn-te słowo ze wszystkich wierszy:')
        for linia in linie:
            slowa = linia.split()
            if len(slowa) >= n:
                print(slowa[n-1])

        # n-ty znak ze wszystkich wierszy
        print('\nn-ty znak ze wszystkich wierszy:')
        for linia in linie:
            if len(linia) >= n:
                print(linia[n-1])

def przetworz_plik_wielokrotny():
    # Lista plików .in w bieżącym katalogu
    pliki = [plik for plik in os.listdir('.') if plik.endswith('.in')]
    
    # Przechowywanie danych (x, y) z każdego pliku
    dane = []
    
    for plik in pliki:
        with open(plik, 'r') as f:
            # Wczytanie danych do listy
            dane.append(np.loadtxt(f))
    
    # Transponowanie danych, aby uzyskać kolumny x i y w oddzielnych listach
    dane = np.array(dane)
    
    # Średnia dla x i y oraz odchylenie standardowe dla y
    srednie_x = np.average(dane[:, :, 0], axis=0)
    srednie_y = np.average(dane[:, :, 1], axis=0)
    odchylenia_y = np.std(dane[:, :, 1], axis=0)
    
    # Zapis wyników do nowego pliku
    with open('wyniki.txt', 'w') as wynik:
        for i in range(len(srednie_x)):
            wynik.write(f"{srednie_x[i]:.6f}\t{srednie_y[i]:.6f}\t{odchylenia_y[i]:.6f}\n")

def stworz_instrukcje_do_wykresu(nazwa_zip):
    # Rozpakowywanie pliku zip do katalogu 'rozpakowane_pliki'
    with zipfile.ZipFile(nazwa_zip, 'r') as zip_ref:
        zip_ref.extractall('rozpakowane_pliki')
    
    # Lista plików .in w rozpakowanym katalogu
    pliki = [plik for plik in os.listdir('rozpakowane_pliki') if plik.endswith('.in')]
    
    # Przechowywanie danych (x, y) z każdego pliku
    dane = []
    
    for plik in pliki:
        sciezka_pliku = os.path.join('rozpakowane_pliki', plik)
        with open(sciezka_pliku, 'r') as f:
            # Wczytanie danych do listy
            dane.append(np.loadtxt(f))
    
    # Transponowanie danych, aby uzyskać kolumny x i y w oddzielnych listach
    dane = np.array(dane)
    
    # Średnia dla x i y oraz odchylenie standardowe dla y
    srednie_x = np.average(dane[:, :, 0], axis=0)
    srednie_y = np.average(dane[:, :, 1], axis=0)
    odchylenia_y = np.std(dane[:, :, 1], axis=0)
    
    # Zapis wyników do nowego pliku
    with open('wyniki.txt', 'w') as wynik:
        for i in range(len(srednie_x)):
            wynik.write(f"{srednie_x[i]:.6f}\t{srednie_y[i]:.6f}\t{odchylenia_y[i]:.6f}\n")

    # Tworzenie instrukcji do wykresów
    instrukcje = '''
import matplotlib.pyplot as plt
import numpy as np

# Wczytanie danych z pliku wynikowego
srednie_x = np.loadtxt('wyniki.txt', usecols=0)
srednie_y = np.loadtxt('wyniki.txt', usecols=1)
odchylenia_y = np.loadtxt('wyniki.txt', usecols=2)

# Wykres średnich x i y
plt.figure(figsize=(10, 5))
plt.plot(srednie_x, srednie_y, label='Średnia y', color='blue', marker='o')
plt.title('Wykres średnich wartości x i y')
plt.xlabel('Średnia x')
plt.ylabel('Średnia y')
plt.grid(True)
plt.legend()
plt.savefig('wykres_srednich.png')
plt.show()

# Wykres odchylenia standardowego dla y
plt.figure(figsize=(10, 5))
plt.errorbar(srednie_x, srednie_y, yerr=odchylenia_y, fmt='o', label='Średnia y ± odchylenie', color='red')
plt.title('Wykres średnich wartości y z odchyleniem standardowym')
plt.xlabel('Średnia x')
plt.ylabel('Średnia y')
plt.grid(True)
plt.legend()
plt.savefig('wykres_odchylenia.png')
plt.show()
'''

    # Zapisanie instrukcji do pliku
    with open('instrukcje_do_wykresu.py', 'w') as instrukcje_file:
        instrukcje_file.write(instrukcje)

def przetworz_pliki_zip(nazwa_zip):
    # Rozpakowywanie pliku zip do katalogu 'rozpakowane_pliki'
    with zipfile.ZipFile(nazwa_zip, 'r') as zip_ref:
        zip_ref.extractall('rozpakowane_pliki')
    
    # Lista plików .in w rozpakowanym katalogu
    pliki = [plik for plik in os.listdir('rozpakowane_pliki') if plik.endswith('.in')]
    
    # Przechowywanie danych (x, y) z każdego pliku
    dane = []
    
    for plik in pliki:
        sciezka_pliku = os.path.join('rozpakowane_pliki', plik)
        with open(sciezka_pliku, 'r') as f:
            # Wczytanie danych do listy
            dane.append(np.loadtxt(f))
    
    # Transponowanie danych, aby uzyskać kolumny x i y w oddzielnych listach
    dane = np.array(dane)
    
    # Średnia dla x i y oraz odchylenie standardowe dla y
    srednie_x = np.average(dane[:, :, 0], axis=0)
    srednie_y = np.average(dane[:, :, 1], axis=0)
    odchylenia_y = np.std(dane[:, :, 1], axis=0)
    
    # Zapis wyników do nowego pliku
    with open('wyniki.txt', 'w') as wynik:
        for i in range(len(srednie_x)):
            wynik.write(f"{srednie_x[i]:.6f}\t{srednie_y[i]:.6f}\t{odchylenia_y[i]:.6f}\n")

if __name__ == '__main__':
    None
    # print('Task 1:')
    # operacje_na_pliku('lab06/dane.txt', 3)
    # # operacje_na_pliku('lab06/dane.txt', 5)
    # # operacje_na_pliku('lab06/dane.txt', 7)
    # # operacje_na_pliku('lab06/dane.txt', 9)

    # print('Task 2:')
    # przetworz_plik_wielokrotny()

    # print("Task 3:")
    # przetworz_pliki_zip('pliki.zip')

    # print('Task 4:')
    # stworz_instrukcje_do_wykresu('pliki.zip')
