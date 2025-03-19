#include "System.h"

void WriteToFlash(uint32_t f);

/*
 * BU Fonskiyon Araçlarda bulunan Diagnostic mesajını temsil eder.
 * Errorun içeriğine göre gönderdiği mesajın içeriği değişecektir.
 * Bunu yapmamızın sebebi hataları kolay bir şekilde gözlemyebilmek
 */
void DM1_error(error_t err){

	Send_DM1_Sequence();

}

/*
 *Bu fonskiyon temsili bir Diagnostic mesajı gönderen fonskiyodur.
 *Bu  Diagnostic mesajları bir sequence olarak gönderildiği için bu fonskiyonda o sequence başlatılıyor.
 */
void Send_DM1_Sequence(){

	// START SEQUENCE
}



