#include "player/human.h"

#include "console/ask.h"
#include "move/parse.h"

using namespace std::string_literals;

auto minesweeper::player::human() -> Player {
  return [](auto) {
    return move::parse(console::ask("Your move: [(m)ark] <row> <column>: "s));
  };
}
