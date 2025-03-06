/*
*main.c
*
*		Created on: 06.03.25
*		Author: Ismail Gunes
*
*
*        strlen() fonksiyonunu işaretçi aritmetiği ile sıfırdan yazalım
*/
#include <stdio.h>


size_t EM_strlen(const char *str)
{
    const char *ptr = str; // Başlangıç işaretçi adresini sakla
    
    while (*ptr) // işaretçi NULL olana kadar döngüde kal
    { 
        ptr++;      //işaretçi değerini arttır (string 32bit olduğu için her artış diğer bir stringe denk gelecektir.)
    }
    return ptr - str; // işaretçilerin arasında fark bize uzunluğu verir
}

int main() {
    char test[] = "EGE MOBİL";
    printf("Uzunluk: %zu\n", EM_strlen(test));
}
/*******END OF FILE********/