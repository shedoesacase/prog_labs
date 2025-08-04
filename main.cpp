#include <iostream>
#include "version.h"

int main() {
    std::cout << "Hello, World! Version " << VERSION_MAJOR << '.' << VERSION_MINOR << '.' << VERSION_PATCH << std::endl; //2 push
    return 0;
}