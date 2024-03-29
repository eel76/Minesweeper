#include "columns.h"

#include <algorithm>

auto minesweeper::generateColumns(unsigned count) -> Columns {
  auto columns = Columns{ count };
  generate(begin(columns), end(columns),
           [index = 0]() mutable { return static_cast<Column>(index++); });

  return columns;
}
