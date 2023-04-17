#include <stdio.h>
#include <unistd.h>

int main()
{
    // Kullanıdan her bir boğumun uzunluğu n sayısı ile alınıyor diğer değişkenler for döngülerini kullanmak için.
    int n, i, j, k;
    printf("Lutfen bogum uzunlugunu giriniz: ");
    scanf("%d", &n);
    // Kullanıcıdan alınan veri başka bir değere daha eşitleniyor bu değer sağa doğru kaydırmak için kullanıılıyor
    int x = n;
    // animsayonumuzun sürekli devam etmesi için sonsuz döngü açıyoruz
    while (1)
    {

        // 3 kere bogum boğum yapmamıza yarayan for döngüsü
        for (k = 0; k < 3; k++)
        {
            // Boğumun uzunuğu kadar dönen for döngüsü
            for (int i = 1; i <= n; i++)
            {
                /* çam ağacı üçgeni için  satıra  boşluk ekleniyor ama bu tersten işliyor
                yani ilk satıra boğum uzunluğu kadar ekleniyor sonra birer birer azalıyor
                burda n değeri yerine x kullanılıyor çünkü x arttıkça boşluk ekleme artacak
                bu sayede ağaç boğumları kaymış olacak*/
                for (int j = 1; j <= x - i; j++)
                {
                    printf(" ");
                }
                /* burda  satıra 2n-1 formulu kullanarak "*" sembolu koyuluyor */
                for (j = 1; j <= 2 * i - 1; j++)
                {
                    printf("*");
                }
                // satırı aşşağı kaydıran kod
                printf("\n");
            }
        }
        // Ağacın gövdesini yapmaya yarayan for döngüsü
        for (i = 1; i <= n; i++)
        {
            // Burdada x kullanılmasının sebebi boşluk arttrıp sağa kaydrımak
            for (j = 1; j <= x - 2; j++)
            {
                printf(" ");
            }
            // Ağaç gövdesini 3 yıldızla yazıp aşşağı kaydıran kod
            printf("***\n");
        }
        // x değişkeni arttırıp boşluk sayısını arttırmış oluyoruz
        x++;
        // Bu döngü sürekli çalışırsa terminalde görüntü bozulcağından dolayı saniyede bir kere çalışmasını sağlayan kod
        sleep(1);
    }
    return 0;
}
