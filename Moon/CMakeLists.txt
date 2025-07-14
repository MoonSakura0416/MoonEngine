add_executable(Moon)

file(GLOB_RECURSE Moon_SRC CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Core/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Platform/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Debug/*.cpp"
)

target_sources(Moon
        PRIVATE
        ${Moon_SRC}
)

find_package(spdlog CONFIG REQUIRED)

target_link_libraries(Moon
        PUBLIC
        spdlog::spdlog
)

target_include_directories(Moon
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(Moon PROPERTIES
        WIN32_EXECUTABLE ON
)

target_compile_definitions(Moon
        PRIVATE
        UNICODE _UNICODE
)