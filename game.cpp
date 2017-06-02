#include "game.h"
#include "preparation.h"
#include "round.h"

using namespace minesweeper;

void minesweeper::PlayGame(Size size, MineCount mineCount)
{
  // FIXME: first user move is always ok
  auto board = LayMines(MakeBoard(size), mineCount);

  while (NextRoundPossible(board))
    board = NextRound(board);

  EvaluationRound(board);
}