// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Celem zadania jest rozszerzenie wcześniejszego projektu realizowanego w parach:
// Hierarchia klas opisujacej skladniki systemu plikow.
// Skladnikami tymi sa miedzy innymi katalog (klasa Dir) i plik (klasa File). 
// W tym zadaniu należy zaimplementowac metodę listDirs, której argumentem jest głębokość
// w drzewie katalogu, do której chcemy listować katalogi.
// Zadanie można zrealizować na dwóch poziomach trudności:
// 1) Max 8 pkt.
// - listDirs korzysta z metody Dir::getDirs, która zwraca liste katalogow do danego poziomiu
// 2) Max 10 pkt.
// - listDirs korzysta z metody FSElement::getFSElemets, które zwraca również liste katalogow i plikow do danego poziomu, 
//   ale która przyjmuje również określenie typu, np. Type::Dir, Type::File
//
// UWAGA: w obu przypadach należy wykorzystać lambdę, np. do rozszerzania listy katalogów,
//        przy rekurencyjnym wywołaniu metody getDirs, lub getFSElemets
//
// Prosze zadbac o dobre zarzadzanie pamiecia.
// Pliku main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab10/
// * archiwum nie powinno zawierać katalogu build/


#include "Dir.h"
#include "File.h"

int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home; // dodajemy do kat TOP podkatalog
  *home += new Dir("ewa");
  *home += new File("proj.descr");
  home->add(new File("proj.files.repo") );
  home->add(new Dir("adam") );
  
  top->findDir("ewa")->add( new Dir("Desk") );

  Dir* ewa = home->findDir("ewa");  
  *ewa += new File("pict.jpg");
  top->findDir("ewa")->add( new Dir("work") );

  std::cout << *top << std::endl;


  std::cout << "--------------" << std::endl;
  top->listDirs(1);
  std::cout << "--------------" << std::endl;
  top->listDirs(2);

  // delete top;
}

/*
. (DIR)
  home (DIR)
    ewa (DIR)
      Desk (DIR)
      pict.jpg (FILE)
      work (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)

--------------
. home 
--------------
. home ewa adam
*/