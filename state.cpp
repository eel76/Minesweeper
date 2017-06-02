#include "state.h"
#include <utility>

using namespace minesweeper;
using namespace std;

bool minesweeper::IsMine(State const& state)
{
  return get<Mines>(state) < 0;
}
