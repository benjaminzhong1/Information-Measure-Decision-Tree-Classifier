cmake_minimum_required(VERSION 3.10) #minimum cmake version

set(CMAKE_CXX_STANDARD 23) #target cpp version for std::variant

project(LeafClassification) #project name

include_directories(include) #include the include directory for headers

add_executable(tree_classifier
    src/main.cpp
    src/data_ingestion.cpp
    src/decision_tree.cpp
    src/utils.cpp
    )

