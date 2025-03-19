#include <stdio.h>


typedef enum 
{
    BEKLE,
    NEMI_OLC,
    ESIG_KONTROL,
    POMBA_AC,
    SULAMA_TAMAMLANDI
} NemState;


// Sensör ve pompa için varsayılan değerler
#define ESIK_NEM_SEVIYESI 40 //örnek eşik değer



//sensör değerini okuyan fonksiyon

int nemOku() {
    // Bu fonksiyon sensörden okunan değeri döndürecektir.
    // Şu an sabit bir değer döndürüyoruz, ancak gerçek sensör verisini buradan alabiriz.
    return 50;  // Sensör değerini burada değiştirilir.
}


//pompayı kontrol eden fonksiyon

void pompaAc()
{
    printf("Pompa acildi.Sulama gerceklesiyor\n");
}

void pompaKapat()
{
    printf("Pompa kapatildi");
}

NemState currentState = BEKLE;
int main()
{
    int toprak_nem_seviyesi;
    while(1)
    {
        switch (currentState)
        {
        case BEKLE:
        printf("Bekleme ekrani\n");
        currentState = NEMI_OLC;

            break;
        case NEMI_OLC:
        printf("Nem olculuyor\n");
        toprak_nem_seviyesi = nemOku();
        currentState = ESIG_KONTROL;

            break;        
        case ESIG_KONTROL:
        printf("Pompanin calismasi icin esik kontrol ediliyor\n");
        if(toprak_nem_seviyesi < ESIK_NEM_SEVIYESI)
        {
            currentState = POMBA_AC;
        }
        else
        {   printf("Nem seviyesi yuksek.Pompa calismiyor");
            currentState = BEKLE;
        }

            break;
        case POMBA_AC:
        printf("Pompa calisiyor\n");
        pompaAc();
                
        // Nem seviyesi artana kadar döngü içinde sürekli kontrol et
        while (1) {
            toprak_nem_seviyesi = nemOku();
            if (toprak_nem_seviyesi >= ESIK_NEM_SEVIYESI) {
                break;
            }
        }
        
        pompaKapat();
        currentState = SULAMA_TAMAMLANDI;          
          break;     
        case SULAMA_TAMAMLANDI:
        printf("Sulama Tamamlandi\n");
        currentState = BEKLE;

            break;                            
        
        default:
        currentState = BEKLE;
            break;
        }
    }
    return 0;

}



