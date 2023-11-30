// Observability.h

#pragma once

#include <iostream>
#include <vector>
#include <string>

// Observer interface
class Observer {
public:
    virtual ~Observer() {}
    virtual void Update(const std::string& message) = 0;
};

// Observable subject
class Observable {
private:
    std::vector<Observer*> observers;

public:
    void AddObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void RemoveObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void NotifyObservers(const std::string& message) {
        for (auto observer : observers) {
            observer->Update(message);
        }
    }
};

// Logger class that observes and logs messages
class Logger : public Observer {
public:
    void Update(const std::string& message) override {
        std::cout << "[Log] " << message << std::endl;
    }
};

// Observability utility functions

// Function to
