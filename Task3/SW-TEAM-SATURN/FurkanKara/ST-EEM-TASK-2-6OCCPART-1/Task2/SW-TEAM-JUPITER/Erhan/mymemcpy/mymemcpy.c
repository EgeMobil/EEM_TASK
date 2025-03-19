
#include <stdio.h>
#include <string.h>

void* mymemcpy(void* vpdest, const void* vpsource, int n)
{
    char* pdest = (char*) vpdest;
    const char* psource = (const char*) vpsource;
    
    while(n--)
    {
        *pdest = *psource;
        *(pdest++);
        *(psource++);
    }
    return vpdest;
}



int main() {
    char kaynak[] = "Merhaba, Dunya!";
    char hedef[20]; 

    
    mymemcpy(hedef, kaynak, strlen(kaynak) + 1);

    printf("Kaynak: %s\n", kaynak);
    printf("Hedef: %s\n", hedef);

    return 0;
}
