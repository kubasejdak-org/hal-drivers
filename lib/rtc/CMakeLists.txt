add_library(hal-drivers-rtc INTERFACE)
add_library(hal::drivers-rtc ALIAS hal-drivers-rtc)

set(DRIVERS
    m41t82
)

foreach (DRIVER IN LISTS DRIVERS)
    add_subdirectory(${DRIVER})

    target_link_libraries(hal-drivers-rtc
        INTERFACE hal::rtc-${DRIVER}
    )
endforeach ()