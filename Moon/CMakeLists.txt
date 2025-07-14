add_executable(Moon)

file(GLOB_RECURSE Moon_SRC CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

target_sources(Moon
        PRIVATE
        ${Moon_SRC}
)

target_include_directories(Moon
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(Moon PROPERTIES
        WIN32_EXECUTABLE ON
)