#include "cell.h"
#include <map>

using namespace minesweeper;
using namespace std;

std::string minesweeper::toString(Cell cell)
{
  char constexpr toChar[3][19] = { "##################", "******************",
                                   ".12345678XXXXXXXXX" };
  return string{ toChar[get<State>(cell)][get<Threat>(cell)] };
}

Cell minesweeper::toggleMark(Cell cell)
{
  return Cell{ toggleMark(get<State>(cell)), get<Threat>(cell) };
}

Cell minesweeper::uncover(Cell cell)
{
  return Cell{ uncover(get<State>(cell)), get<Threat>(cell) };
}

Cell minesweeper::threaten(Cell cell, Threat threat)
{
  return Cell{ get<State>(cell), Threat(get<Threat>(cell) + threat) };
}

bool minesweeper::isUncovered(Cell cell)
{
  return get<State>(cell) == State::Uncovered;
}

bool minesweeper::isMarked(Cell cell)
{
  return get<State>(cell) == State::Marked;
}

bool minesweeper::containsMine(Cell cell)
{
  return get<Threat>(cell) >= Threat::Mine;
}