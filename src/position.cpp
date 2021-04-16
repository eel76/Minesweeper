#include "position.h"

#include <algorithm>

auto minesweeper::row(Position position) -> Row {
  return std::get<Row>(position);
}

auto minesweeper::column(Position position) -> Column {
  return std::get<Column>(position);
}
