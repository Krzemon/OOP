# Repozytorium C++ 2

## Spis Treści

- lab01 - Program dotyczy dziedziczenia wielokrotnego, gdzie klasa PlayerCharacter dziedziczy po klasach GameObject i Renderable, a także implementuje metody handleGameObject i handleRenderable w przestrzeni nazw gutils, wykorzystując RTTI oraz dynamic_cast.

- lab02 - Program identyfikuje wspólną hierarchię klas, ograniczając się do dwóch implementacji funkcji eval, uwzględniając operacje logiczne oraz polimorfizm z użyciem wskaźników lub referencji, przy czym "Logical" nie jest klasą ani strukturą.

- lab03 - Program identyfikuje wspólną hierarchię klas, ograniczając się do dwóch implementacji funkcji eval, uwzględniając argumenty operacji logicznych oraz polimorfizm z użyciem wskaźników lub referencji.

- lab04 - Program dotyczy dziedziczenia wielokrotnego, w którym należy odwzorować zależności między czterema klasami, a także przekierować operator << do wirtualnej metody, aby zapewnić odpowiednią funkcjonalność, przy czym ważne jest także dobre zarządzanie pamięcią, a plik main.cpp nie może być modyfikowany.

- lab05 - Program rozszerza podstawową, kopiowalną połączoną listę o dodatkowy typ FloatData, implementując funkcję List::find do wyszukiwania elementów oraz przeciążając operator << dla klasy List w celu umożliwienia konkatenacji list, przy zachowaniu polimorficzności poprzez przechowywanie wskaźników do klasy bazowej LData.

- lab06 - Program implementuje hierarchię czterech klas, w której Player, Enemy i NPC dziedziczą po abstrakcyjnej klasie GameObject, wykorzystując wczesne i późne wiązanie oraz obsługując atrybut complexity za pomocą klasy enumerowanej GameObject::CPLX, która ma wartości LOWEST, MID i HIGHEST, z możliwością konwersji między typem int a CPLX przy użyciu static_cast.

- lab07 - Program dotyczy wielokrotnego dziedziczenia, gdzie klasy Player i Enemy dziedziczą po klasach bazowych GameObject, Renderable, Collidable i Updatable, wykorzystując dynamic_cast do sprawdzania typów, a także implementując mechanizm przechowywania wskaźników dla obiektów dynamicznie alokowanych, z odpowiednim zarządzaniem pamięcią.

- lab08 - Program rozszerza wcześniejsze zadanie, implementując wielokrotne dziedziczenie, w którym klasa GameObject przechowuje wskaźniki do obiektów dynamicznie alokowanych, a klasy Player i Enemy dziedziczą po Renderable, Collidable i Updatable, z uwzględnieniem wirtualnego dziedziczenia dla uniknięcia problemów.

- lab09 - Program implementuje hierarchię klas opisującą składniki systemu plików, w tym klasy Dir i File, uniemożliwiając dziedziczenie po klasie Dir, z dynamicznym rozpoznawaniem typów, funkcją print dla ładnego wypisywania z odpowiednią indentacją oraz wykorzystaniem funkcji lambda, przy czym klasa Dir zarządza pamięcią dla przechowywanych obiektów i nie może używać dwóch tablic na pliki i katalogi.

- lab10 - Program rozszerza wcześniejszy projekt związany z hierarchią klas opisującą składniki systemu plików, implementując metodę listDirs, która na podstawie podanej głębokości w drzewie katalogów wypisuje katalogi, z możliwością realizacji na dwóch poziomach trudności, przy czym w obu przypadkach wykorzystuje funkcje lambda do rozszerzania listy katalogów w rekurencyjnych wywołaniach metod getDirs lub getFSElemets.

- lab11 - Program analizuje kod związany z obliczeniami asynchronicznymi, tworząc wektor gameObjects, który przechowuje wskaźniki do obiektów gry (w tym Player i Enemy), a następnie aktualizuje je asynchronicznie za pomocą std::async, wykonując jednocześnie inne akcje, takie jak ataki i otrzymywanie obrażeń, a na koniec czeka na zakończenie wszystkich aktualizacji, korzystając z metody get() na futurach.

- lab12 - Program rozszerza projekt dotyczący hierarchii klas systemu plików, implementując metodę Dir::listDirs, która korzysta z nowej metody FSElement::getRelativePath do zwracania ścieżki do najwcześniejszego elementu w drzewie katalogów, przy czym ścieżka do zasobu nie jest przechowywana jako std::string.

project 1 - Program implementuje polimorficzną, kopiowalną listę połączoną, gdzie elementy listy są przechowywane jako wskaźniki do klas pochodnych IntData i StringData, z klasą bazową definiującą interfejs do klonowania i wypisywania danych, a także z uwzględnieniem składnika wyliczeniowego List::Begin/End i szczególnych wymagań dotyczących konstruktora kopiującego.


project 2 - Program rozszerza hierarchię klas opisującą składniki systemu plików, implementując metodę listDirs, która pozwala na listowanie katalogów do określonej głębokości w drzewie katalogów oraz umożliwia kopiowanie katalogów z ich zawartością, wykorzystując metodę FSElement::getFSElemets do pobierania katalogów i plików według typu, z zachowaniem zasad D.R.Y. oraz uwzględnieniem ryzyka ewentualnych cyklicznych zależności.
