add_executable(multicore
        multicore.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(multicore pico_stdlib pico_multicore)

# enable usb output
pico_enable_stdio_usb(multicore 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(multicore)

# add url via pico_set_program_url
example_auto_set_url(multicore)
