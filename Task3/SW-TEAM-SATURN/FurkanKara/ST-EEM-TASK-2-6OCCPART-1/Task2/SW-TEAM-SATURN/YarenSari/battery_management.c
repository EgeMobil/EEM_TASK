#include "battery_management_public.h"
#include "battery_management_private.h"
#include "definition.h"
#include <stdio.h>

static float cellVoltages[6] = {4.1, 4.0, 4.1, 4.0, 4.2, 4.1};			// 6 hücre için voltaj değerleri
static float cellTemperatures[6] = {25, 26, 24, 25, 27, 26};			// 6 hücre içim sıcaklık değerleri
static char batteryHealth[20] = "Good";									// batarya durumunu tutar

//// "battery_management_public.h" dosyasının fonksiyonları ////

// bataryanın doluluk oranını dönen fonksiyon
float Battery_getChargeLevel(void) 
{
    float averageVoltage = Battery_getVoltage();									// hücrelerde yer alan toplam voltaj değeri averageVoltage değerine atanır							
    return ((averageVoltage - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE)) * 100;	// mevcut voltaj ile voltajın tüm kullanabilir değer aralığı hesaplanarak bataryanın doluluk oranı bulunur
}

// bulunan hücrelerin voltaj değerleri toplanır ve toplam voltaj hesaplanır
float Battery_getVoltage(void) 
{
    float totalVoltage = 0.0;
    for (int i = 0; i < 6; i++) {
        totalVoltage += cellVoltages[i];
    }
    return totalVoltage;
}

// bataryanın durumunu dönen fonksiyon
const char* Battery_getHealthStatus(void) 
{
    Battery_analyzeHealth();
    return batteryHealth;
}

// istenen hücrenin sıcaklık değerini döndüren fonksiyon
float Battery_getCellTemperature(int cell) 
{
    return cellTemperatures[cell];
}

// istenen hücrenin voltaj değerini döndüren fonksiyon 
float Battery_getCellVoltage(int cell) 
{
    return cellVoltages[cell];
}

// hücre dengeleme fonksiyonu
void Battery_balanceCells(void) 
{
    float averageVoltage = Battery_getVoltage() / 6;					// hücrelerin voltaj değerinin ortalaması alınır
    for (int i = 0; i < 6; i++) 
	{
        if (cellVoltages[i] > averageVoltage + BALANCE_THRESHOLD)		// eğer bir hücrenin değeri ortalama değerin hücre dengeleme sınırından büyükse  
            cellVoltages[i] -= 0.01;									// hücrenin voltajı azaltılır
    }
}

// batarya sağlık analizinin yapıldığı private fonksiyon
static void Battery_analyzeHealth(void) 
{
    for (int i = 0; i < 6; i++) {
        if (cellVoltages[i] < MIN_VOLTAGE || cellVoltages[i] > MAX_VOLTAGE ||
            cellTemperatures[i] < MIN_TEMPERATURE || cellTemperatures[i] > MAX_TEMPERATURE) 	// her hücrenin voltaj ve sıcaklık değerleri min ve maks değerler aralığında mı kontrol edilir
		{
            snprintf(batteryHealth, sizeof(batteryHealth), "Warning");							// eğer aralık içerisinde değilse batteryHealth "Warning" olur
            return;
        }
    }
    snprintf(batteryHealth, sizeof(batteryHealth), "Good");										// eğer aralık içerisindeyse batteryHealth "Good" olur
}