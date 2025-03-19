#include "lka_private.h"
#include <stdio.h>
#include <stdlib.h>

void LKA_processCameraData(LKA* self) {
    LKA_PrivateData* pdata = self->privateData;

    pdata->laneWidth = MIN_LANE_WIDTH + 50;
    pdata->laneOffset = 5.0f;              
    printf("Kamera verisi islendi: Serit genisligi = %d, Sapma = %.2f\n",
           pdata->laneWidth, pdata->laneOffset);
}

void LKA_calculateSteeringCorrection(LKA* self) {
    LKA_PrivateData* pdata = self->privateData;
    float correction = ((float)(pdata->laneWidth - MIN_LANE_WIDTH) / MIN_LANE_WIDTH) * MAX_CORRECTION_ANGLE;
    if (correction > MAX_CORRECTION_ANGLE) {
        correction = MAX_CORRECTION_ANGLE;
    }
    if (((float)pdata->laneWidth / MIN_LANE_WIDTH) < SAFETY_THRESHOLD) {
        printf("Uyarı: Serit genisligi guvenlik esik degerinin altinda.\n");
    }
    printf("Hesaplanan direksiyon duzeltme acisi: %.2f derece\n", correction);
}


static void LKA_enable_impl(LKA* self) {
    self->status = LKA_ENABLED;
    printf("LKA sistemi etkin.\n");
}

static void LKA_disable_impl(LKA* self) {
    self->status = LKA_DISABLED;
    printf("LKA sistemi devre disi.\n");
}

static LKA_Status LKA_getStatus_impl(LKA* self) {
    return self->status;
}

static void LKA_run_impl(LKA* self) {
    if (self->status == LKA_ENABLED) {
        LKA_processCameraData(self);
        LKA_calculateSteeringCorrection(self);
    } else {
        printf("LKA sistemi kapali.\n");
    }
}


LKA* LKA_create(void) {
    LKA* obj = (LKA*) malloc(sizeof(LKA));
    if (!obj) return NULL;

    // Dahili veriler için bellekte yer ayıralım
    LKA_PrivateData* pdata = (LKA_PrivateData*) malloc(sizeof(LKA_PrivateData));
    if (!pdata) {
        free(obj);
        return NULL;
    }
    pdata->laneWidth = 0;
    pdata->laneOffset = 0.0f;

    obj->status = LKA_DISABLED;
    obj->privateData = pdata;

    obj->enable = LKA_enable_impl;
    obj->disable = LKA_disable_impl;
    obj->getStatus = LKA_getStatus_impl;
    obj->run = LKA_run_impl;

    return obj;
}

void LKA_destroy(LKA* self) {
    if (self) {
        if (self->privateData)
            free(self->privateData);
        free(self);
    }
}

int main(void) {
    LKA* lka = LKA_create();
    if (!lka) {
        fprintf(stderr, "LKA nesnesi olusturulamadi.\n");
        return 1;
    }

    lka->enable(lka);
    lka->run(lka);
    lka->disable(lka);
    lka->run(lka);

    LKA_destroy(lka);
    return 0;
}
