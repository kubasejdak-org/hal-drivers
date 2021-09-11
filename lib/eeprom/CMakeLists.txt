add_library(hal-drivers-eeprom INTERFACE)
add_library(hal::drivers-eeprom ALIAS hal-drivers-eeprom)

set(DRIVERS
    generic
)

foreach (DRIVER IN LISTS DRIVERS)
    add_subdirectory(${DRIVER})

    target_link_libraries(hal-drivers-eeprom
        INTERFACE hal::eeprom-${DRIVER}
    )
endforeach ()
