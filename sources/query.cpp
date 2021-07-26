#include "../headers/query.h"

bool colorFilter(Car c1, int color)
{
    return c1.getColor() == color;
}

bool yearFilter(Car c1, int year)
{
    return c1.getYear() <= year;
}

bool modelFilter(Car c1, std::string model)
{
    return c1.getModel() == model;
}

void setReqvParam(query& reqv, std::string query)
{
    std::vector<std::string> queryTkn = split(query,' ');
    for (auto it = queryTkn.begin(); it != queryTkn.end();++it)
    {
        if (it->compare("<id>")==0)
        {
            reqv.id = std::stoi(*++it);
        }
        else if (it->compare("<model>")==0)
        {
            reqv.model = *++it;
        }
//       else if (it->compare("<color>")==0)
//        {
//            reqv.model = std::stoi(*++it);
//        }
        else if (it->compare("<year>")==0)
        {
            reqv.year = std::stoi(*++it);
        }
        else
        {
            reqv.id = -1;
            reqv.model = "";
            reqv.color = -1;
            reqv.year = -1;
        }
    }
}
