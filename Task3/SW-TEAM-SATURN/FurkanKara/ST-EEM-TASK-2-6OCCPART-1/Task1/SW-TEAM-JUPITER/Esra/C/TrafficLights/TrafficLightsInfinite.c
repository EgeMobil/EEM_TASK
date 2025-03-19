//traffic lights

#include <stdio.h> 
#include <unistd.h> //sleep fonk. için

typedef enum {
    RED,
    YELLOW,
    GREEN
} TrafficLight; 

void handleState(TrafficLight *state) {
    switch (*state) {
        case RED:
        printf("Kırmızı ışık! Durun.\n");
        sleep(5);
             *state = GREEN; 
             break; 
        case YELLOW:
        printf("Sarı ışık! Hazır olun.\n");
        sleep(2);
            *state = RED;
            break; 
        case GREEN:
        printf("Yeşil ışık! Geçebilirsiniz.\n");
        sleep(5);
            *state = YELLOW; 
            break; 
    }
}

int main() {
    TrafficLight state = RED; 

    while(1) {
        handleState(&state); 
    
}

}