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
    query& operator=(const query &n);
    bool operator== (const query &n);
};

void setReqvParam(query&, std::string);
void getRequest(std::vector<Car>&,query&);

const query DEFAULT_QUERY;

#endif // QUERY_H
