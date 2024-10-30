# Repozytorium C++ 1

## Spis Treści

- lab01 - Wprowadzenie do Cmake.

- lab02 - Program Generuje ciąg geometryczny, a następnie oblicza sumę, iloczyn oraz znajduje największy element.

- lab03 - Program Tworzy ciąg geometryczny, oblicza sumę i średnią elementów, zarządza pamięcią przy użyciu new i delete, oraz obsługuje zmienną PERFORM_LONG_LOOP (kontrolowaną w CMakeLists.txt) do zmiany zakresu działania programu w zależności od jej wartości.

- lab04 - Program tworzy ciągi geometryczne, oblicza ich sumę i średnią, celowo popełniając błędy zarządzania pamięcią oraz kontrolując ich wystąpienie przez zmienne LP_1 i LP_2 w CMake.

- lab05 - Program implementuje klasę Angle, która modeluje kąt w radianach, zapewniając możliwość tworzenia kątów w przedziale od 0 do 2π oraz konwersji między radianami a stopniami, a także uniemożliwia tworzenie obiektów bez określonych jednostek.

- lab06 - Program implementuje klasę Angle, która modeluje kąt w radianach, ogranicza go do przedziału 0-2π, umożliwia konwersję między radianami a stopniami oraz wspiera "chained function calls" i oblicza różnicę między kątami.

- lab07 - Program implementuje klasy Point3D, APointCloud i VPointCloud, gdzie Point3D przechowuje współrzędne 3D w std::array, a APointCloud i VPointCloud są agregatami punktów, przy czym APointCloud używa dynamicznie alokowanej tablicy, a VPointCloud korzysta z std::vector, dodatkowo wykorzystując przyjaźń klas dla współdzielenia funkcjonalności.

- lab08 - Program refaktoryzuje i rozszerza klasy Point3D oraz VPointCloud z poprzednich zajęć, dodając nowe funkcjonalności, które są opisane w funkcji main().

- lab09 - Program implementuje klasy CplxNumber i CplxVector, gdzie CplxNumber reprezentuje liczbę zespoloną jako parę liczb, a CplxVector jest uporządkowanym zbiorem trzech takich liczb, z obsługą konwersji między typami, bez użycia static_cast<>.

- lab10 - Program implementuje klasę Car, która spełnia regułę pięciu (Rule of Five) i zarządza dynamicznymi zasobami, w tym przypadku atrybutem mileage przechowywanym jako wskaźnik, z dodatkowymi atrybutami opisanymi w funkcji main().

- lab11 - Program implementuje klasę Line do reprezentacji linii w równaniu y=a⋅x+b oraz do obliczania wartości i punktu przecięcia z osią odciętą, a także klasy LPrint do drukowania linii i LArray do dynamicznego przechowywania tablicy instancji Line.

- lab12 - Program implementuje hierarchię klas opisujących elementarne kształty z wykorzystaniem dziedziczenia, gdzie każdy kształt ma polimorficzne metody oraz niezbędną infrastrukturę.

- lab13 - Program implementuje hierarchię klas reprezentujących elementarne kształty z dziedziczeniem i polimorficznymi metodami.

- lab14 - Program implementuje abstrakcyjne klasy Obszar i Zwierze, oraz ich konkretne implementacje w postaci klas Kontynent, Kraj, Ptak i Ssak, wykorzystując wirtualne funkcje oraz oznaczenia override i final, a także definiując składnik Kraj w klasie Ptak jako miejsce życia.

- lab15 - Program implementuje abstrakcyjne klasy Obszar i Zwierze oraz konkretne klasy Kontynent, Kraj, Ptak i Ssak, wykorzystując wirtualne funkcje i destruktory, oznaczenia override i final, a klasa Ptak zawiera składnik Kraj jako miejsce życia.
