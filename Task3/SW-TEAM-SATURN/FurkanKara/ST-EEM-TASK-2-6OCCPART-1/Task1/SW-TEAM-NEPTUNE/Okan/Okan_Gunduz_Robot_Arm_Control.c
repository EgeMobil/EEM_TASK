/* State Machine 

State Machine is a model of computation based on a finite number of states.

Robot Kol Hareket Kontrolü

Durumlar (States):
1- Bekleme
2- Kavrama Açık
3- Kavrama Kapalı 
4- Hareket Et 
5- Bırak

Olaylar (Events):
Robotik kol, belirlenen nesneyi kavrar, 
taşır ve hedef konumuna bırakır.

Geçişler (Transitions):
1- Bekleme -> Kavrama Açık
2- Kavrama Açık -> Kavrama Kapalı   
3- Kavrama Kapalı -> Hareket Et
4- Hareket Et -> Bırak
5- Bırak -> Bekleme

Eylemler (Actions):
1- Bekleme: Robotik kol hareketsiz durur.
2- Kavrama Açık: Robotik kol kavrama mekanizması açık durumda.
3- Kavrama Kapalı: Robotik kol kavrama mekanizması kapalı durumda.
4- Hareket Et: Robotik kol belirlenen nesneyi taşır.
5- Bırak: Robotik kol belirlenen nesneyi bırakır.



*/



#include <stdio.h>

#ifdef _WIN32
    #include <windows.h>
    #define wait(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define wait(ms) usleep((ms) * 1000)
#endif

/* State Machine Tasarlama Süreci
1. Durumlar (States) ve Olaylar (Events) belirlenir.
2. Durumlar arasındaki geçişler (Transitions) belirlenir.
3. Durumlar ve olaylar arasındaki ilişkiler tablo halinde gösterilir.  
4. Durumlar ve olaylar arasındaki ilişkiler kodlanır.
5. Durumlar ve olaylar arasındaki ilişkiler test edilir.
*/

// Durumlar için enum tanımlıyoruz
typedef enum 
{
    Bekleme,
    Kavrama_Acik,
    Kavrama_Kapali,
    Hareket_Et,
    Birak
} Durumlar;

Durumlar mevcut_durum = Bekleme; // Başlangıç durumu Bekleme olarak belirlenir.

void durum_degistir(Durumlar yeni_durum)
{
    mevcut_durum = yeni_durum;
    printf("Durum Degisti: %d\n", mevcut_durum);
}

int main()
{
    int iteration = 10; // 10 iterasyon yapılacak.

    for (int i = 0; i < iteration; i++)
    {
        switch (mevcut_durum)
        {
        case Bekleme:
            printf("Robot Kol Beklemede\n");
            wait(1000); // 1 saniye bekleme
            durum_degistir(Kavrama_Acik);
            break;

        case Kavrama_Acik:
            printf("Kavrama Acik. Nesne Kavranabilir.\n");
            wait(1000); // 1 saniye bekleme
            durum_degistir(Kavrama_Kapali);
            break;

        case Kavrama_Kapali:
            printf("Kavrama Kapali. Nesne Kavrandi.\n");
            wait(1000); // 1 saniye bekleme
            durum_degistir(Hareket_Et);
            break;

        case Hareket_Et:
            printf("Nesne Hareket Ediyor.\n");
            wait(2000); // 2 saniye bekleme
            durum_degistir(Birak);
            break;

        case Birak:
            printf("Nesne Bırakıldı.\n");
            wait(1000); // 1 saniye bekleme
            durum_degistir(Bekleme);
            break;

        default:
            printf("Bilinmeyen Durum\n");
            return 1;
        }
    }

    printf("Robot Kol Hareketi Tamamlandı\n");
    return 0;
}
