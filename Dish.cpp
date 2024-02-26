//
// Created by eduard on 13.02.24.
//

#include "Dish.h"
#include <iostream>
#include <string>
#include <utility>

using namespace std;
void Dish::getDish() const{
    cout<<"\nName of Dish: "<<name
    <<"\nType: "<<type
    <<"\nAuthor: "<<author
    <<"\nRecipe: "<<recipe
    <<"\nIngredients: "<<ingredients<<endl;
}
Dish::Dish(string newName, string newType, string newAuthor, string newRecipe,
           string newIngredients):name{std::move(newName)}, type{std::move(newType)}, author{std::move(newAuthor)},recipe{std::move(newRecipe)}, ingredients{std::move(newIngredients)} {}

Dish::~Dish() {}


