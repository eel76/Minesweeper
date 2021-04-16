#pragma once
#include "cells.h"

namespace minesweeper {
  auto neighborsOf(Cell cell, Board const& board) -> Cells;
}
