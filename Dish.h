//
// Created by eduard on 13.02.24.
//
#include <string>
#ifndef LAB2_1_DISH_H
#define LAB2_1_DISH_H

using namespace std;
class Dish {
private:
    string name;
    string type;
    string author;
    string recipe;
    string ingredients;
public:
    void getDish() const;
    Dish(string newName="None",string newType="Unknown",
         string newAuthor="None", string newRecipe="Unknown",
         string newIngredients="None");
};


#endif //LAB2_1_DISH_H
