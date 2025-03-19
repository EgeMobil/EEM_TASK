#ifndef SPEED_CONTROL_PUBLIC_H
#define SPEED_CONTROL_PUBLIC_H

// Dışa açık fonksiyonlar
void Speed_setTarget(int newSpeed);
int Speed_getCurrent();
void Speed_adjust(int event);

#endif // SPEED_CONTROL_PUBLIC_H
