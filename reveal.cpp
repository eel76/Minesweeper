#include "reveal.h"
#include "cells.h"
#include "concealed.h"
#include "negligible.h"
#include "neighbor.h"

auto minesweeper::toggleMark(Board board, Cells cells) -> Board {
  for (auto cell : cells)
    board[position(cell)] = toggleMark(threat(cell));

  return board;
}

auto minesweeper::reveal(Board board, Cells cs) -> Board {
  for (auto cell : concealed(cs))
    board[position(cell)] = reveal(threat(cell));

  for (auto cell : concealed(cs) | isNegligible())
    board = reveal(board, cells(board) | neighborOf(position(cell)));

  return board;
}
