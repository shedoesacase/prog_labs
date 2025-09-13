#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "filter.h"

std::vector<std::string> split(const std::string &str, char d) //из файла функция для сплита до табуляции и до точки
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

std::vector<std::vector<int>> parse(const std::vector<std::string> ips){ //функция для превращения строки в инт
    std::vector<std::vector<int>> pool;

    for(auto &line : ips){
        auto part = split(line, '\t');
        auto ip_str = part[0];
        auto num = split(ip_str, '.');

        std::vector<int> ip = {
            std::stoi(num[0]),
            std::stoi(num[1]),
            std::stoi(num[2]),
            std::stoi(num[3])
        };

        pool.push_back(ip);
    }

    std::sort(pool.begin(), pool.end(), [](const std::vector<int> &a, const std::vector<int> &b){
        for(int i=0; i<4; ++i){
            if(a[i] != b[i]) return a[i] > b[i];
        }
        return false;
    });

    return pool;
}

std::vector<std::vector<int>> firstbit(std::vector<std::vector<int>> &v){
    std::vector<std::vector<int>> first;
    for(const auto &r : v){
        if(r[0] == 1){
            first.push_back(r);
        }
    }
    return first;
}

std::vector<std::vector<int>> firstandsecondbit(std::vector<std::vector<int>> &v){
    std::vector<std::vector<int>> first;
    for(const auto &r : v){
        if(r[0] == 46 && r[1] == 70){
            first.push_back(r);
        }
    }
    return first;
}

std::vector<std::vector<int>> anybit(std::vector<std::vector<int>> &v){
    std::vector<std::vector<int>> first;
    for(const auto &r : v){
        if(r[0] == 46 || r[1] == 46 || r[2] == 46 || r[3] == 46){
            first.push_back(r);
        }
    }
    return first;
}

void print(std::vector<std::vector<int>> &v){
    for(const auto &r : v){
        for(size_t i = 0; i < 4; ++i){
            std::cout << r[i];
            if(i < r.size() -1 ) std::cout << ".";
        }
        std::cout << std::endl;
    }
}
