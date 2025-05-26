// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywał się,
// a wynik jego dzialania był taki sam jak podany na końcu tego pliku.
// Celem zadania jest zaimplementowanie uproszczonego systemu hotelowego.
// Zdefiniowanie odpowiednich klas, w tym klasy czysto wirtualnej IUser, która reprezentuje użytkownika systemu.
// Zbudowanie hierarchii dziedziczenia, w której Guest (gość hotelowy) i Staff (pracownik) dziedziczą z IUser,
// a HotelMember dziedziczy po obu (tj. po Guest oraz Staff), wg schematu:
//     IUser
//     /     \
// Guest    Staff
//     \     /
// HotelMember

// Klasa HotelMember powinna umożliwiać zarówno rezerwację pokoju (makeReservation),
// jak i jego obsługę (manageReservation), w zależności od roli użytkownika.
// Przechowywanie nazwy (np. Jan Kowalski) ma zawierać się w klasie IUser.
//
// Prosze zadbać o dobre zarzadzanie pamiecia.
// Plik Main.cpp w przesłanym rozwiązaniu powinien być niezmodyfikowany.
// Struktura propramu powinna być oparta o definicję zawartą w pliku CMakeLists.txt
//
// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materiałów.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i Main.cpp
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab10/
// * archiwum nie powinno zawierać katalogu build/


#include "HotelMember.h"

int main() {
    HotelMember guest("Jan Nowak", Type::GUEST);
    guest.printRole();
    guest.performRoleAction();
    std::cout << guest.getName() << std::endl;


    HotelMember staff("Jan Kowal", Type::STAFF);
    staff.printRole();
    staff.performRoleAction();
    std::cout << staff.getName() << std::endl;
   

    return 0;
}
/* wynik działania programu
[Info]: Jan Nowak (role: Guest)
[Info]: Jan Nowak is making reservation for: Room 401
Jan Nowak
[Info]: Jan Kowal (role: Staff)
[Info]: Jan Kowal is managing reservations.
Jan Kowal
*/
