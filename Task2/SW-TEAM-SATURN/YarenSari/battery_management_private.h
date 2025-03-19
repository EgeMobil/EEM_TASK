#ifndef BATTERY_MANAGEMENT_PRIVATE_H
#define BATTERY_MANAGEMENT_PRIVATE_H

float Battery_getCellTemperature(int cell);		// belirli bir hücrenin sıcaklık değerini döndüren fonksiyon
float Battery_getCellVoltage(int cell);			// belirli bir hücrenin voltaj değerinin döndüren fonksiyon
void Battery_balanceCells(void);				// hücre voltajlarını eşitlemek için kullanılacak olan fonksiyon
static void Battery_analyzeHealth(void);		// battery_management_private dosyasına özgü bir fonksiyondur. hücre voltajlarını ve sıcaklıklarını analiz edecek

#endif