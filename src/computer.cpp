#include "computer.h"

#include "concealed.h"
#include "deadly.h"
#include "marked.h"
#include "move.h"
#include "move/mark.h"
#include "move/reveal.h"
#include "neighbors.h"
#include "positions.h"
#include "revealed.h"
#include "take.h"
#include <algorithm>
#include <random>

namespace minesweeper { namespace {

  auto count(Filter test, Cells cells) {
    return size(select(test, cells));
  }

  auto hintsOf(Cell cell, Board board) {
    return select(revealed(), neighborsOf(cell, board));
  }

  Filter threatMarkable(Board board) {
    return [board](auto cell) {
      auto const neighbors = neighborsOf(cell, board);
      return count(isDeadly(), neighbors) == count(not(revealed()), neighbors);
    };
  }

  Filter threatMarked(Board board) {
    return [board](auto cell) {
      auto const neighbors = neighborsOf(cell, board);
      return count(isDeadly(), neighbors) == count(marked(), neighbors);
    };
  }

  Filter markMissing(Board board) {
    return [board](auto cell) {
      auto const hints = hintsOf(cell, board);
      return any_of(begin(hints), end(hints), threatMarkable(board));
    };
  }

  Filter safe(Board board) {
    return [board](auto cell) {
      auto const hints = hintsOf(cell, board);
      return any_of(begin(hints), end(hints), threatMarked(board));
    };
  }

  auto partition(Cells cells, Filter filter) {
    std::partition(begin(cells), end(cells), filter);
    return cells;
  }

  auto computerMove(Board board) -> Move {
    auto const concealedCells = concealed(cellsOf(board));
    if (concealedCells.empty())
      throw;

    if (auto cells = select(take(1), select(markMissing(board), concealedCells));
        !cells.empty())
      return move::mark(position(cells[0]));

    return move::reveal(position(partition(concealedCells, safe(board))[0]));
  }
}}

auto minesweeper::computer() -> Player {
  return [](auto board) { return computerMove(board); };
}
