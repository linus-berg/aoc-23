#include <iostream>
#include "utils/common.h"
#include "days/Day2/Day2.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Common common;

    std::vector<std::string> content = common.GetFileContent(2);
    Day2 d;
    int result = d.Run(content);
    return 0;
}
