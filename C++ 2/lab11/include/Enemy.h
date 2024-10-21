#pragma once
#include "GameObject.h"
#include <iostream>
#include <future>
#include <chrono>
#include <thread>

// Derived class representing an enemy
class Enemy : public GameObject {
    private:
        int m_health;
        int heavyOperation(){
            // Simulate heavy number operation
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return 84; // Dummy result
        }

    public:
        Enemy() : m_health(50) {}
        virtual void update() override {
            std::cout << "Enemy update started..." << std::endl;
            // Perform heavy number operation asynchronously
            std::future<int> result_future = std::async(std::launch::async, &Enemy::heavyOperation, this);
            // Simulate other work while waiting for heavy operation
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Enemy update in progress..." << std::endl;
            // Wait for heavy operation to finish and get the result
            int result = result_future.get();
            std::cout << "Enemy update finished! Result: " << result << ", Health: " << m_health << std::endl;
        }
        void attack() {
            std::cout << "Enemy attacks!" << std::endl;
        }

    void takeDamage(int damage) {
        m_health -= damage;
        std::cout << "Enemy takes " << damage << " damage! Health: " << m_health << std::endl;
    }
    
};