#ifndef SPEED_CONTROL_PUBLIC_H
#define SPEED_CONTROL_PUBLIC_H

// Hedef hız değerini ayarlar
int Speed_setTarget(int speed);

// Mevcut hız değerini döner
int Speed_getCurrent(void);

// Mevcut hızı hedef hıza yaklaştırmak için ayarlama yapar
void Speed_adjust(void);

#endif // SPEED_CONTROL_PUBLIC_H