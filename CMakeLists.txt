cmake_minimum_required(VERSION 3.15)
project(FoodOrderingRModular C)

set(CMAKE_C_STANDARD 99)

add_executable(FoodOrderingRModular main.c buyer.h order.h choosingFood.c additional_things.c data_loading.c data_loading.h initialize_variables.c variables.h free_memory.c free_memory.h login.c login.h buyer.c food.c food.h type.c type.h)