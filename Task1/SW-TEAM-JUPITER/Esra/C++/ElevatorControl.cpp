#include <iostream>
#include <thread>
#include <chrono>
#include <limits>

class ElevatorSystem {
private:
    static constexpr int MIN_FLOOR = 0;
    static constexpr int MAX_FLOOR = 5;
    static constexpr int DOOR_OPERATION_TIME = 2;
    static constexpr int MOVEMENT_TIME = 3;

    enum class State {
        IDLE,
        FLOOR_SELECTION,
        DOOR_OPERATION,
        MOVING,
        REACHED_DESTINATION
    };

    State currentState;
    int currentFloor;
    int targetFloor;

    bool isValidFloor(int floor) const {
        return floor >= MIN_FLOOR && floor <= MAX_FLOOR;
    }

    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

public:
    ElevatorSystem() 
        : currentState(State::IDLE)
        , currentFloor(0)
        , targetFloor(0) {}

    void handleState() {
        using namespace std::chrono_literals;

        switch (currentState) {
            case State::IDLE:
                std::cout << "Elevator is idle. Waiting for floor selection...\n";
                std::this_thread::sleep_for(2s);
                currentState = State::FLOOR_SELECTION;
                break;

            case State::FLOOR_SELECTION:
                std::cout << "Current floor: " << currentFloor << '\n';
                std::cout << "Select floor (" << MIN_FLOOR << "-" << MAX_FLOOR << "): ";
                
                if (std::cin >> targetFloor) {
                    if (!isValidFloor(targetFloor)) {
                        std::cout << "Invalid floor selection!\n";
                        clearInputBuffer();
                        currentState = State::IDLE;
                    } else if (targetFloor == currentFloor) {
                        std::cout << "Already on this floor!\n";
                        currentState = State::IDLE;
                    } else {
                        currentState = State::DOOR_OPERATION;
                    }
                } else {
                    std::cout << "Invalid input!\n";
                    clearInputBuffer();
                    currentState = State::IDLE;
                }
                break;

            case State::DOOR_OPERATION:
                std::cout << "Doors opening...\n";
                std::this_thread::sleep_for(2s);
                std::cout << "Doors closing...\n";
                std::this_thread::sleep_for(2s);
                currentState = State::MOVING;
                break;

            case State::MOVING:
                std::cout << "Moving from floor " << currentFloor 
                         << " to floor " << targetFloor << "...\n";
                std::this_thread::sleep_for(3s);
                currentFloor = targetFloor;
                currentState = State::REACHED_DESTINATION;
                break;

            case State::REACHED_DESTINATION:
                std::cout << "Arrived at floor " << currentFloor << "!\n";
                std::this_thread::sleep_for(2s);
                currentState = State::DOOR_OPERATION;
                break;
        }
    }
};

int main() {


    ElevatorSystem elevator;
    
    while (true) {
        try {
            elevator.handleState();
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            break;
        }
    }


}