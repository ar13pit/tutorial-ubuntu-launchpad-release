# add the library that runs
add_library(tutorial MathFunctions.cxx)

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(tutorial
                           PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
                           $<INSTALL_INTERFACE:include>
                           )

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)
message("-- Option USE_MYMATH is ${USE_MYMATH}")
if(USE_MYMATH)

  target_compile_definitions(tutorial PRIVATE "USE_MYMATH")

  # first we add the executable that generates the table
  add_executable(MakeTable MakeTable.cxx)
  target_link_libraries(MakeTable PRIVATE tutorial_compiler_flags)

  # add the command to generate the source code
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
    )

  # library that just does sqrt
  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              ${CMAKE_CURRENT_BINARY_DIR}/Table.h
              )

  # state that we depend on our binary dir to find Table.h
  target_include_directories(SqrtLibrary PRIVATE
                             ${CMAKE_CURRENT_BINARY_DIR}
                             ${CMAKE_CURRENT_SOURCE_DIR}/..
                             )

  # state that SqrtLibrary need PIC when the default is shared libraries
  set_target_properties(SqrtLibrary PROPERTIES
                        POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                        )

  target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)
  target_link_libraries(tutorial PRIVATE SqrtLibrary)
endif()

target_link_libraries(tutorial PUBLIC tutorial_compiler_flags)

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(tutorial PRIVATE "EXPORTING_MYMATH")

# setup the version numbering
set_property(TARGET tutorial PROPERTY VERSION "1.0.0")
set_property(TARGET tutorial PROPERTY SOVERSION "1")

# install rules
install(TARGETS tutorial tutorial_compiler_flags
        EXPORT MathFunctionsTargets
        DESTINATION ${CMAKE_INSTALL_LIBDIR})

# install(DIRECTORY include/tutorial
        # DESTINATION include)

install(FILES MathFunctions.h mysqrt.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tutorial)
