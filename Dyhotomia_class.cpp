
#include "Dyhotomia_class.h"
#include <cmath>

Dyhotomia_class::Dyhotomia_class()
{
}

Dyhotomia_class::~Dyhotomia_class()
{
}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b)
{
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps)
{
    eps = vol_eps;
}

double Dyhotomia_class::f(double x)
{
    return x + sqrt(x) + pow(x, 1.0 / 3.0) - 2.5;
}

int Dyhotomia_class::countDyhotomia(double &x)
{
    double left = a;
    double right = b;
    double c;

    // Перевіряємо, чи є зміна знаку на кінцях проміжку.
    if (f(left) * f(right) > 0)
    {
        return -1;
    }

    // Поступово звужуємо проміжок, де знаходиться корінь.
    while (fabs(right - left) > eps)
    {
        c = (left + right) / 2.0;

        // Вибираємо ту половину відрізка, де є корінь.
        if (f(left) * f(c) < 0)
        {
            right = c;
        }
        else
        {
            left = c;
        }
    }

    x = (left + right) / 2.0;
    return 0;
}

int Dyhotomia_class::countNewton(double &x)
{
    double x_next;
    double h = 0.00001;
    double derivative;

    // За умовою стартуємо з правої межі проміжку.
    x = b;

    while (true)
    {
        // Похідну рахуємо чисельно через малий приріст.
        derivative = (f(x + h) - f(x)) / h;

        if (derivative == 0)
        {
            return -1;
        }

        x_next = x - f(x) / derivative;

        // Якщо сусідні наближення майже однакові, зупиняємось.
        if (fabs(x_next - x) < eps)
        {
            x = x_next;
            return 0;
        }

        x = x_next;
    }
}
