#include "preparation.h"
#include "combos.h"

auto minesweeper::generateBoard(Rows rows, Columns columns) -> Board {
  auto board = Board{};

  for (auto position : generatePositions(rows, columns))
    board[position] = Threat{};

  return board;
}
