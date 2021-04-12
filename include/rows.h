#pragma once
#include "row.h"

#include <vector>

namespace minesweeper {
  using Rows = std::vector<Row>;
  auto generateRows(unsigned count) -> Rows;
}
