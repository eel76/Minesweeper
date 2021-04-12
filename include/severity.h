#pragma once
#include "mines.h"

namespace minesweeper {
  Mines mined(Mines mines, Hazard hazard);
  bool isDeadly(Mines mines);
  bool isNegligible(Mines mines);
}
