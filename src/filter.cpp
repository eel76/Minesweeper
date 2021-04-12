#include "filter.h"

#include <algorithm>

auto minesweeper::not(Filter test) -> Filter {
  return [=](auto cell) { return !test(cell); };
}

auto minesweeper::select(Filter test, Cells cells) -> Cells {
  cells.erase(std::remove_if(begin(cells), end(cells), not (test)), end(cells));
  return cells;
}
