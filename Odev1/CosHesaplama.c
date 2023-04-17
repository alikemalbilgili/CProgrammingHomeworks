#include <stdio.h>
// Üs almak ve cos değerini hesaplamak için gereken kütüphane
#include <math.h>

int main()
{
    // Taylor serisine göre derece cinsinden girilen bir değeri radyana çevirmeliyiz bu yüzden pi sayısı tanımlıyoruz.
    const double PI = 3.14;
    // Kullanıcıdan input alma
    double x;
    printf("Lutfen hesaplamak istediginiz x degerini giriniz: ");
    scanf("%lf", &x);
    // Burdaki n değeri taylor serisinde kaç terimi alcağını söylüyor çok büyük tutarsak faktoriyel çok büyüyor o yüzden 8 aldık.
    int n = 8;
    // Faktoriyel 1 ile başlayıp kendine çarpılıp kendine eşitlenecek
    long faktoriyel = 1;
    // Seriye göre ilk üs 2 den başladığı için böyle tanımladık
    long us = 2;
    // Derece radyan dönüşümü yapılıyor
    x = x * PI / 180;
    // Terimlerin toplamı burda saklanıyor ilk terim 1 olduğu ve değişkeni olmadığı için onu direkt olarak toplama ekliyoruz.
    long double toplam = 1;
    // Burda aynı değeri math kütüphanesiyle de hesaplıyoruz sonuçları karşılaştırmak için.
    double cosDegeri = cos(x);
    // Sonuç depişkenini tanımlama
    double sonuc;
    // taylor serisindeki terimleri n değerini kullanarak  5 taneyle sınırladık bu döngü sadece 5 terim için dönecek
    for (int i = 0; i < n; i++)
    {
        // Faktoriyel hesapladığımız kısım
        faktoriyel = faktoriyel * (us - 1) * us;
        // burdaki pow üs almaya yarıyor -1 ile üs alınca terimler bir negatif bir pozitif olarak çarpılıyor
        // diğer üs alma ve faktoriyel hesaplaması formüle göre uygulanıyor
        sonuc = (pow(-1, i + 1)) * (pow(x, us) / (2 * faktoriyel));
        // her bir terim toplam değişkeninde toplanıyor
        toplam = toplam + sonuc;
        // üstler formüle uygun olarak çift artıyor.
        us = us + 2;
    }
    // Formülden ve kütüphanedeki sonucu yazdırma
    printf("Taylor Sonuc: %Lf \n", toplam);
    printf("Cos(x) Sonuc: %f ", cosDegeri);
    return 0;
}
