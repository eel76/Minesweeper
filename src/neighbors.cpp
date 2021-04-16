#include "neighbors.h"

#include "positions.h"
#include <algorithm>

namespace minesweeper { namespace {
  auto up(Position position) -> Position {
    return { Row{ index(row(position)) + 1 }, column(position) };
  }

  auto down(Position position) -> Position {
    return { Row{ index(row(position)) - 1 }, column(position) };
  }

  auto left(Position position) -> Position {
    return { row(position), Column{ index(column(position)) - 1 } };
  }

  auto right(Position position) -> Position {
    return { row(position), Column{ index(column(position)) + 1 } };
  }

  auto neighborPositions(Position position) -> Positions {
    return { up(left(position)), up(position),         up(right(position)),
             left(position),     right(position),      down(left(position)),
             down(position),     down(right(position)) };
  }

  auto cellsOf(Positions positions, Board const& board) -> Cells {
    Cells cells;

    transform(begin(positions), end(positions), std::back_inserter(cells), [&](auto position) {
      return Cell{ position, board.at(position) };
    });

    return cells;
  }
}}

auto minesweeper::neighborsOf(Cell cell, Board const& board) -> Cells {
  auto neighbors = neighborPositions(position(cell));

  neighbors.erase(remove_if(begin(neighbors), end(neighbors),
                            [&](auto neighbor) {
                              return board.count(neighbor) != 1;
                            }),
                  end(neighbors));

  return cellsOf(neighbors, board);
}
