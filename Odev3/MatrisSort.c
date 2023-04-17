    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    #define SIZE 10

    // rastgele sayilarla matris olusturan fonksiyon
    void generate_matrix(int matrix[SIZE][SIZE]);
    // matrisi ekrana yazan fonskiyon
    void print_matrix(int matrix[SIZE][SIZE]);
    // satirlari siralayan fonskiyon
    void sort_rows(int matrix[SIZE][SIZE], int ascending);
    // kolonlari siralayan fonskiyon
    void sort_columns(int matrix[SIZE][SIZE], int ascending);
    // satir veya sutunlari azalan veya artan siraya gore karsilastiran fonskiyonlar
    int compare(const void *a, const void *b);
    int compare_desc(const void *a, const void *b);

    int main()
    {
        // matrix tanimimiz
        int matrix[SIZE][SIZE];
        // artan mi azalan mi icin kullanacagimiz fonskiyon
        int order;

        srand(time(NULL));
        // rastgele sayilarla matris olusturan fonksiyon
        generate_matrix(matrix);

        // matrisi ekrana yazdir
        printf("Generated matrix:\n");
        print_matrix(matrix);

        // matrisin artan olarak mi azalan olarak mi secilmesine yarayan fonskiyon
        printf("Choose sorting order:\n");
        printf("1. Ascending\n");
        printf("2. Descending\n");
        scanf("%d", &order);

        // burda order==1 degeri 0 veya 1 dondurecektir buna gore siralama yapiliyor ve ekrana yaziliyor
        sort_columns(matrix, order == 1);
        sort_rows(matrix, order == 1);

        printf("Sorted matrix:\n");
        print_matrix(matrix);

        return 0;
    }

    void generate_matrix(int matrix[SIZE][SIZE])
    {
        // 100 ile 500 arasinda olusturlan rastgele sayilari matrise atayan dongu
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                matrix[i][j] = rand() % 401 + 100;
            }
        }
    }

    void print_matrix(int matrix[SIZE][SIZE])
    {
        // matrisi sirasiyla duzgun bir sekilde ekrana yazan dognu
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }

    void sort_rows(int matrix[SIZE][SIZE], int ascending)
    {
        // burda stdlibin icindeki qsort fonksiyonunu kullanarak siralama yaptim ordaki yonergelere gore assagida iki tane degisken tanimladim
        for (int i = 0; i < SIZE; i++)
        {
            qsort(matrix[i], SIZE, sizeof(int), ascending ? compare : compare_desc);
        }
    }

    void sort_columns(int matrix[SIZE][SIZE], int ascending)
    {
        // her bir kolonu ayni yontemle donen ve esitleyen donguler
        for (int i = 0; i < SIZE; i++)
        {
            int column[SIZE];
            for (int j = 0; j < SIZE; j++)
            {
                column[j] = matrix[j][i];
            }
            qsort(column, SIZE, sizeof(int), ascending ? compare : compare_desc);
            for (int j = 0; j < SIZE; j++)
            {
                matrix[j][i] = column[j];
            }
        }
    }

    // bu qsort a gore artan tam sayi olarak karsilastir demek
    int compare(const void *a, const void *b)
    {
        return (*(int *)a - *(int *)b);
    }

    // buda azalan tam sayi olarak karsilastir demek
    int compare_desc(const void *a, const void *b)
    {
        return (*(int *)b - *(int *)a);
    }