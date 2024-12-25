/*

1- durumlar stateler
dolu
boşalıyor 
boş
doluyor
2- olaylar eventler
su miktarı algılanır
3-geçişler
Dolu ? Boşalıyor (su kullanımı başladığında).
Boşalıyor ? Boş (seviye çok düştüğünde).
Boş ? Doluyor (pompa çalıştırıldığında).
Doluyor ? Dolu (seviye tamamen dolduğunda).
4- eylemler actionlar
Pompa motoru çalıştırılır veya durdurulur.

*/



typedef enum {
    DOLU,
    BOSALIYOR,
    BOS,
    DOLUYOR
} DepoDurumu;


DepoDurumu durum = DOLU; 


void durumYazdir(DepoDurumu d) {
    switch (d) {
        case DOLU: printf("Durum: DOLU\n"); break;
        case BOSALIYOR: printf("Durum: BOSALIYOR\n"); break;
        case BOS: printf("Durum: BOS\n"); break;
        case DOLUYOR: printf("Durum: DOLUYOR\n"); break;
        default: printf("Durum: BILINMIYOR\n");
    }
}


void durumGuncelle() {
    switch (durum) {
        case DOLU:
            printf(">> Su kullanıyoor\n");
            sleep(2); 
            durum = BOSALIYOR; 
            break;

        case BOSALIYOR:
            printf(">> Su seviyesi azalıyor\n");
            sleep(2); // 2 saniye
            durum = BOS; 
            break;

        case BOS:
            printf(">> Pompa calıştırılıyor\n");
            sleep(3); // gecıkme sürelerini ayarladım sleep() ile 3 saniye
            durum = DOLUYOR; 
            break;

        case DOLUYOR:
            printf(">> Su deposu doluyor\n");
            sleep(3); // 3 saniye
            durum = DOLU; 
            break;

        default:
            printf(">> Bilinmeyen bir durum var\n");
            break;
    }
}

int main() {
    printf("Su Deposu Kontrol Sistemi Başlatılıyor\n");

    while (1) { // 1 yazarak sonsuz döngü yaptım.
    

        durumYazdir(durum);
        durumGuncelle();
        printf("----------------------------");
    }

    return 0;
}