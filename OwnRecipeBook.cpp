//
// Created by eduard on 13.02.24.
//

#include "OwnRecipeBook.h"
#include "Dish.h"
#include <utility>
#include <vector>
#include <iostream>
using namespace std;



void OwnRecipeBook::getDishes() const{
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
void OwnRecipeBook::setDish(string &setName, string &newType,
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
void OwnRecipeBook::showInfo() const {
    cout<<"Name: "<<getName()<<endl;
    cout<<"Author: "<<getAuthor()<<endl;
    cout<<"Price: "<<getPrice()<<endl;
}

OwnRecipeBook::OwnRecipeBook(string newName, vector<Dish> newDrinks, vector<Dish> newFood, string newAuthor,int newPrice)
    : RecipeBook(newName,newAuthor,newPrice), food(newFood), drinks(newDrinks){}

OwnRecipeBook::~OwnRecipeBook() {}

OwnRecipeBook &OwnRecipeBook::operator=(OwnRecipeBook &other) {
    if(this == &other){
        return *this;
    }
    RecipeBook::operator=(other);
    this->food = other.food;
    this->drinks = other.drinks;
    return *this;
}

bool OwnRecipeBook::operator==(OwnRecipeBook &other) {
    if(getName() == other.getName()
       && this->drinks.size() == other.drinks.size()
       && this->food.size() == other.food.size()){
        return true;
    }
    return false;

}

ostream &operator<<(ostream &output, OwnRecipeBook &p) {
    output<<"\nWelcome to "<<p.getName()<<endl;
    return output;
}

OwnRecipeBook::OwnRecipeBook(OwnRecipeBook &other)
    : RecipeBook(other), drinks(other.drinks),food(other.food){

}

string OwnRecipeBook::getAuthor() const {
    return "You are author!";
}

