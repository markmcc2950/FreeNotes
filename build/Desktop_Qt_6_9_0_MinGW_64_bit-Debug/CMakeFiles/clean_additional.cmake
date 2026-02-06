# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FreeNotes_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FreeNotes_autogen.dir\\ParseCache.txt"
  "FreeNotes_autogen"
  )
endif()
