add_library(hal-drivers-logger INTERFACE)
add_library(hal::drivers-logger ALIAS hal-drivers-logger)

target_include_directories(hal-drivers-logger
    INTERFACE include
)

target_link_libraries(hal-drivers-logger
    INTERFACE utils::logger
)
