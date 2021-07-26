#include "../headers/query.h"

query& query::operator=(const query &n)
{
    this->id = n.id;
    this->model = n.model;
    this->color = n.color;
    this->year = n.year;
    return *this;
}

bool query::operator==(const query &n)
{
    if (this->id == n.id && this->model == n.model && \
            this->color == n.color && this->year == n.year)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool idFilter(Car c1, int id)
{
    return c1.getId() == id;
}

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
    if (query.compare("")==0)
    {
        reqv = DEFAULT_QUERY;
    }
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
       else if (it->compare("<color>")==0)
        {
            reqv.model = std::stoi(*++it);
        }
        else if (it->compare("<year>")==0)
        {
            reqv.year = std::stoi(*++it);
        }
        else
        {
            reqv = DEFAULT_QUERY;
        }
    }
}

void getRequest(std::vector<Car>& cars,query& reqv)
{
    if (reqv.id != -1)
    {
        for(auto it = cars.begin();it != cars.end();++it){
            if(!idFilter(*it,reqv.id))
            {
                cars.erase(it);
                --it;
            }
        }
    }
    if (reqv.model != "")
    {
        for(auto it = cars.begin();it != cars.end();++it){
            if(!modelFilter(*it,reqv.model))
            {
                cars.erase(it);
                --it;
            }
        }
    }
    if (reqv.color != -1)
    {
        for(auto it = cars.begin();it != cars.end();++it){
            if(!colorFilter(*it,reqv.color))
            {
                cars.erase(it);
                --it;
            }
        }
    }
    if (reqv.year != -1)
    {
        for(auto it = cars.begin();it != cars.end();++it){
            if(!yearFilter(*it,reqv.year))
            {
                cars.erase(it);
                --it;
            }
        }
    }
}
