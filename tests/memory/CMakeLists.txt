add_executable(test_memory test_memory.cxx)
target_link_libraries(test_memory memory)
add_test(NAME test_memory 
         COMMAND test_memory)