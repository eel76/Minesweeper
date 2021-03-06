#include "state.h"
#include <map>

auto minesweeper::reveal(State state) -> State {
  using Revealed = std::map<State, State>;
  return Revealed{ { State::Concealed, State::Revealed },
                   { State::Marked, State::Marked },
                   { State::Revealed, State::Revealed } }[state];
}

auto minesweeper::mark(State state) -> State {
  using Marked = std::map<State, State>;
  return Marked{ { State::Concealed, State::Marked },
                 { State::Marked, State::Concealed },
                 { State::Revealed, State::Revealed } }[state];
}

auto minesweeper::isRevealed(State state) -> bool {
  return state == State::Revealed;
}

