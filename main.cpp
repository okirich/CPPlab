#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include "./headers/splitFunc.h"
#include "./headers/car.h"
#include "./headers/Colors.h"

const std::string filePath = "C:\\Users\\Kirill\\Documents\\CarFinder";
const std::string fileName = "cars.txt";
const std::string fileOut = "filtred.txt";

std::vector<Car> data;
std::vector<std::function<bool(Car)>> filter;

//функция которая применяет фильтры к вектору элементов
const std::vector<Car> findCar(const std::vector<Car> &carVect,\
                               std::vector<std::function<bool(Car)>> &funcVect){
    std::vector<Car> filtred = carVect;
    for (auto it = filtred.begin(); it != filtred.end();++it){
        for(auto func : funcVect){
            if (!func(*it)){
                filtred.erase(it);
                --it;
                break;
            }
        }
    }
    return filtred;
};

//функции фильтрации

bool colorFilter(Car);
bool yearFilter(Car);

int main()
{
    std::string str_buff;
    std::string str_out;
    // открытие файа на чтение (создается файловый поток)
    std::ifstream fin(filePath + '\\' + fileName);
    if (!fin.is_open()){
        std::cout << "Couldn't open file!" << std::endl;
    }
    while (std::getline(fin,str_buff)){
        // демонстрация работы исправленного split
        auto tokens = split(str_buff, ';');
        // создаем экземпляр класса машины
        Car *ptr = new Car(std::stoi(tokens[0]),tokens[1],\
                std::stoi(tokens[2]),std::stoi(tokens[3]));
        data.push_back(*ptr);
        for (auto s : tokens){
            str_out += s  + ' ';
        }
        str_out.erase(str_out.length()-1,2);
        std::cout << str_out;
        std::cout << std::endl;
        str_out.clear();
    }
    //вызываем ф-ю сортировки
    std::sort(data.begin(),data.end());
    for(auto it = data.begin(); it != data.end(); ++it){
        std::cout << *it << std::endl;
    }
    //открытие файла записи
    std::ofstream fout(filePath + '\\' + fileOut);
    if (!fout.is_open()){
        std::cout << "Couldn't create file!" << std::endl;
    }
    //вызов ф-ии фильтрации
    filter.emplace_back(colorFilter);
    filter.emplace_back(yearFilter);
    for (auto s : findCar(data,filter)){
        fout << s << std::endl;
    }
    return 0;
}
