#include <stdio.h>
#include <unistd.h>
#include "elevatorControlSystem.h"

// asansör konrol sistemi sistemi başlatmak için öncelikle enter tuşuna basmalısınız sonrasında gitmeniz gereken katı girmelisiniz 
// asansörün giriş tuşunu enter olarak düşündüm
// eğer aynı katı girerseniz bir kez daha girmenizi istemektedir
// sistemi daha iyi görebilmemiz için 100 ms bekleme konulmuştur



int main()
{
    while(1)
    {
        elevatorControlSystem();
        usleep(100000);  // 100 milisaniye = 100,000 mikro saniye
    }
}