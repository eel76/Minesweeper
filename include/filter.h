#pragma once
#include "cells.h"

#include <functional>

namespace minesweeper {
  using Filter = std::function<bool(Cell)>;
  auto not (Filter test) -> Filter;
  auto select (Filter test, Cells cells) -> Cells;
}
