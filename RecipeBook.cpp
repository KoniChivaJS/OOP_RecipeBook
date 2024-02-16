//
// Created by eduard on 13.02.24.
//

#include "RecipeBook.h"
#include "Dish.h"
#include <vector>
#include <iostream>
using namespace std;

void RecipeBook::getDishes() const{
    int choice = 0;
    cout<<"\n1: Drink category"<<endl;
    cout<<"2: Food category"<<endl;
    cout<<"3: All categories"<<endl;
    cout<<"\nChoose option: ";
    cin>>choice;
    switch (choice) {
        case 1:
            for(int i = 0; i<drinks.size();++i){
                drinks[i].getDish();
            }
            break;
        case 2:
            for(int i = 0; i<food.size();++i){
                food[i].getDish();
            }
            break;
        case 3:
            for(int i = 0; i<drinks.size();++i){
                drinks[i].getDish();
            }
            for(int i = 0; i<food.size();++i){
                food[i].getDish();
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

RecipeBook::RecipeBook(string newName, int newPrice, vector<Dish> newDrinks, vector<Dish> newFood):
    name{newName},price{newPrice}, drinks{newDrinks}, food{newFood} {}

