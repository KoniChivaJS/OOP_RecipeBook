cmake_minimum_required(VERSION 3.27)
project(lab2_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2_1 main.cpp
        Dish.cpp
        Dish.h
        OwnRecipeBook.cpp
        OwnRecipeBook.h
        PopularRecipeBooks.cpp
        PopularRecipeBooks.h
        RecipeBook.cpp
        RecipeBook.h
        IBook.h
        User.cpp
        User.h
)
