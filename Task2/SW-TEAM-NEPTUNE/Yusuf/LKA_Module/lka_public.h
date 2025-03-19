#ifndef LKA_PUBLIC_H
#define LKA_PUBLIC_H

#include "definition.h"

typedef enum {
    LKA_DISABLED = 0,
    LKA_ENABLED
} LKA_Status;

typedef struct LKA LKA;

LKA* LKA_create(void);
void LKA_destroy(LKA* self);

void LKA_enable(LKA* self);
void LKA_disable(LKA* self);
LKA_Status LKA_getStatus(LKA* self);
void LKA_run(LKA* self);

#endif // LKA_PUBLIC_H
