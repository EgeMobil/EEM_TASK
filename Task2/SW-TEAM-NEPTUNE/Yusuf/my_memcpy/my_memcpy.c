#include <stdio.h>

// Test icin kullanılacak struct tanimi
typedef struct {
    int id;
    float value;
    char name[20];
} TestStruct;


// dest   : Hedef adres
// src    : Kaynak adres
// n      : boyut (byte)
// hedef adresini doner.
void *my_memcpy(void *dest, const void *src, size_t n) {
    // void pointer'ları byte bazında işleyebilmek için char pointer'a cast ediyoruz.
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    // n byte'ı tek tek kopyala
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }

    return dest;
}

// Test kodu
int main(void) {
    
    TestStruct src = {1, 3.14f, "Test Struct"};
    TestStruct dst;
    
    my_memcpy(&dst, &src, sizeof(TestStruct));
    
    printf("Kopyalanan struct:\n");
    printf("ID: %d\n", dst.id);
    printf("Value: %f\n", dst.value);
    printf("Name: %s\n", dst.name);
    
    printf("\n------------------------\n\n");
   
    int srcInts[5] = {10, 20, 30, 40, 50};
    int dstInts[5] = {0};

    my_memcpy(dstInts, srcInts, 5 * sizeof(int));

    printf("int dizisi kopyasi: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dstInts[i]);
    }
    
    printf("\n------------------------\n\n");

  
    char srcStr[] = "Merhaba";
    char dstStr[50] = {0};

    my_memcpy(dstStr, srcStr, sizeof(srcStr));

    printf("char dizisi kopyasi: %s\n", dstStr);

    return 0;
}