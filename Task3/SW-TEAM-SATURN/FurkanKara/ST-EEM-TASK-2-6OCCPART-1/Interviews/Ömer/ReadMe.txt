Öncelikle Stm32f407 kartını tercih ettim. Stm32CubeIde kullanacağım bunun sebebi elimde bunun bulunması yoksa pedaldan veri okumak için daha düşük maliyetli bir kart tercih edebilirim. Kartın Adc bulundurması önemlidir. Pedal üzerinden veri adc ile okuduktan sonra aldığım veriyi işlemeye başlayabilirim.

Kodun modüler olması gerektiği göz önünde bulundurularak her bir katman için bir header ve bir source dosyası açtım.

Controller source dosyasında Adc ile pedal üzerinden aldığımız veriyi alan ve doğrulayan bir fonksiyon yazdım.

Application source dosyasında Adc verisinin okunması ve timer üzerinden pwm sinyali ile motor hızının ayarlanması için 2 tane fonksiyon yazdım.

Interface source dosyasında Application dosyasını dahil ederek bu modülden motor sürücüsüne pwm sinyali gönderme fonksiyonunu çağırdım.

Source dosyasında ise alınan verilerin MCU'nun flash belleğine kayıt işlemleri için bir fonksiyonda ekledim.

Main dosyasında timer üzerinden her 10ms de bir kesme olacak şekilde timer kesmesi oluşturdum. Böylece her kesmede veriler işlenip motor hızı ayarlayacak veriler motor sürücü devresine gönderilecek.


