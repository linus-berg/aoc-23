
#include "common.h"
#include<fstream>

std::vector<std::string> Common::GetFileContent(int day) {
  std::string path = "../inputs/" + std::to_string(day);
  std::ifstream file(path);
  std::string str;
  std::vector<std::string> vector;
  while (std::getline(file, str))
  {
    vector.push_back(str);
  }
  return std::move(vector);
}