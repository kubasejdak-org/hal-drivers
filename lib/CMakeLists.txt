cmake_minimum_required(VERSION 3.24)

# Project-wide compilation options.
add_compile_options(-Wall -Wextra -Wpedantic -Werror $<$<COMPILE_LANGUAGE:CXX>:-std=c++20> $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>)

add_library(hal-drivers INTERFACE)
add_library(hal::drivers ALIAS hal-drivers)

set(MODULES
    eeprom
    gpio
    rtc
    sensor
)

add_subdirectory(logger)

foreach (MODULE IN LISTS MODULES)
    add_subdirectory(${MODULE})

    target_link_libraries(hal-drivers
        INTERFACE hal::drivers-${MODULE}
    )
endforeach ()
