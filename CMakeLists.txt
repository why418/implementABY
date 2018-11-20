
add_executable(project bench_operations.cpp ../aes/common/aescircuit.cpp)
target_link_libraries(project ABY::aby ENCRYPTO_utils::encrypto_utils)
