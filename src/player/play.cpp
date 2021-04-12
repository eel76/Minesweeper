#include "player/play.h"

#include "console/ask.h"
#include "cells.h"
#include "deadly.h"
#include "group.h"
#include "marked.h"
#include "reveal.h"
#include "to_string.h"

using namespace std::string_literals;

namespace minesweeper::player { namespace {

  void print(Board board) {
    for (auto&& [row, cells] : byRow(cellsOf(board)))
      console::print(to_string(cells) + "\n"s);

    auto const countdown =
    size(select (isDeadly(), cellsOf(board))) - size(select (marked(), cellsOf(board)));
    console::print("Mines left: "s + std::to_string(countdown) + "\n"s);
  }

  void printIf(std::string const& text, bool condition) {
    if (condition)
      console::print(text);
  }

  auto perform(Move move, Board board) -> Board {
    return move(board);
  }

  auto doMove(Player player, Board board) -> Board {
    print(board);

    return perform(requestMove(player, board), board);
  }
}}

void minesweeper::player::play(Player player, Board board) {
  while (! isLost(board) && ! isWon(board))
    board = doMove(player, board);

  print(reveal(board, select (isDeadly(), cellsOf(board))));
  printIf("Game lost :-(\n"s, isLost(board));
  printIf("Game won :-)\n"s, isWon(board));
  console::ask("Press ENTER to quit...");
}
