# configure a header file to pass the version number only
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the executable
add_executable(Tutorial tutorial.cxx)
set_target_properties(Tutorial PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

target_link_libraries(Tutorial PUBLIC tutorial)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           # "${PROJECT_BINARY_DIR}"
                           ${CMAKE_CURRENT_BINARY_DIR}
                           )

# add the install targets
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/TutorialConfig.h"
  DESTINATION include/tutorial
  )
