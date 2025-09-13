#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str, char d);
std::vector<std::vector<int>> parse(const std::vector<std::string> ips);
void print(std::vector<std::vector<int>> &v);
std::vector<std::vector<int>> firstbit(std::vector<std::vector<int>> &v);
std::vector<std::vector<int>> firstandsecondbit(std::vector<std::vector<int>> &v);
std::vector<std::vector<int>> anybit(std::vector<std::vector<int>> &v);