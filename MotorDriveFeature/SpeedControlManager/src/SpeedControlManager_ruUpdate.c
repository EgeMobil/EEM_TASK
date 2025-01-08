// baslangic yorumu doxy'gene uygun sekilde yapilacak

// runable'ların fonksiyon tanimi ozel sekilde yapiliyor ona uygun yapilacak.
// #define FUNC(returnType, functionName) returnType functionName

// rawSpeed değerini okur.
// Okunan değer, 0-1000 aralığına normalize edilir. 
// Örneğin, bir ADC verisi veya başka bir kaynaktan gelen değer 0-1000 oranına dönüştürülür.
// Normalize edilen değer bir local attribute’da tutulur (örneğin targetSpeed).

/*
ruUpdate Fonksiyonu:
Hız Okuma:
RawSpeedInterface üzerinden ham hız değeri alınır.
Normalize Etme:
Örneğin, ADC’den gelen 12-bit bir değer (0-4095), 0-1000 aralığına çevrilir.
Dönüştürme formülü: oran orani 4095'te x ise 1000'de ?

*/
 