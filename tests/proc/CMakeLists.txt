# Register tests

add_executable(test_generic_register test_generic_register.cxx)
add_test(NAME test_generic_register 
         COMMAND test_generic_register)

add_executable(test_processor_status_register test_processor_status_register.cxx)
add_test(NAME test_processor_status_register 
         COMMAND test_processor_status_register)


# Processor function tests
add_executable(test_load_store_registers test_load_store_registers.cxx)
target_link_libraries(test_load_store_registers memory processor)
add_test(NAME test_load_store_registers 
         COMMAND test_load_store_registers)

add_executable(test_register_transfers test_register_transfers.cxx)
target_link_libraries(test_register_transfers memory processor)
add_test(NAME test_register_transfers 
         COMMAND test_register_transfers)

add_executable(test_increments_and_decrements test_increments_and_decrements.cxx)
target_link_libraries(test_increments_and_decrements memory processor)
add_test(NAME test_increments_and_decrements 
         COMMAND test_increments_and_decrements)

add_executable(test_arithmetic test_arithmetic.cxx)
target_link_libraries(test_arithmetic memory processor)
add_test(NAME test_arithmetic 
         COMMAND test_arithmetic)