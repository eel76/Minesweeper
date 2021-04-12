#pragma once
#include "column.h"

#include <vector>

namespace minesweeper {
  using Columns = std::vector<Column>;
  auto generateColumns(unsigned count) -> Columns;
}