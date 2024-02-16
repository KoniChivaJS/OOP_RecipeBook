//
// Created by eduard on 13.02.24.
//

#include "Dish.h"
#include <iostream>
#include <string>

using namespace std;
void Dish::getDish() const{
    cout<<"\nName of Dish: "<<name
    <<"\nType: "<<type
    <<"\nAuthor: "<<author
    <<"\nRecipe: "<<recipe
    <<"\nIngredients: "<<ingredients<<endl;
}
Dish::Dish(string newName, string newType, string newAuthor, string newRecipe,
           string newIngredients):name{newName}, type{newType}, author{newAuthor},recipe{newRecipe}, ingredients{newIngredients} {}


