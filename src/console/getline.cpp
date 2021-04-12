#include "console/getline.h"

#include <iostream>

auto minesweeper::console::getline() -> std::string {
  auto line = std::string{};
  getline(std::cin, line);

  return line;
}
