#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <math.h>
#include <locale.h>

int n1(int years);
double n2(double x);
int n3(int number, int* ed_e, int* dec_e, int* sot_e, int* thousands_e);

int main()
{
    setlocale(LC_ALL, ".UTF8");

    int years;
    printf("Введите год: ");
    if (scanf("%d", &years) == 1)
    {
        int l = n1(years);
        if (l)
        {
            printf("Год %d високосный\n", years);
        }
        else
        {
            printf("Год %d не високосный\n", years);
        }
    }

    double x;
    printf("\nВведите x: ");
    if (scanf("%lf", &x) == 1)
    {
        double fx = n2(x);
        printf("F(%.2f) = %.6f\n", x, fx);
    }

    int number;
    printf("\nВариант 9\n");
    printf("Введите четырехзначное число: ");
    if (scanf("%d", &number) != 1 || number < 1000 || number > 9999)
    {
        printf("введено не четырехзначное число.\n");
    }
    else
    {
        int ed_e = 0, dec_e = 0, sot_e = 0, thousands_e = 0;

        n3(number, &ed_e, &dec_e, &sot_e, &thousands_e);

        if (ed_e) printf("число единиц - четное\n");
        if (dec_e) printf("число десятков - четное\n");
        if (sot_e) printf("число сотен - четное\n");
        if (thousands_e) printf("число тысяч - четное\n");
    }

    return 0;
}

int n1(int years)
{
    if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0))
    {
        return 1;
    }
    return 0;
}

double n2(double x)
{
    return (x >= 0.0 && x <= 1.0) ? (x * x - x) : (x * x - sin(M_PI * x * x));
}

int n3(int number, int* ed_e, int* dec_e, int* sot_e, int* thousands_e)
{
    int ed = number % 10;
    int dec = (number / 10) % 10;
    int sot = (number / 100) % 10;
    int thousands = number / 1000;

    if (ed % 2 == 0) *ed_e = 1;
    if (dec % 2 == 0) *dec_e = 1;
    if (sot % 2 == 0) *sot_e = 1;
    if (thousands % 2 == 0) *thousands_e = 1;

    return 0;
}
