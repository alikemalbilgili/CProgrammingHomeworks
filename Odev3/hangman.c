#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global değişkenler
char city[50];
char guessed_letters[40];
char guessedChar[] = "";
int rnd;
int length;
int attempts = 10;

// Fonksiyon Tanimlari
void get_input();
void print_blanks();
void hang_man();
void get_random_city();

int main(void)
{
    // random sehir getir
    get_random_city();

    // getirlen sehrin kelime uzunlugunu al ve
    length = strlen(city);
    // ilk basta bos olan bu degisken kullanici tahmin ettikce dolacaktir
    memset(guessed_letters, 0, sizeof guessed_letters);
    // deneme sayimiz
    attempts = 10;
    // deneme hakkimiz bitene kadar calisan dongu
    while (attempts > 0)
    {
        system("clear");

        // eger tum harfleri bililerse while dongusunden cik degilse diger kod bloguna gir
        if (strlen(guessed_letters) == length)
        {
            // alttaki tahmin cizgilerini yazmaya yarayan program
            print_blanks();
            // donguden cik
            break;
        }
        // d
        else
        {
            // kalan hak sayisini yazan program
            printf("Attempts Remaining: %i\n", attempts);
            // adam asma animasyonu cagiran ve alt cizgileri ekleyen yer
            print_blanks();
            // kullanicidan giris al deneme saysini azalt
            get_input();
        }
    }

    system("clear");

    // Eger kullanici yenerse
    if (attempts > 0)
    {
        // adam asma animasyonu cagiran ve alt cizgileri ekleyen yer
        print_blanks();
        printf("You Won!\n");
    }
    // eger kaybederse
    else
    {
        // adam asma animasyonunu cagiran blok
        hang_man();
        printf("You Lost! The city was %s, Play again?\n", city);
    }
}

void get_input()
{
    // kullanicidan input al ve kontrol et

    int i;
    // Kullanici harfi bildi mi bilmedi mi kontrol eden program
    int isFind = 0;
    // tahmini al
    printf("\nYour guess: \n");
    scanf(" %c", guessedChar);

    for (i = 0; i < length; i++)
    {
        // eger tahmin sehrin herhangi bir harfiyle uyusuyosa sadece o indexe harfi ata bu sayede harflerin hangi konumlarda oldugunu goruyoruz
        if (guessedChar[0] == city[i])
        {
            guessed_letters[i] = guessedChar[0];
            // kullanici dogur bildigi icin true yap
            isFind = 1;
        }
    }

    if (isFind)
    {
        return;
    }
    else
    {
        // bilemediyse azalt
        attempts--;
    }
}

void print_blanks()
{
    int i, j;

    // adam asma animasyonunu getiren blog
    hang_man();
    // tahmin edilen karakterleri dogru sirayla yazan yer
    for (i = 0; i < length; i++)
    {
        printf("%c", guessed_letters[i]);
        printf(" ");
    }
    printf("\n");

    // kelime uzunluguna gore  _ isareti koyan blok
    for (j = 0; j < length; j++)
    {
        printf("_");
        printf(" ");
    }
    printf("\n");
}
void get_random_city()
{
    // dizi tanimlamasi
    char *cities[10] = {"istanbul", "ankara", "izmir", "bursa", "antalya", "adana", "konya", "gaziantep", "kayseri", "mersin"};
    srand(time(NULL));
    // rastgele sehir secmek icin yazilan ve bunu city degiskenine atan kod blogu
    rnd = rand() % 10;
    strcpy(city, cities[rnd]);
}

void hang_man()
{
    // adam asma animasyonu
    char *area[] = {

        "      ===\n",

        "        |\n"
        "        |\n"
        "        |\n"
        "       ===\n",

        "   =====|\n"
        "        |\n"
        "        |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "        |\n"
        "        |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        "        |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        "  |     |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        "  |-    |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        " -|-    |\n"
        "        |\n"
        "       ===\n",

        "  |=====|\n"
        "  O     |\n"
        " -|-    |\n"
        "  |     |\n"
        "       ===\n",

        "   |=====|\n"
        "   O     |\n"
        "  -|-    |\n"
        "  //     |\n"
        "       ===\n"

    };

    // hangi animasyomnun gosterilecegine karar veren yapi
    if (attempts >= 0 && attempts <= 9)
    {
        printf("\n\n%s\n", area[9 - attempts]);
    }
}
