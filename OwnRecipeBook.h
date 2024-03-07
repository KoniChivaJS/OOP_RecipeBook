//
// Created by eduard on 13.02.24.
//

#ifndef LAB2_1_OWNRECIPEBOOK_H
#define LAB2_1_OWNRECIPEBOOK_H
#include <string>
#include <vector>
#include "Dish.h"
#include "RecipeBook.h"
using namespace std;
class OwnRecipeBook : public RecipeBook{
private:
    vector<Dish> drinks;
    vector<Dish> food;
public:
    void getDishes() const;

    void setDish(string &setName,string &newType,
                 string &author, string &recipe,
                 string &ingredients);
    void showInfo()const;
    OwnRecipeBook(OwnRecipeBook& other);
    OwnRecipeBook& operator = (OwnRecipeBook& other);
    bool operator ==(OwnRecipeBook& other);
    friend ostream &operator << (ostream &output, OwnRecipeBook &p);

    OwnRecipeBook(string newName = "Unknown",
                  vector<Dish> drinks = {},
                  vector<Dish> food = {},
                  string newAuthor = "Unknown",
                  int newPrice = 0);
    ~OwnRecipeBook();
};


#endif //LAB2_1_OWNRECIPEBOOK_H
