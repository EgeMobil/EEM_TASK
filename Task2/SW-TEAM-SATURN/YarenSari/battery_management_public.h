#ifndef BATTERY_MANAGEMENT_PUBLIC_H
#define BATTERY_MANAGEMENT_PUBLIC_H

// bu iki fonksiyonda pointer dönüşü gerçekleştirilmez çünkü gereksiz yer kaplar. char veri tipleri bellekte bir adreste bulunduğu ve bu adresteki
// değerin değişmemesi gerektiği için const keyword'ü ile geri dönüş sağlanarak ilgili adresteki verinin değişmesine olanak sağlanmaz ve veri korunur.
float Battery_getChargeLevel(void);
float Battery_getVoltage(void);
const char* Battery_getHealthStatus(void);	// const char* olarak tanımlanarak geri dönen değer değiştirilemez olur. bu string ROM veya sabit bellekte saklanır

#endif