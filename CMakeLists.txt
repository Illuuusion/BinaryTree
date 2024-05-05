cmake_minimum_required(VERSION 3.27)
project(binary_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(binary_tree Sources/main.cpp
        Headers/BinaryTree_Declaration.h
        Headers/BinaryTree.h
        Headers/Iterator.h
)
