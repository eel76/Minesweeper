#include "combos.h"

auto minesweeper::generatePositions(Rows rows, Columns columns) -> Positions {
  if (rows.empty())
    return {};

  auto positions = generatePositions({ begin(rows) + 1, end(rows) }, columns);

  for (auto column : columns)
    positions.emplace_back(rows[0], column);

  return positions;
}
