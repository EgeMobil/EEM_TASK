#include "../inc/main.h"

int main() {
    Climate_PublicInit();

    float input = -1;
    uint8_t received;

    while(1) {
        received = getInputWithTimeout(&input);

        if(received == 0)
            Climate_Update();
        else if(received == 2)
            exit(-1);
        else
            Climate_UserSetTargetTemp(&input);
    }
    return 0;
}

#ifdef _WIN32

int getInputWithTimeout(float* input) {
    clock_t start_time = clock();
    char buffer[100];

    while ((clock() - start_time) < TIMEOUT_MS * CLOCKS_PER_SEC / 1000) {
        if (_kbhit()) {  // Klavyeden giriş var mı?
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                *input = strtof(buffer, NULL);

                if (*input == 0.0f) {
                    return 2;
                }
                return 1;
            }
        }
    }
    return 0;  // Timeout
}

#else

int getInputWithTimeout(float* input) {
    struct pollfd fds;
    int ret;
    char buffer[100];

    fds.fd = STDIN_FILENO;
    fds.events = POLLIN;
    fds.revents = 0;

    ret = poll(&fds, 1, TIMEOUT_MS);

    if (ret == -1) {
        perror("poll() error");
        exit(1);
    } 
    else if (ret == 0) {
        return 0;
    } 
    else {
        if (fds.revents & POLLIN) {
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                *input = strtof(buffer, NULL);

                if (*input == 0.0f) {
                    return 2;
                }

                return 1;
            }
        }
    }
    return 0;
}

#endif