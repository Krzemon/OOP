#pragma once
#include "logger.h"
#include "log.h"

class RoomAssignment {
public: 
    /**
     * @brief loguje pokój
     */
    RoomAssignment() {
        Logger::get_logger().log("RoomAssignment");
    }
};
class GuestInfo {
public: 
    /**
     * @brief loguje gościa
     */
    GuestInfo() {
        Logger::get_logger().log("GuestInfo");
    }
};

class ClientRecord {
private:
    RoomAssignment* room;
    GuestInfo* guest;
public:
    /**
     * @brief loguje klienta
     */
    ClientRecord() {
        this->guest = new GuestInfo();
        this->room = new RoomAssignment();
        Logger::get_logger().log("ClientRecord");
    }

};
