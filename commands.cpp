#include <iostream>

#include "commands.h"

void commands::init() {
  std::string command;
  std::cin >> command;
  std::cout << command[3] << "\n";
}
