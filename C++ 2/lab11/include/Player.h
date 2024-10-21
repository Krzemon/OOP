#pragma once
#include "GameObject.h"
#include <iostream>
#include <future>
#include <chrono>
#include <thread>

// Derived class representing a player
class Player : public GameObject {
    private:
        int m_health;
        int heavyOperation() {
            // Simulate heavy number operation
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return 42; // Dummy result
        }
    public:
        Player() : m_health(100) {}
        virtual void update() override {
            std::cout << "Enemy update started..." << std::endl;
            // Perform heavy number operation asynchronously
            std::future<int> result_future = std::async(std::launch::async, &Player::heavyOperation, this);
            // Simulate other work while waiting for heavy operation
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Enemy update in progress..." << std::endl;
            // Wait for heavy operation to finish and get the result
            int result = result_future.get();
            std::cout << "Enemy update finished! Result: " << result << ", Health: " << m_health << std::endl;
        }
        void attack() {
            std::cout << "Player attacks!" << std::endl;
        }
        void takeDamage(int damage) {
            m_health -= damage;
            std::cout << "Player takes " << damage << " damage! Health: " << m_health << std::endl;
        }
};