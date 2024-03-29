#include "reveal.h"
#include "cells.h"
#include "concealed.h"
#include "negligible.h"
#include "neighbors.h"

auto minesweeper::toggleMark(Board board, Cells cells) -> Board {
  for (auto cell : cells)
    board[position(cell)] = toggleMark(threat(cell));

  return board;
}

auto minesweeper::reveal(Board board, Cells cells) -> Board {
  for (auto cell : concealed(cells))
    board[position(cell)] = reveal(threat(cell));

  for (auto cell : select (isNegligible(), concealed(cells)))
    board = reveal(board, neighborsOf(cell, board));

  return board;
}
