find_package(PythonLibs 3 REQUIRED) # Just to make sure that setup.py won't fail
find_package(PythonInterp 3 REQUIRED)

configure_file(setup.py.in setup.py)

set(BUILD_LIB_PARAMS
    --lib-dirs $<TARGET_FILE_DIR:foo>
    --lib-dirs $<TARGET_FILE_DIR:bar>
    --include-dirs $<TARGET_PROPERTY:foo,INCLUDE_DIRECTORIES>
    --include-dirs $<TARGET_PROPERTY:bar,INCLUDE_DIRECTORIES>
    --libraries foo
    --libraries bar
    --source-files ${CMAKE_CURRENT_SOURCE_DIR}/foobar_python.cpp)

add_custom_target(python_module ALL
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/setup.py build --build-base=${CMAKE_BINARY_DIR}/build ${BUILD_LIB_PARAMS})

add_dependencies(python_module foo bar)

install(CODE "execute_process(COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/setup.py install --prefix=${CMAKE_INSTALL_PREFIX})")
