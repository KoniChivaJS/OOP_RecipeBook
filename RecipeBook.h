//
// Created by eduard on 13.02.24.
//

#ifndef LAB2_1_RECIPEBOOK_H
#define LAB2_1_RECIPEBOOK_H
#include <string>
#include <vector>
#include "Dish.h"
using namespace std;
class RecipeBook {
private:
    string name;
    vector<Dish> drinks;
    vector<Dish> food;
public:
    void getDishes() const;
    void setDish(string &setName,string &newType,
                 string &author, string &recipe,
                 string &ingredients);
        RecipeBook(string newName = "Unknown",
                   vector<Dish> drinks = {},
                   vector<Dish> food = {});
    ~RecipeBook();
};


#endif //LAB2_1_RECIPEBOOK_H
