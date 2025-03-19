
/**
 * HEAD: Week 2 Pointer  <ö.varol> gith: <omrvrl>
 * DESC: Reach and print elements of array using pointer arithmetic
 * 
 */



#include<stdio.h>



int EkranaYazdir(int n, int *ptr){
   
    int* last_ptr = ptr + n;                           // ptr + n -> n kadar sonraki adrese gider.  

    
    while(ptr < last_ptr){                             // pointerlar arasında kıyaslama yapılır. yani adımlar aradaki adreslerdir.
        
        printf("Dizi Elemani: %d \n",*ptr);           // İlk indexteki değerden başlayarak pointer ile değerlere ulaşır ve bastırır.
        ptr++;
    };

}


int main(){

    int Dizi[] = {1,2,3,4,5,6,7,8,9};
    
    int* ptr = Dizi;                                                // array ismi tek başına başlangıç adresini tutar, Dizi[0] ise indexteki değeri tutar

    int size_dizi = sizeof(Dizi) / sizeof(Dizi[0]);                 // dizinin boyutunu tespit eder 

    EkranaYazdir(size_dizi,ptr);                                    // dizinin boyutunu ve pointer değişkeni ile adres gönderir.

    return 0;
}