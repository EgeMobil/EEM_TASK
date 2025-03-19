#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <limits>


enum class DoorState {
    WAITING,
    CARD_READING,
    VERIFICATION,
    OPEN_CLOSE
};

class DoorControlSystem {
private:
    static constexpr const char* VALID_CARD = "12345";
    static constexpr const char* VALID_PIN = "54321";
    DoorState currentState;


    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::string getSecureInput(const std::string& prompt) {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin >> std::ws, input);
        return input;
    }

public:
    DoorControlSystem() : currentState(DoorState::WAITING) {}

    void handleState() {
        using namespace std::chrono_literals;

        switch (currentState) {
            case DoorState::WAITING:
                std::cout << "Door is locked, waiting for credentials...\n";
                std::this_thread::sleep_for(2s);
                currentState = DoorState::CARD_READING;
                break;

            case DoorState::CARD_READING:
                {
                    std::string cardNumber = getSecureInput("Enter card number: ");
                    std::string pin = getSecureInput("Enter PIN: ");
                    
                    if (cardNumber.empty() || pin.empty()) {
                        std::cout << "Invalid input! Please try again.\n";
                        currentState = DoorState::WAITING;
                    } else {
                        currentState = DoorState::VERIFICATION;
                        processCredentials(cardNumber, pin);
                    }
                }
                break;

            case DoorState::VERIFICATION:
                std::this_thread::sleep_for(2s);
                currentState = DoorState::WAITING;
                break;

            case DoorState::OPEN_CLOSE:
                std::cout << "Door is open...\n";
                std::this_thread::sleep_for(5s);
                std::cout << "Door closing...\n";
                std::this_thread::sleep_for(2s);
                currentState = DoorState::WAITING;
                break;
        }
    }

private:
    void processCredentials(const std::string& cardNumber, const std::string& pin) {
        if (cardNumber == VALID_CARD && pin == VALID_PIN) {
            std::cout << "Access granted! Door opening...\n";
            currentState = DoorState::OPEN_CLOSE;
        } else {
            std::cout << "Invalid credentials! Please try again.\n";
            currentState = DoorState::WAITING;
        }
    }
};

int main() {
    std::cout << "Door Control System Started\n";
    std::cout << "-------------------------\n";

    DoorControlSystem doorSystem;
    
    while (true) {
        try {
            doorSystem.handleState();
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            break;
        }
    }

}