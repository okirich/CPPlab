#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <vector>
#include "../headers/car.h"
#include "../headers/splitFunc.h"

struct query
{
    int id = -1;
    std::string model = "";
    int color = -1;
    int year = -1;
};

void setReqvParam(query&, std::string);

#endif // QUERY_H
