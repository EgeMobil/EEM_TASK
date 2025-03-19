#include <stdio.h>
/*
Bir hesap makinesi uygulamasında, toplama, çıkarma, çarpma ve bölme işlemlerini bir dizi içinden fonksiyon işaretçileri ile çağırmak istiyoruz.
Hedef:
Kullanıcı bir işlem türü girdiğinde, doğru fonksiyon seçilmeli ve işlem gerçekleştirilmelidir.
*/
float add(float x, float y)
{
    return (x + y);
}

float subtract(float x, float y)
{
    return (x - y);
}

float multiply(float x, float y)
{
    return (x * y);
}

float divide(float x, float y)
{
    if (y != 0)
        return (x / y);
    printf("Error! Division by zero. Please enter a non-zero number for second number : ");
    scanf("%f", &y);
    return divide(x, y);
}
int main()
{
    float x, y, result = 0;
    int choice;
    float (*op[4])(float, float) = {add, subtract, multiply, divide};
    while (1)
    {
        printf("Enter 0 to add, 1 to subtract, 2 to multiply, 3 to divide, 4 to Reset or to QUIT press any key: ");
        if (!scanf("%d", &choice)) 
            break;
        if(choice == 4 ){
            result = 0 ;printf("System reseted.\n");
            printf("Enter 0 to add, 1 to subtract, 2 to multiply, 3 to divide, 4 to Reset or to QUIT press any key: "); scanf("%d", &choice);}
        if(result == 0){
            printf("Enter two number: ");
            scanf("%f%f", &x, &y);
        }    
        else{
            printf("Enter a number: ");
            scanf("%f", &y);
            x = result; result = 0;
        }
        if (choice >= 0 || choice <= 3) // switch case yapılabilir fakat satır uzar.
            result += op[choice](x, y);
        else
            printf("Invalid choice. Please enter a number between 0 and 3. \n");
        printf("\n %.4f \n", result);
    }
    return 0;
}
