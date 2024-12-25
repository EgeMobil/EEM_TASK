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
    FULL,
    EMPTYING,
    EMPTY,
    FULLING
} tankState;


tankState state = FULL; 


void writeState(tankState d) {
    switch (d) {
        case FULL: printf("Durum: DOLU\n"); break;
        case EMPTYING: printf("Durum: BOSALIYOR\n"); break;
        case EMPTY: printf("Durum: BOS\n"); break;
        case FULLING: printf("Durum: DOLUYOR\n"); break;
        default: printf("Durum: BILINMIYOR\n");
    }
}


void updateState() {
    switch (state) {
        case FULL:
            printf(">> Su kullanıyoor\n");
            sleep(2); 
            state = EMPTYING; 
            break;

        case EMPTYING:
            printf(">> Su seviyesi azalıyor\n");
            sleep(2); // 2 saniye
            state = EMPTY; 
            break;

        case EMPTY:
            printf(">> Pompa calıştırılıyor\n");
            sleep(3); // gecıkme sürelerini ayarladım sleep() ile 3 saniye
            state = FULLING; 
            break;

        case FULLING:
            printf(">> Su deposu doluyor\n");
            sleep(3); // 3 saniye
            state = FULL; 
            break;

        default:
            printf(">> Bilinmeyen bir durum var\n");
            break;
    }
}

int main() {
    printf("Su Deposu Kontrol Sistemi Başlatılıyor\n");

    while (1) { // 1 yazarak sonsuz döngü yaptım.
    

        writeState(state);
        updateState();
        printf("----------------------------");
    }

    return 0;
}
