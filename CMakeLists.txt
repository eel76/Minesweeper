cmake_minimum_required (VERSION 3.15)

project (Minesweeper CXX)
set (CMAKE_CXX_STANDARD 17)

add_executable (
  ${PROJECT_NAME}
  )

target_sources (${PROJECT_NAME} PRIVATE
  include/ask.h
  include/board.h
  include/cell.h
  include/cells.h
  include/choose.h
  include/column.h
  include/columns.h
  include/combos.h
  include/computer.h
  include/concealed.h
  include/deadly.h
  include/filter.h
  include/getline.h
  include/group.h
  include/hazard.h
  include/human.h
  include/marked.h
  include/mined.h
  include/move/mark.h
  include/move/parse.h
  include/move/reveal.h
  include/move.h
  include/negligible.h
  include/neighbor.h
  include/only.h
  include/play.h
  include/player.h
  include/position.h
  include/positions.h
  include/preparation.h
  include/print.h
  include/reveal.h
  include/revealed.h
  include/row.h
  include/rows.h
  include/severity.h
  include/state.h
  include/take.h
  include/threat.h
  include/to_string.h
  src/board.cpp
  src/cell.cpp
  src/cells.cpp
  src/choose.cpp
  src/column.cpp
  src/columns.cpp
  src/combos.cpp
  src/computer.cpp
  src/getline.cpp
  src/move/mark.cpp
  src/move/parse.cpp
  src/move/reveal.cpp
  src/filter.cpp
  src/group.cpp
  src/human.cpp
  src/main.cpp
  src/mined.cpp
  src/play.cpp
  src/position.cpp
  src/preparation.cpp
  src/print.cpp
  src/reveal.cpp
  src/row.cpp
  src/rows.cpp
  src/severity.cpp
  src/state.cpp
  src/threat.cpp
  src/to_string.cpp
  Readme.md
  )

target_include_directories (
  ${PROJECT_NAME}
  PRIVATE include
  )

if (IS_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/../imperative-calisthenics")
  add_subdirectory ("${CMAKE_CURRENT_LIST_DIR}/../imperative-calisthenics" "${CMAKE_CURRENT_BINARY_DIR}/imperative-calisthenics")
endif ()
