// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Celem zadania jest rozszerzenie projektu nr 2, czyli:
// Hierarchia klas opisujacej skladniki systemu plikow.
// Skladnikami tymi sa miedzy innymi katalog (klasa Dir) i plik (klasa File).
// UWAGA: FSElement to klasa bazowa, zwierająca m.in metodę:
//        std::vector<FSElement*> getFSElemets(..., FSElement::Type type), gdzie:
// enum class Type{ Dir, File };
//
// ZADANIE:
//
// W tym zadaniu należy rozszerzyć metodę Dir::listDirs, w oparciu o nową metodę
// FSElement::getRelativePath która zwraca ścieżkę do najwcześniejszego elementu
// w zdefiniowanym drzewie katalogów.
// UWAGA: ścieżka do zosobu nie może być przechowywana w żadnym miejscu jako std::string.

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
  home->add( new Dir("adam") );

  Dir* ewa = home->findDir("ewa");  
  *ewa += new File("pict.jpg");
  *ewa += new Dir("Desk");
  top->findDir("ewa")->add( new Dir("work") );
  top->findDir("Desk")->add( new Dir("Docs") );
  top->findDir("Docs")->add( new Dir("priv") );

  std::cout << *top << std::endl;
  std::cout << "--------------" << std::endl;

  auto dir = top->findDir("Desk");
  std::cout << "name: " << dir->name() << std::endl;
  std::cout << "path: " << dir->getRelativePath() << std::endl;
  std::cout << "--------------" << std::endl;
  top->listDirs(4);

  delete top;
}

/*
. (DIR)
  home (DIR)
    ewa (DIR)
      pict.jpg (FILE)
      Desk (DIR)
        Docs (DIR)
          priv (DIR)
      work (DIR)
    proj.descr (FILE)
    adam (DIR)

--------------
name: Desk
path: ./home/ewa/Desk/
--------------
name: .
path: ./
name: home
path: ./home/
name: ewa
path: ./home/ewa/
name: Desk
path: ./home/ewa/Desk/
name: Docs
path: ./home/ewa/Desk/Docs/
name: work
path: ./home/ewa/work/
name: adam
path: ./home/adam/
*/