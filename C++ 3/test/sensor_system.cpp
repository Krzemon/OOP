#include <iostream>
#include <string>
#include <vector>
#include <memory>

//
// INTERFEJSY (abstrakcyjne klasy bazowe)
//

class ISensor {
public:
    virtual double readValue() const = 0;
    virtual std::string sensorType() const = 0;
    virtual ~ISensor() = default;
};

class IDevice {
public:
    virtual void activate() = 0;
    virtual std::string deviceName() const = 0;
    virtual ~IDevice() = default;
};

//
// PRZYKŁADOWE IMPLEMENTACJE
//

class TemperatureSensor : public virtual ISensor {
public:
    double readValue() const override {
        return 21.5; // symulowana temperatura
    }
    std::string sensorType() const override {
        return "TemperatureSensor";
    }
};

class AlarmDevice : public virtual IDevice {
public:
    void activate() override {
        std::cout << "ALARM! AlarmDevice activated!" << std::endl;
    }

    std::string deviceName() const override {
        return "AlarmDevice";
    }
};

//
// WIELOKROTNE I WIRTUALNE DZIEDZICZENIE
//

class SensorDevice : public virtual ISensor, public virtual IDevice {
public:
    void reportStatus() {
        std::cout << "Status from " << deviceName()
                  << " [" << sensorType() << "]: " << readValue() << std::endl;
    }
};

//
// KONKRETNA IMPLEMENTACJA
//

class SmartAlarm : public SensorDevice, public TemperatureSensor, public AlarmDevice {
public:
    void checkAndActivate() {
        if (readValue() > 25.0) {
            activate();
        } else {
            std::cout << "Temperature OK: " << readValue() << "°C" << std::endl;
        }
    }

    // Nadpisujemy by jasno określić, której wersji używać
    std::string sensorType() const override {
        // return TemperatureSensor::sensorType();
        return sensorType();
    }

    std::string deviceName() const override {
        // return AlarmDevice::deviceName();
        return deviceName();
    }
};

//
// PROGRAM GŁÓWNY
//

int main() {
    SmartAlarm alarm;
    alarm.reportStatus();       // pokazuje dane czujnika i urządzenia
    alarm.checkAndActivate();   // aktywuje alarm tylko jeśli temperatura > 25

    // Przykład polimorfizmu
    ISensor* s = &alarm;
    std::cout << "Sensor value: " << s->readValue() << std::endl;

    IDevice* d = &alarm;
    d->activate();
}
