#ifndef STEERING_CONTROL_PUBLIC_H
#define STEERING_CONTROL_PUBLIC_H

#ifdef __cplusplus
extern "C"
{
#endif

    // Dışa açık fonksiyon prototipleri
    void Steering_setAngle(double angle);
    double Steering_getAngle(void);
    void Steering_calibrate(void);

#ifdef __cplusplus
}
#endif

#endif /* STEERING_CONTROL_PUBLIC_H */
