cmake_minimum_required(VERSION 3.17)
project(CCL)

set(CMAKE_CXX_STANDARD 20)

add_executable(map_study map_study.cpp)
add_executable(ellipsis_syntax ellipsis_syntax.cpp)
add_executable(seq_container seq_container.cpp)

add_executable(upper_bound_lower_bound upper_bound_lower_bound.cpp)

add_executable(thread_demo thread_demo/hello_thread.cpp)
add_executable(thread_join thread_demo/thread_join.cpp)
add_executable(thread_joinable thread_demo/thread_joinable.cpp)
add_executable(thread_detach thread_demo/thread_detach.cpp)

add_executable(thread_parameter thread_demo/thread_parameter.cpp)
add_executable(thread_ownership thread_demo/thread_ownership.cpp)


add_executable(CostEstimate CostEstimate.cc CostEstimate.hh)

add_executable(ConstRef ConstRef.cc)

add_executable(DeConstructor DeConstructor.cc DeConstructor.hh)

add_executable(OperatorOverLoad OperatorOverLoad.cc)

add_executable(TableTennisPlayer TableTennisPlayer.cc)
add_executable(VirtualFunction VirtualFunction.cc)
add_executable(multi-inherited multi-inherited.cc)

add_executable(main main.cc
        Sales_data.cc Sales_data.hh
        Screen.hh Screen.cc
        Windows_Mgr.hh Windows_Mgr.cc
        X.hh X.cc
        )
add_executable(constructor constructor.cc
        Sales_data.cc Sales_data.hh
        Screen.hh Screen.cc
        Windows_Mgr.hh Windows_Mgr.cc
        X.hh X.cc
        )

add_executable(bits_l bits_l.cc)

add_executable(operator_bits operator_bits.cc)

add_executable(Initialization_L Initialization_L.cc)

add_executable(local_static File1.hh File2.cc)
add_executable(ConstructorDestructorAssignment ConstructorDestructorAssignment.cc)
add_executable(Uncopyable Uncopyable.cc)
add_executable(virtual_destructor virtual_destructor.cc)
add_executable(call-virtual-in-constructor call-virtual-in-constructor.cc)

add_executable(copy_object copy_object.cc)