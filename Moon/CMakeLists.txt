add_executable(Moon)

file(GLOB_RECURSE Moon_SRC CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/*.cpp"
)

target_sources(Moon PRIVATE
        ${Moon_SRC}
)

set_target_properties(Moon PROPERTIES
        WIN32_EXECUTABLE ON
)