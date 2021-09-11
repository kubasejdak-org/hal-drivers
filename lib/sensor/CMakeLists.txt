add_library(hal-drivers-sensor INTERFACE)
add_library(hal::drivers-sensor ALIAS hal-drivers-sensor)

set(DRIVERS
    sht3xdis
)

foreach (DRIVER IN LISTS DRIVERS)
    add_subdirectory(${DRIVER})

    target_link_libraries(hal-drivers-sensor
        INTERFACE hal::sensor-${DRIVER}
    )
endforeach ()
