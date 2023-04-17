#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void BogumYap(int bogumUzunlugu);
void GovdeYap(int govdeUzunlugu);
void AssagiHareketEttir(int bogumUzunlugu, int bogumSayisi, int sure);
void YukariHareketEttir(int bogumUzunlugu, int bogumSayisi, int sure);

int main()
{
    // Kullanici inputlari icin tanimlanan degiskenler
    int bogumUzunlugu;
    int bogumSayisi;
    int yon;
    int sure;

    // Kullanicidan inputlari alan kod blogu
    printf("Her bir bogumun ve kutugun uzunlugunu giriniz: ");
    scanf("%d", &bogumUzunlugu);
    printf("\nKac tane bogum olacagini giriniz: ");
    scanf("%d", &bogumSayisi);
    printf("\nAgacin nereye dogru hareket etcegini seciniz (1-Asagi 2-Yukari): ");
    scanf("%d", &yon);
    printf("\nHareketin kac saniye surecegini giriniz: ");
    scanf("%d", &sure);

    // kullanicinin secimlerine gore fonskiyonu calistiran kod blogu
    switch (yon)
    {
    case 1:
        AssagiHareketEttir(bogumUzunlugu, bogumSayisi, sure);
        break;
    case 2:
        YukariHareketEttir(bogumUzunlugu, bogumSayisi, sure);
        break;
    default:
        printf("\nHatali tuslama yaptiniz.");
        break;
    }

    return 0;
}

// Bu fonskiyonda for dongusu kullanilarak bir ucgen yapiliyor
void BogumYap(int bogumUzunlugu)
{
    int i, j;
    for (i = 1; i <= bogumUzunlugu; i++)
    {
        for (j = 1; j <= bogumUzunlugu - i; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

// Bu fonksiyonda for dongusu kullanilarak agacin govdesi yapiliyor
void GovdeYap(int govdeUzunlugu)
{
    int i, j;
    for (i = 0; i < govdeUzunlugu; i++)
    {
        for (j = 1; j < govdeUzunlugu - 1; j++)
        {
            printf(" ");
        }
        printf("****\n");
    }
}

// Agacimizi assagi hareket ettiren fonskiyon
void AssagiHareketEttir(int bogumUzunlugu, int bogumSayisi, int sure)
{
    int i = 0;
    while (i <= sure)
    {
        int j = sure;

        // Ilk basta agacimizi yapiyoruz
        for (int k = 0; k < bogumSayisi; k++)
        {
            BogumYap(bogumUzunlugu);
        }
        GovdeYap(bogumUzunlugu);

        i++;

        // assagiya git gide azalan bosluk ekleniyor bu sayede assaga gidiyormus efekti yaratiyor.
        while (j > i)
        {
            printf("\n");
            j--;
        }
        // Terminali bir saniye beklet
        sleep(1);
    }
}
// Agacimizi yukari hareket ettiren fonskiyon

void YukariHareketEttir(int bogumUzunlugu, int bogumSayisi, int sure)
{
    int i = 0;
    while (i <= sure)
    {
        printf("------------------------------------------------------------------------\n");
        int j = sure;

        // yukariya git gide azalan bosluk ekleniyor bu sayede yukari gidiyormus efekti yaratiyor.

        while (j > i)
        {
            printf("\n");
            j--;
        }

        // sonra da  agacimizi yapiyoruz

        for (int k = 0; k < bogumSayisi; k++)
        {
            BogumYap(bogumUzunlugu);
        }
        GovdeYap(bogumUzunlugu);

        i++;

        // Terminali bir saniye beklet
        sleep(1);
        // Terminali temizleyen kod
        system("clear");
    }
}
