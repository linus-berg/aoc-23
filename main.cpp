#include <iostream>
#include "utils/common.h"
#include "days/1.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Common common;

    std::vector<std::string> content = common.GetFileContent(1);


    Day1 d;
    d.Run(content);

    return 0;
}
