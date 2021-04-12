#pragma once
#include "only.h"

namespace minesweeper {
  inline auto concealed(Cells cells) -> Cells {
    return select(only(State::Concealed), cells);
  }
}
