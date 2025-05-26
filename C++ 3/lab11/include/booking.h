#pragma once

#include <iostream>

class ReservationSystem;

#ifdef COMPILATION_ISSUE
class BookingManager : public ReservationSystem {
public:
    BookingManager() {}
};
#endif
