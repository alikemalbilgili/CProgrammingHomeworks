#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

void RastgeleDiziUret(int dizi[], int elemanSayisi, int baslangicDegeri, int bitisDegeri);
void DiziyiGoruntule(int dizi[], int n);
void DizininAraliklariniDegistir(int dizi[], int baslangic, int bitis);
float DizininOrtalamasiniAl(int dizi[], int n);

int main(void)
{
    srand(time(NULL));
    int n;
    int rastgeleAralikBaslangic;
    int rastgeleAralikBitis;
    printf("\nLutfen dizinin boyutunu giriniz: ");
    scanf("%d", &n);
    printf("\nLutfen rastgele sayi araliginin baslangicini giriniz: ");
    scanf("%d", &rastgeleAralikBaslangic);
    printf("\nLutfen rastgele sayi araliginin bitisini giriniz: ");
    scanf("%d", &rastgeleAralikBitis);

    int dizi[n];
    RastgeleDiziUret(dizi, n, rastgeleAralikBaslangic, rastgeleAralikBitis);

    // switch case yapısında seçim yaptırmak için kullanacağımız değişken
    int sec;
    // kullanıcı programdan çıkmak istediğinde kullanılacak olan bool eleman sadece 0 veya 1 almalı
    int ciktiMi = 0;
    int aralikBaslangic;
    int aralikbitis;
    float sonuc;
    // ciktiMi değişkeni 1 olmadığı sürece devam eden while döngüsü
    while (ciktiMi != 1)
    {
        // döngünün sürekli çalışıp yazıların aniden gitmemesi için terminali 1 saniye bekleten kod
        sleep(1);
        // menünün diğer yazılarla karışmaması için tire atan for döngüsü
        for (int x = 0; x < 50; x++)
        {
            printf("-");
        }
        printf("\n");
        printf("1)Dizinin elemanlarini gosterme\n"
               "2)Dizinin istenen araliklardaki elemanlarini degistirme\n"
               "3)Dizinin ortalamasini alma\n"
               "4)Programdan cikis.\n");
        // menünün diğer yazılarla karışmaması için tire atan for döngüsü
        for (int x = 0; x < 50; x++)
        {
            printf("-");
        }
        // Yapmak istediğimiz işlemi alan kod bloğu
        printf("\nLutfen yapmak istediginiz islemi seciniz: ");
        scanf(" %d", &sec);
        printf("");
        // sec değişkenini bağlı olarak kullanıcının seçim yaptığı caseye giden yapı
        switch (sec)
        {
            // Kullanıcının Dizinin elemanlarini görmesi için  çalışacak olan case
        case 1:
            DiziyiGoruntule(dizi, n);
            break;
        // Kullanıcının Dizinin belirli aralıkarını degistirmek istediğinde çalışacak olan case
        case 2:

            printf("\nLutfen aralik baslangicini giriniz: ");
            scanf("%d", &aralikBaslangic);
            printf("\nLutfen rastgele sayi aralik bitisini giriniz: ");
            scanf("%d", &aralikbitis);
            DizininAraliklariniDegistir(dizi, aralikBaslangic, aralikbitis);
            break;
        case 3:
            sonuc = DizininOrtalamasiniAl(dizi, n);
            printf("Dizinizin ortalamasi %f \n", sonuc);
            break;
        // Kullanıcının çıkış yapmak istediğinde çalışacak olan case
        case 4:
            // ciktiMi değişkeni 1 yapıldığında while döngüsü son bulup program kapanacaktır
            ciktiMi = 1;
            break;
        // Kullanıcı hatalı giriş yaptığında çalışacak olan kod bloğu
        default:
            printf("\nHatali tuslama yaptiniz. Lutfen menuleri numaraya gore girdiginize emin olunuz \n!");
            break;
        }
    }
    return 0;
}

// istenilen araliklarda rastgele sayi ureten fonskiyon
int RastgeleSayiUret(int aralikBaslangici, int aralikBitisi)
{

    return (rand() % (aralikBitisi - aralikBaslangici + 1)) + aralikBaslangici;
}
void RastgeleDiziUret(int dizi[], int elemanSayisi, int baslangicDegeri, int bitisDegeri)
{
    int temp;

    // Gelen random sayinin dizide bulunup bulunmadigini kontrol eden for dongusu
    for (int i = 0; i < elemanSayisi; i++)
    {
        temp = RastgeleSayiUret(baslangicDegeri, bitisDegeri);
        for (int j = 0; j < i; j++)
        {
            if (dizi[j] == temp)
            {
                temp = RastgeleSayiUret(baslangicDegeri, bitisDegeri);
                j = -1;
            }
        }
        dizi[i] = temp;
    }
}

// istenilen araliktaki elemanlari for dongusuyle tekrardan alan fonskiyon
void DizininAraliklariniDegistir(int dizi[], int baslangic, int bitis)
{
    for (int i = baslangic; i < bitis + 1; i++)
    {
        printf("\nLutfen %d inci elemanin yeni degerini giriniz: ", i);
        scanf("%d", &dizi[i - 1]);
    }
}
// Diziyi for dongusuyle gosteren fonksiyon
void DiziyiGoruntule(int dizi[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Dizinin %d ninci elemani = %d \n", i + 1, dizi[i]);
    }
}
// Dizinin tum elemanlarini for dongusuyle toplayip sonra eleman sayisina bolen float donduren fonskiyon
float DizininOrtalamasiniAl(int dizi[], int n)
{
    int toplam = 0;
    for (int i = 0; i < n; i++)
    {
        toplam += dizi[i];
    }
    return (float)toplam / n;
}
