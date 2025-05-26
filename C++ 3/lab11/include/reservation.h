#pragma once

#include "booking.h"

/** Dlaczego z kodem ReservationSystem jest problem?

    Ponieważ pliki booking.h oraz reservation nawzajem się includują (zawierają)
    klasa ReservationSystem dziedziczy po BookingManager, a 
    klasa BookingManager dziedziczy po ReservationSystem 
    
    załączają się rekurecyjnie bez końca i nie wiadomo która jest bazowa.

 */

#ifdef COMPILATION_ISSUE

class ReservationSystem : public BookingManager {
public:
    ReservationSystem() {
        std::cout << "ReservationSystem" << std::endl;
    }
};
#endif
