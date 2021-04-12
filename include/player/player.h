#pragma once
#include "move.h"
#include <functional>

namespace minesweeper::player {
  using Player = std::function<Move(Board)>;
  inline auto requestMove(Player player, Board board) -> Move {
    return player(board);
  }
}
