#pragma once
#include "console/getline.h"
#include "console/print.h"

namespace minesweeper::console {
  inline std::string ask(std::string const& question) {
    print(question);
    return getline();
  }
}
