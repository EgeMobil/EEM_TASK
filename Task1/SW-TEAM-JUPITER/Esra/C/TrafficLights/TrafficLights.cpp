#include <iostream> 
#include <thread>
#include <chrono> 

enum class TrafficLight{
    RED,
    YELLOW,
    GREEN
};

void handleState(TrafficLight &state) {
    switch (state) {
        case TrafficLight::RED: 
        std::cout << "RED" ;
        std::this_thread::sleep_for(5s); 
        state = TrafficLight::GREEN; 
        break; 
        case TrafficLight::YELLOW: 
        std::cout << "YELLOW" ;
        std::this_thread::sleep_for(2s); 
        state = TrafficLight::RED; 
        break; 
        case TrafficLight::GREEN:
        std::cout << "GREEN"; 
        std::this_thread::sleep_for(3s); 
        state= TrafficLight::YELLOW; 
        break; 

    }
}

int main() {
    TrafficLight state = TrafficLight::RED;

    while(true) {
        handleState(state);
    }
}