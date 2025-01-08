// baslangic yorumu doxy'gene uygun sekilde yapilacak

// runable'ların fonksiyon tanimi ozel sekilde yapiliyor ona uygun yapilacak.
// #define FUNC(returnType, functionName) returnType functionName

// mevcut hız (currentSpeed) ile hedef hız (targetSpeed) arasındaki fark kontrol edilir.
// Mevcut hız, hedef hıza doğru kademeli şekilde (KADEME)
//(örneğin her çağrıda sabit bir adım değeri kadar) artırılır veya azaltılır.
//ruRefresh fonksiyonu 1 ms’de bir çağrıldığından, hız değişim adımını (step) 
//bu süreye uygun şekilde ayarlamak önemlidir.

/*
Hedef Hıza Yaklaşma:
Eğer mevcut hız (currentSpeed), hedef hızdan (targetSpeed) küçükse:
currentSpeed, her çağrıda speedStep kadar artırılır.
Eğer mevcut hız, hedef hızdan büyükse:
currentSpeed, her çağrıda speedStep kadar azaltılır.
Sınır Kontrolü:
currentSpeed, hedef hızı aşıyorsa (artırma veya azaltma durumunda), currentSpeed hedef hız olarak ayarlanır.
*/

/* 

PWM değişim kademesini (step) dinamik olarak ayarlamak için hedef hız (targetSpeed) ve 
mevcut hız (currentSpeed) arasındaki farkı ve PWM aralığındaki oranları kullanabiliriz. 
Böylece hız değişimi, hedef hıza daha hızlı veya daha yavaş ulaşmayı sağlayacak şekilde ayarlanabilir. 
Aşağıda bunun için önerdiğim bir metodoloji var:

1-) Hedef hız ve mevcut hız arasındaki fark ne kadar büyükse, değişim kademesi (speedStep) o kadar büyük olabilir.
Küçük farklarda daha yumuşak bir geçiş sağlamak için daha küçük bir kademe kullanılabilir.

speedStep = max(minStep, min(maxStep, (targetSpeed - currentSpeed) / divider));

minStep: Minimum değişim adımı. Çok yavaş geçişleri önlemek için bir alt sınır.
maxStep: Maksimum değişim adımı. Çok hızlı geçişleri önlemek için bir üst sınır.
divider: Farkı yavaşlatmak veya hızlandırmak için bir ölçek faktörü.

static const uint16_t minStep = 5;  // Minimum kademe (örneğin, 5 birim).
static const uint16_t maxStep = 50; // Maksimum kademe (örneğin, 50 birim).
static const uint16_t divider = 20; // Dinamik bölme faktörü.

void IIndicatorSpeedStatus_ruRefresh(void)
{
    uint16_t speedStep;

    // Hedef ve mevcut hız farkına göre dinamik kademe hesaplama
    uint16_t speedDiff = abs((int32_t)targetSpeed - (int32_t)currentSpeed);
    speedStep = max(minStep, min(maxStep, speedDiff / divider));

    if (currentSpeed < targetSpeed)
    {
        // Hız artışı
        currentSpeed += speedStep;
        if (currentSpeed > targetSpeed)
        {
            currentSpeed = targetSpeed; // Hedef hıza aşırı geçişi önle
        }
    }
    else if (currentSpeed > targetSpeed)
    {
        // Hız azalışı
        currentSpeed -= speedStep;
        if (currentSpeed < targetSpeed)
        {
            currentSpeed = targetSpeed; // Hedef hıza aşırı geçişi önle
        }
    }

    printf("[IIndicatorSpeedStatus] Current speed: %u, Target speed: %u, Step: %u\n",
           currentSpeed, targetSpeed, speedStep);
}

İlk aşamada bu şekilde olacak daha sonra;
Adaptif Kademe artırma yönetemi kullanacagiz:
Fark büyüdükçe daha büyük adımlarla hızlanmak, 
fark azaldıkça daha küçük adımlarla hassasiyeti artırmak dinamik bir çözüm sağlar.

*/