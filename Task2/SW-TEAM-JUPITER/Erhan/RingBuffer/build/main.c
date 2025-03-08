
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "ringBuffer.h"

char bufferArray[8];
char gelenData;


int main() 
{
    ty_ringBuffer ringBuffer;
    srand(time(NULL));
    
    rb_init(&ringBuffer, bufferArray, sizeof(bufferArray));
  
    // 7 adet rasgele veri eklendi
    rb_push(&ringBuffer, (char) '0' + rand() % 10);
    rb_push(&ringBuffer, (char) '0' + rand() % 10);
    rb_push(&ringBuffer, (char) '0' + rand() % 10);
    rb_push(&ringBuffer, (char) '0' + rand() % 10);
    rb_push(&ringBuffer, (char) '0' + rand() % 10);
    rb_push(&ringBuffer, (char) '0' + rand() % 10);
    rb_push(&ringBuffer, (char) '0' + rand() % 10);

    // veriler okunuyor eğer rb_pop epmty dönerse while döngüsünden çıkıyor 
    while (rb_pop(&ringBuffer, &gelenData) != RB_EMPTY)
    {    
        printf("gelen data: %c\n",gelenData);
    }
}
