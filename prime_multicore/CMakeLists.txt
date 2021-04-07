add_executable(prime_multicore
        prime_multicore.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(prime_multicore pico_stdlib pico_multicore)

# enable usb output
pico_enable_stdio_usb(prime_multicore 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(prime_multicore)

# add url via pico_set_program_url
example_auto_set_url(prime_multicore)
