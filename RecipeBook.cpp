//
// Created by eduard on 13.02.24.
//

#include "RecipeBook.h"
#include "Dish.h"
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

string RecipeBook::getName() {
    return this->name;
}
void RecipeBook::setName(string &name) {
    this->name = name;
}

void RecipeBook::getDishes() const{
    int choice = 0;
    cout<<"\n1: Drink category"<<endl;
    cout<<"2: Food category"<<endl;
    cout<<"3: All categories"<<endl;
    cout<<"\nChoose option: ";
    cin>>choice;
    switch (choice) {
        case 1:
            if(drinks.empty()){
                cout<<"No dishes in drink category"<<endl;
                break;
            }
            for(const auto & drink : drinks){
                drink.getDish();
            }
            break;
        case 2:
            if(food.empty()){
                cout<<"No dishes in food category"<<endl;
                break;
            }
            for(const auto & i : food){
                i.getDish();
            }
            break;
        case 3:
            if(food.empty() && drinks.empty()){
                cout<<"No dishes in Recipe Book"<<endl;
                break;
            }
            for(const auto & drink : drinks){
                drink.getDish();
            }
            for(const auto & i : food){
                i.getDish();
            }
            break;
        default:
            cout<<"\nWrong choice"<<endl;
            break;

    }
}
void RecipeBook::setDish(string &setName,string &newType,
                         string &author, string &recipe,
                         string &ingredients) {
    Dish setNewDish(setName,newType,author,recipe,ingredients);
    if(newType == "drink"){
        drinks.push_back(setNewDish);
        cout<<"\nDrink successfully added";
    }else if(newType == "food"){
        food.push_back(setNewDish);
        cout<<"\nFood successfully added";
    }else{
        cout<<"\nCategory not found. Error"<<endl;
    }
}

RecipeBook::RecipeBook(string newName, vector<Dish> newDrinks, vector<Dish> newFood):
    name{std::move(newName)}, drinks{std::move(newDrinks)}, food{std::move(newFood)} {}

RecipeBook::~RecipeBook() {

}

RecipeBook::RecipeBook(const RecipeBook &other)
    :name(other.name), drinks(other.drinks), food(other.food){}

RecipeBook::RecipeBook(RecipeBook &&other)
    :name(other.name), drinks(other.drinks), food(other.food) {
    other.name = "Unknown";
    other.drinks = {};
    other.food = {};
}

RecipeBook &RecipeBook::operator=(RecipeBook &other) {
    if(this == &other){
        return *this;
    }
    this->food = other.food;
    this->drinks = other.drinks;
    return *this;
}

bool RecipeBook::operator==(RecipeBook &other) {
    if(this->name == other.name
       && this->drinks.size() == other.drinks.size()
       && this->food.size() == other.food.size()){
        return true;
    }
    return false;

}
