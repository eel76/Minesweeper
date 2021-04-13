#include "mined.h"
#include "choose.h"
#include "play.h"
#include "preparation.h"

using namespace minesweeper;

int main() {
  auto const rows    = generateRows(9);
  auto const columns = generateColumns(9);
  auto const board   = generateBoard(rows, columns);

  play(choose(), mined(board, 10));
}
