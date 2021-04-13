#include "human.h"

#include "ask.h"
#include "move/parse.h"

using namespace std::string_literals;

auto minesweeper::human() -> Player {
  return [](auto) {
    return move::parse(ask("Your move: [(m)ark] <row> <column>: "s));
  };
}
