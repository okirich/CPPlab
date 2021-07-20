#include "../headers/car.h"

bool colorFilter(Car c1)
{
    return c1.getColor() == 1;
}

bool yearFilter(Car c1)
{
    return c1.getYear() <= 2017;
}
