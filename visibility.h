#pragma once

namespace minesweeper {
  enum struct State { Concealed, Marked, Revealed };
  State reveal(State state);
  State changeMark(State state);
}
