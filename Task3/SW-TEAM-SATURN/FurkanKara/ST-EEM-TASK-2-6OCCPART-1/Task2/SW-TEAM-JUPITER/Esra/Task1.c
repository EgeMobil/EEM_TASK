/*Dizideki En Büyük ve En Küçük Elemanı Bulma
 Senaryo: Kullanıcıdan N elemanlı bir dizi al ve işaretçi aritmetiği ile en büyük ve en küçük elemanları bul.

 Hedefler:

Diziyi işaretçi aritmetiği ile dolaş (indis kullanma!).

Dinamik bellek tahsisi ile bellek verimli kullanılsın.  */ 

#include <stdio.h> 
#include <stdlib.h> 
//*arr : diziye işaret eden işaretçi: dizinin başlangıç adresi
//int n: dizinin eleman sayısı
//float *min, *max en küçük ve en büyük değeri saklamak için pointers

void findMinMax(float *arr, int n, float *min, float *max) {
    *min = *max = *arr; 

    //ptr diziye işaret eden işaretçi 
    //arr + 1 dizinin ikinci elemanı 
    //arr+n dizinin son elemanından bir sonraki eleman 

    for(float *ptr = arr + 1; ptr < arr + n; ptr++) {
        if(*ptr < *min) {
            *min = *ptr; 
        }
        if(*ptr > * max) {
            *max = *ptr;
        }
        }
    }





int main() {
     int n; 
     printf("kaç elemanlı bir dizi gireceksiniz?:"); 
     scanf("%d", &n); 

    //dinamik bellek tahsisi 
    float *dizi = (float*)malloc(n * sizeof(float)); 
    if(dizi == NULL) {
        printf("bellek tahsisi hata!\n");
        return 1;
    }

    printf("%d adet sayi girin: \n" n); 
    for(float *ptr =dizi; ptr < dizi + n; ptr++) {
        scanf("%f", ptr); 
    }

    float min, max; 
    findMinMax(dizi, n, &min, &max); 

    printf("en kucuk: %.2f\n", min); 
    printf("en buyuk: %.2f\n", max); 


    //belleği, serbest bırakma
    free(dizi); 
    return 0; 
    
}