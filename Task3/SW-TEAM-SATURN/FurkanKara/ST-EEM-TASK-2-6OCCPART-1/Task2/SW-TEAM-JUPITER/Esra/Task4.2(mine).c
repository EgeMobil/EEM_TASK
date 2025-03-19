//task 4- 2den fazla işlem 


#include <stdio.h> 
#include <stdlib.h> 

float sum(float nums[], int n) { 
    float result = 0; 
    for(int i = 0; i < n; i++) {
        result += nums[i]; 
    }
     return result; 
}

float mul(float nums[], int n) {
    float result = 1; 
    for(int i=0; i<n; i++) {
        result *= nums[i]; 
    }
    return result; 
}

int main() {
    int n; 
    char islem; 
    float (*islem_ptr)(float[], int) = NULL;

    printf("Kac sayi ile islem yapacaksiniz?: ");
    scanf("%d", &n);

    float* sayilar = (float*)malloc(n * sizeof(float)); 

    printf("%d sayi girin: \n", n); 
    for(int i = 0; i < n; i++) {
        scanf("%f", &sayilar[i]); 
    }

    printf("Islem secin (+, *): ");
    scanf(" %c", &islem);

   if(islem == '+') {
    islem_ptr = sum; 
   } else if (islem == '*') {
    islem_ptr = mul; 
   }

   if(islem_ptr != NULL) {
    printf("sonuc: %.2f\n", islem_ptr(Sayilar, n)); 
   } else {
    printf("gecersiz islem\n"); 
   }



    free(sayilar); 
    return 0; 
}