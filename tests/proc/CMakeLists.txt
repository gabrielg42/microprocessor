add_executable(test_generic_register test_generic_register.cxx)
add_test(NAME test_generic_register 
         COMMAND test_generic_register)

add_executable(test_processor_status_register test_processor_status_register.cxx)
add_test(NAME test_processor_status_register 
         COMMAND test_processor_status_register)