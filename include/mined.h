#pragma once
#include "board.h"
#include "cell.h"

namespace minesweeper {
  // FIXME: plantBomb, layMine
  Board mined(Board board, Cell cell);
  Board mined(Board board, unsigned count);
}
