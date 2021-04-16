#include "choose.h"

#include "ask.h"
#include "computer.h"
#include "human.h"

using namespace std::string_literals;

auto minesweeper::choosePlayer() -> Player {
  using Players = std::map<std::string, Player>;
  auto players  = Players{ { "h"s, human() }, { "c"s, computer() } };
  auto player   = Player{};

  while (!player)
    player = players[ask("Player: (h)uman or (c)omputer? "s)];

  return player;
}
