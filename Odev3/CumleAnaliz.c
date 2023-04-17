#include <stdio.h>
#include <string.h>

//fonskiyon tanimlamalari
void KarakterHesapla( char input[100]);
void KelimeHesapla(char input[100]);
void SesliHarfHesapla(char input[100]);
void CumleHesapla(char input[100]);

int main()
{
    //kullanicidan girdi alan kisim
    char kullaniciGirdisi[100];
    printf("Lutfen metin giriniz:");
    fgets(kullaniciGirdisi, 100, stdin);
    printf("%s", kullaniciGirdisi);
    //sirayla fonskiyonlarimizi cagirdigimiz kisim
    KarakterHesapla(kullaniciGirdisi);
    SesliHarfHesapla(kullaniciGirdisi);
    CumleHesapla(kullaniciGirdisi);
    KelimeHesapla(kullaniciGirdisi);
    return 0;
}

void KarakterHesapla( char input[100])
{
  
  //gelen inputun gercek uzunlugunu buluyoruz
    int inputUzunlugu = strlen(input);
    //bosluksuz uzunlugu bulmak icin tanimladigimiz degisken
    int bosluksuzUzunluk = 0;
    char karakter;
    for (int i = 0; i < inputUzunlugu; i++)
    {
        karakter = input[i];
        if (karakter != ' ')
        {
            //eger bosluk yoksa karakteri arttir
            bosluksuzUzunluk++;
        }
    }
    printf("Karakter sayisi: %d\n", bosluksuzUzunluk);
}

void KelimeHesapla(char input[100])
{
    //kelime sayisini hesaplamak icn tanimlanan degisken
    int kelimeSayisi = 0;
    //kelimeyi bosluktan parcala ve token degiskenine at 
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        //her boslugu parcaladiginda kelime saysisi artiyor
        kelimeSayisi++;
        token = strtok(NULL, " ");
    }
    printf("Kelime sayisi: %d\n", kelimeSayisi);
}

void SesliHarfHesapla(char input[100])
{
    //sesli harf  sayisini hesaplamak icn tanimlanan degisken
    int sesliHarfSayisi = 0;
    int inputUzunlugu = strlen(input);

    for (int i = 0; i < inputUzunlugu; i++)
    {
        //eger sesli harf varsa sesli harf saysiini bir arttir
        char ch = input[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            sesliHarfSayisi++;
        }
    }
    printf("Sesli harf sayisi: %d\n", sesliHarfSayisi);
}

void CumleHesapla(char input[100])
{
    int cumleSayisi = 0;
    int inputUzunlugu = strlen(input);
    for (int i = 0; i < inputUzunlugu; i++)
    {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            cumleSayisi++;
        }
    }
    printf("Cumle sayisi: %d\n", cumleSayisi);
}
