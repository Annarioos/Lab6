#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <math.h>
#include <locale.h>

int n1();
int n2();
int n3();

int n1()
{
    int years;

    printf("Введите год: ");
    scanf("%d", &years);
    if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0))
    {
        printf("Год %d високосный\n", years);
    }
    else
    {
        printf("Год %d не високосный\n", years);
    }

    return 0;
}

int n2()
{
    double x;
    printf("\nВведите x: ");
    scanf("%lf", &x);

    printf("F(%.2f) = %.6f\n", x,
        (x >= 0.0 && x <= 1.0) ? (x * x - x) : (x * x - sin(M_PI * x * x)));
    return 0;
}

int n3()
{
    int number;
    printf("\nВариант 9 ");
    printf("\nВведите четырехзначное число: ");
    if (scanf("%d", &number) != 1 || number < 1000 || number > 9999)
    {
        printf("введено не четырехзначное число.\n");
        return 0;
    }

    int ed = number % 10;
    int dec = (number / 10) % 10;
    int sot = (number / 100) % 10;
    int thousands = number / 1000;

    if (ed % 2 == 0) printf("число единиц - четное\n");
    if (dec % 2 == 0) printf("число десятков - четное\n");
    if (sot % 2 == 0) printf("число сотен - четное\n");
    if (thousands % 2 == 0) printf("число тысяч - четное\n");

    return 0;
}

int main()
{
    setlocale(LC_ALL, ".UTF8");
    n1();
    n2();
    n3();
    return 0;
}