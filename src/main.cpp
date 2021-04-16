#include "choose.h"
#include "mined.h"
#include "play.h"
#include "preparation.h"

using namespace minesweeper;

namespace {
  auto generateBoard() {
    auto const rows    = generateRows(20);
    auto const columns = generateColumns(20);
    auto const board   = generateBoard(rows, columns);

    return layMines(board, 50);
  }
}

int main() {
  play(choosePlayer(), generateBoard());
}
