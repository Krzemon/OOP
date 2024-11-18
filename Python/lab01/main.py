# 1. Zmienne i typy danych
liczba = 10              # zmienna typu int
pi = 3.14                # zmienna typu float
imie = "Jan"             # zmienna typu string
czy_jest_dorosly = True  # zmienna typu bool

# 2. Operacje matematyczne
suma = liczba + pi        # dodawanie
roznica = liczba - pi     # odejmowanie
iloczyn = liczba * pi     # mnożenie
iloraz = liczba / pi      # dzielenie
reszta = liczba % 3       # reszta z dzielenia
potega = liczba ** 2      # potęgowanie

# 3. Struktury warunkowe: if, elif, else
if liczba > 5:
    print("Liczba jest większa od 5")
elif liczba == 5:
    print("Liczba jest równa 5")
else:
    print("Liczba jest mniejsza od 5")

# 4. Pętle: for i while
for i in range(5):
    print(f"Pętla for: {i}")  # range(5) generuje liczby od 0 do 4

liczba_while = 0
while liczba_while < 3:
    print(f"Pętla while: {liczba_while}")
    liczba_while += 1  # inkrementacja zmiennej

# 5. Funkcje
def dodaj(a, b):
    return a + b

wynik = dodaj(3, 5)
print(f"Wynik dodawania: {wynik}")

# 6. Listy
# Tworzenie listy
moje_lista = [1, 2, 3, 4, 5]

# Dodawanie elementu do listy
moje_lista.append(6)

# Odczytanie elementu z listy (indeksowanie zaczyna się od 0)
pierwszy_element = moje_lista[0]
print(f"Pierwszy element listy: {pierwszy_element}")

# 7. Słowniki
# Tworzenie słownika (para klucz: wartość)
moj_slownik = {"imie": "Jan", "wiek": 30}

# Odczytanie wartości po kluczu
wiek = moj_slownik["wiek"]
print(f"Wiek: {wiek}")

# 8. Obsługa wyjątków (try/except)
try:
    wynik = 10 / 0
except ZeroDivisionError:
    print("Nie można dzielić przez zero!")

# 9. Operacje na stringach
tekst = "Hello, World!"

# Slicing - wycinanie fragmentu tekstu
substring = tekst[0:5]  # 'Hello'

# Zmiana na wielkie litery
tekst_upper = tekst.upper()

print(f"Tekst: {tekst}, Substring: {substring}, Uppercase: {tekst_upper}")

# 10. Podstawy pracy z plikami
# Zapisz dane do pliku
with open("dane.txt", "w") as plik:
    for i in range(1, 11):  # przykładowe dane: 10 punktów
        x = i
        y = x ** 2  # przykładowa funkcja y = x^2
        plik.write(f"{i}\t{x}\t{y}\n")


import matplotlib.pyplot as plt

# Wczytaj dane z pliku
numery_linii = []
x_values = []
y_values = []

with open("dane.txt", "r") as plik:
    for linia in plik:
        dane = linia.split("\t")  # rozdziel dane po tabulatorze
        numery_linii.append(int(dane[0]))  # numer linii
        x_values.append(float(dane[1]))  # wartość x
        y_values.append(float(dane[2]))  # wartość y

# Rysowanie wykresu
plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label='y = x^2')

# Dodanie tytułu i etykiet
plt.title('Wykres funkcji y = x^2')
plt.xlabel('x')
plt.ylabel('y')

# Pokaż legendę
plt.legend()

# Wyświetlenie wykresu
plt.grid(True)
plt.show()

