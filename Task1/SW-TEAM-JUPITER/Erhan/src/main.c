#include <stdio.h>
#include <unistd.h>
#include "elevatorControlSystem.h"

// Asansör kontrol sistemini başlatmak için öncelikle Enter tuşuna basmanız gerekmektedir. Bu tuş, asansörün giriş komutu olarak düşünülmüştür. 
// Sistemi başlattıktan sonra, gitmek istediğiniz kat numarasını girmelisiniz.
// Eğer bulunduğunuz katı tekrar girerseniz, sistem sizden geçerli bir kat numarası girmenizi isteyecektir. 
// Bu, yanlış girişleri önlemek ve sistemin daha doğru çalışmasını sağlamak için eklenmiştir.
// Ayrıca, sistemin çalışma sürecini daha iyi gözlemleyebilmek adına her işlemin ardından 100 ms bekleme süresi eklenmiştir. 
// Bu kısa gecikme, sistemin akışını daha net görmenizi sağlayacaktır.



int main()
{
    elevatorControlSystem_init();
    
    while(1)
    {
        elevatorControlSystem();
        usleep(100000);  // 100 milisaniye = 100,000 mikro saniye
    }
}