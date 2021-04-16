#include "mined.h"

#include "cells.h"
#include "concealed.h"
#include "deadly.h"
#include "neighbors.h"
#include "take.h"

#include <algorithm>
#include <random>

auto minesweeper::mined(Board board, Cell cell) -> Board {
  for (auto neighbor : neighborsOf(cell, board))
    board[position(neighbor)] = mined(threat(neighbor), Hazard::Nearby);

  board[position(cell)] = mined(board[position(cell)], Hazard::Deadly);
  return board;
}

auto minesweeper::layMines(Board board, unsigned count) -> Board {
  auto cells = concealed(select (not (isDeadly()), cellsOf(board)));
  shuffle(begin(cells), end(cells), std::ranlux48{ std::random_device{}() });

  for (auto cell : select (take(count), cells))
    board = mined(board, cell);

  return board;
}
