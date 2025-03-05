//TASK 4  
#include <stdio.h> 

float sum(float a, float b) { 
    return a+b; 

}

float sub(float a, float b) {
    return a-b; 
}

float mul(float a, float b) {
    return a*b; 
}

float div(float a, float b) {
    if( b!= 0){
    return a/b;
    }
    return 0; 
}

float (*p)(float, float) = NULL; 

int main() {
    float x,y; 
    char islem; 



    printf(iki sayı girin: ); 
    scanf("%f %f", &x, &y); 

    printf("İşlem seçin (+, -, *, /): ");
    scanf(" %c", &islem);

    float (*islemler[])(float, float) = {sum, sub, mul, div}; 
    char islemlerDizisi[] = {'+', '-', '*', '/'};

    for(int i = 0; i< 4; i++) {
        if(islem == islemlerDizisi[i]) {
            p = islemler[i]; 
            break; 
        }
    }

    if(p != NULL) {
        if(islem == '/' && y == 0) {
            printf("0'a bölme hatası! \n"); 
        } else {
            printf("sonuç: %.2f\n", p(x,y)); 
        }
       
    }

    else {
        printf("geçersiz islem!\n"); 
    }
    return 0; 


}