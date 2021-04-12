#pragma once
#include "columns.h"
#include "positions.h"
#include "rows.h"

namespace minesweeper {
  Positions generatePositions(Rows rows, Columns columns);
}
