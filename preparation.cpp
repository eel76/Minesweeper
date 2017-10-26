#include "preparation.h"
#include "combos.h"

minesweeper::Board minesweeper::setupBoard(Rows rows, Columns columns) {
  auto board = Board{};

  for (auto position : allCombos(rows, columns))
    board[position] = Threat{};

  return board;
}
