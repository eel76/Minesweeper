#include "mined.h"
#include "player/choose.h"
#include "player/play.h"
#include "preparation.h"

using namespace minesweeper;

int main() {
  auto const rows    = generateRows(9);
  auto const columns = generateColumns(9);
  auto const board   = generateBoard(rows, columns);

  player::play(player::choose(), mined(board, 10));
}
