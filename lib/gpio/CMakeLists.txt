add_library(hal-drivers-gpio INTERFACE)
add_library(hal::drivers-gpio ALIAS hal-drivers-gpio)

set(DRIVERS
    mcp23x17
)

foreach (DRIVER IN LISTS DRIVERS)
    add_subdirectory(${DRIVER})

    target_link_libraries(hal-drivers-gpio
        INTERFACE hal::gpio-${DRIVER}
    )
endforeach ()
