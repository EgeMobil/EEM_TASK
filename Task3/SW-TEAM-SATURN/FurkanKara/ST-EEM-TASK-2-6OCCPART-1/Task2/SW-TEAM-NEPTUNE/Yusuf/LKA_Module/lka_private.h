#ifndef LKA_PRIVATE_H
#define LKA_PRIVATE_H

#include "lka_public.h"

typedef struct {
    int laneWidth;
    float laneOffset;
} LKA_PrivateData;

struct LKA {
    LKA_Status status;

    void (*enable)(LKA* self);
    void (*disable)(LKA* self);
    LKA_Status (*getStatus)(LKA* self);
    void (*run)(LKA* self);

    LKA_PrivateData* privateData;
};

void LKA_processCameraData(LKA* self);
void LKA_calculateSteeringCorrection(LKA* self);

#endif // LKA_PRIVATE_H
