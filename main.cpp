#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "filter.h"


int main(){
     std::ifstream file("ip_filter.tsv");
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    auto ip_pool = parse(lines);
    auto first = firstbit(ip_pool); 
    auto firstandsecond = firstandsecondbit(ip_pool); 
    auto any = anybit(ip_pool);

    print(ip_pool);
    print(first);
    print(firstandsecond);
    print(any);

    return 0;
}