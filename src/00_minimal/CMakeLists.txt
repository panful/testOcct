set(target_name "00_minimal")

add_executable(${target_name} main.cpp)

target_include_directories(${target_name} PRIVATE ${OpenCASCADE_INCLUDE_DIR})
target_link_directories(${target_name} PRIVATE ${OpenCASCADE_LIBRARY_DIR})
target_link_libraries(${target_name} PRIVATE 
    TKernel
)
