/*
Kreatywnie rozwiąż problemy zawarte w załączonym kodzie źródłowym,
oraz implementując brakujące typy i funkcjonalności.
Uzasadnij wszystko w komentarzach!
Wszystko ma być zgodne z OOP

WYMAGANIA: 
NIE MOŻNA MODYFIKOWAĆ ZAŁĄCZONEGO KODU ŹRÓDŁOWEGO!
Poza możliwością dodawania odpowiednich komentarzy.

Prosze zadbać o dobre zarzadzanie pamiecia.
Plik Main.cpp w przesłanym rozwiązaniu powinien być niezmodyfikowany.
Struktura propramu powinna być oparta o definicję zawartą w pliku CMakeLists.txt

Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself

Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
ani żadnych innych materiałó

Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i Main.cpp
należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
* archiwum powinno zawierać katalog z zadaniem, np. lab11/
* archiwum nie powinno zawierać katalogu build/

*/

#include "reservation.h"
#include "logger.h"
#include "record.h"
#include <ctime>

int main() {

    std::time_t result = std::time(nullptr);
    std::string date_time = std::asctime(std::localtime(&result));
    date_time.pop_back(); //  Usuń znak nowej linii na końcu
    std::cout << date_time << std::endl;

    auto& logger1 = Logger::get_logger();
    logger1.log("logger 1");
    Logger::get_logger().log("logger 2");

    Log::Advanced("adv_logger");

    ClientRecord record; // głośne konstruktory

    // Dlaczego z kodem ReservationSystem jest problem?
    #ifdef COMPILATION_ISSUE
        ReservationSystem system;
    #endif
}

/*
Oczekiwany wynik działania programu (oczywiście bez uwzględniania dokładnej wartości daty i czasu):
Mon May 19 13:48:06 2025
Mon May 19 13:48:06 2025 [Logger] 0x560880fc2018 logger 1
Mon May 19 13:48:06 2025 [Logger] 0x560880fc2018 logger 2
Mon May 19 13:48:06 2025 [AdvLogger] 0x560880fc2018 adv_logger
Mon May 19 13:48:06 2025 [Logger] 0x560880fc2018 GuestInfo
Mon May 19 13:48:06 2025 [Logger] 0x560880fc2018 RoomAssignment
Mon May 19 13:48:06 2025 [Logger] 0x560880fc2018 ClientRecord
*/
