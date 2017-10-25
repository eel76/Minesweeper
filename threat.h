#pragma once
#include "severity.h"
#include "visibility.h"
#include <utility>

namespace minesweeper {
  using Threat = std::pair<State, Severity>;
  Threat      changeMark(Threat threat);
  Threat      reveal(Threat threat);
  Threat      consider(Threat threat, Hazard hazard);
  std::string to_string(Threat threat);
  bool        isRevealed(Threat threat);
  bool        isRecognized(Threat threat);
  bool        isDeadly(Threat threat);
} // namespace minesweeper
