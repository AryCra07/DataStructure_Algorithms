cmake_minimum_required(VERSION 3.23)
project(DSA C)

set(CMAKE_C_STANDARD 11)

add_executable(DSA
        LinearList/SequenceList.c)

add_executable(SequenceList LinearList/SequenceList.c)
add_executable(Queue LinearList/Queue.c)
add_executable(Stack LinearList/Stack.c)