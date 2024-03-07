//
// Created by eduard on 13.02.24.
//

#ifndef LAB2_1_OWNRECIPEBOOK_H
#define LAB2_1_OWNRECIPEBOOK_H
#include <string>
#include <vector>
#include "Dish.h"
using namespace std;
class OwnRecipeBook {
private:
    string name;
    vector<Dish> drinks;
    vector<Dish> food;
public:
    void getDishes() const;
    string getName();
    void setName(string &name);
    void setDish(string &setName,string &newType,
                 string &author, string &recipe,
                 string &ingredients);
    OwnRecipeBook(const OwnRecipeBook& other);
    OwnRecipeBook(OwnRecipeBook&& other) noexcept ;
    OwnRecipeBook& operator = (OwnRecipeBook& other);
    bool operator ==(OwnRecipeBook& other);
    friend ostream &operator << (ostream &output, OwnRecipeBook &p);
    friend istream &operator >> (istream &input, OwnRecipeBook &p);

    OwnRecipeBook(string newName = "Unknown",
                  vector<Dish> drinks = {},
                  vector<Dish> food = {});
    ~OwnRecipeBook();
};


#endif //LAB2_1_OWNRECIPEBOOK_H
