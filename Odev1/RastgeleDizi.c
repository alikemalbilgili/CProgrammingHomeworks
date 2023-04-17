#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    // random gelen sayıların sürekli aynı gelmemesi için çalıştırılan kod satırı
    srand(time(NULL));
    // 20 elemanlı dizi tanımlaması
    int dizi[20];
    // 20 elemanı diziyi tek tek dönecek olan for döngüsü
    for (int i = 0; i < 20; i++)
        // dizinin dönülen elemanına 0 la 200 arasında bir değer atayan kod satırı
        dizi[i] = rand() % 200;

    // switch case yapısında seçim yaptırmak için kullanacağımız değişken
    int sec;
    // kullanıcı programdan çıkmak istediğinde kullanılacak olan bool eleman sadece 0 veya 1 almalı
    int ciktiMi = 0;
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
        printf("1)Dizinin istenilen elemanini gosterme\n"
               "2)Dizinin istenen araliklarini elemanlarini listeleme\n"
               "3)Dizinin istenen elemanini değerini değiştiren\n"
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
        // aşşağıdaki işlemlerde kullanılmak üzere tanımlanan değişkenler
        int n, j, k, l;
        // sec değişkenini bağlı olarak kullanıcının seçim yaptığı caseye giden yapı
        switch (sec)
        {
            // Kullanıcının Dizinin istenilen elemanini gosterme seçtiğinde çalışacak olan case
        case 1:

            printf("Dizinin gormek istediginiz elemanini yaziniz: ");
            scanf("%d", &n);
            // alınan n elmanına bağlı olarak dizideki elemanı gösteren kod
            printf("\nDizinin %d inci elemanini = %d", n, dizi[n - 1]);
            printf("\n\n");
            break;
        // Kullanıcının Dizinin belirlenen aralığı göstermek istediğinde çalışacak olan case
        case 2:
            printf("Gormek istediginiz araligin kacinci elemandan basliyacagini yaziniz: ");
            scanf("%d", &j);
            printf("Gormek istediginiz araligin kacinci elemanda bitecegini yaziniz: ");
            scanf("%d", &k);
            // Alınan değerler aralığında bir for döngüsü oluşturup dizinin bu kısmını dönen döngü
            for (j; j - 1 < k; j++)
            {
                // burda da j-1 yapılmasının nedeni indexin 0 dan başlamasından dolayı
                printf("Dizinin %d inci elemanini = %d\n", j, dizi[j - 1]);
            }
            printf("\n");
            break;
        // Kullanıcının Dizinin istenilen elemanini degistirmek istediğinde çalışacak olan case
        case 3:
            // Değiştirmek istenen elemanın sırasını alan kod bloğu
            printf("Dizinin kacinci  elemanini degistirmek istiyorsunuz: ");
            scanf("%d", &n);
            // Değiştirmek istenen elemanın yeni değerini alan kod bloğu
            printf("\nDizinin %d inci elemanini = %d\n", n, dizi[n - 1]);
            printf("Bu elemanin yeni degeri kac olsun :");
            scanf("%d", &l);
            // index 0 dan başladığı için n-1 yapmak zorundayız n-1 indexli elemanı yeni alınan l değerine eşitleyen kod bloğu
            dizi[n - 1] = l;
            printf("\n\n");
            break;
        // Kullanıcının çıkış yapmak istediğinde çalışacak olan case
        case 4:
            // ciktiMi değişkeni 1 yapıldığında while döngüsü son bulup program kapanacaktır
            ciktiMi = 1;
            break;
        // Kullanıcı hatalı giriş yaptığında çalışacak olan kod bloğu
        default:
            printf("\nHatali tuslama yaptiniz. Lutfen menuleri numaraya gore girdiginize emin olunuz \n!");
            /*Kullanıcı herhangi bir karakter string veya sembol girdiğinde scanf methoduna  gitmiyordu  ve bu yüzden
            döngü sürekli çalışarak hata veriyordu bunun çözümü olarak https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c
            aşşağıda kod bloğunu kullanarak kullanıcının inputunu temizleyen kodu aldım*/
            while ((sec = getchar()) != '\n' && sec != EOF)
            {
            }
            break;
        }
    }

    return 0;
}