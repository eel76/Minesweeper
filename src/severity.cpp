#include "severity.h"

auto minesweeper::mined(Mines mines, Hazard hazard) -> Mines {
  mines[hazard]++;
  return mines;
}

auto minesweeper::isDeadly(Mines mines) -> bool {
  return mines[Hazard::Deadly] != 0;
}

auto minesweeper::isNegligible(Mines mines) -> bool {
  return mines.empty();
}
