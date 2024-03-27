//
// Created by eduard on 13.02.24.
//

#include "OwnRecipeBook.h"
#include "Dish.h"
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;



void OwnRecipeBook::getDishes() const{
    int choice = 0;
    cout<<"\n1: Drink category"<<endl;
    cout<<"2: Food category"<<endl;
    cout<<"3: All categories"<<endl;
    cout<<"\nChoose option: ";
    cin>>choice;
    bool found = false;
    switch (choice) {
        case 1:
            for(auto element : this->dishes){
                if(element.type == "drink"){
                    element.getDish();
                    found = true;
                }
            }
            if(!found){
                cout<<"\nNo dishes in drink category!"<<endl;
            }
            break;
        case 2:
            for(auto element : this->dishes){
                if(element.type == "food"){
                    element.getDish();
                    found = true;
                }
            }
            if(!found){
                cout<<"\nNo dishes in food category!"<<endl;
            }
            break;
        case 3:
            if(this->dishes.empty()){
                cout<<"\nNo dishes found"<<endl;
            }else{
                for(auto element : this->dishes){
                    element.getDish();
                }
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
    if(newType == "drink" || newType == "food"){
        this->dishes.push_back(setNewDish);
        cout<<"\nDish successfully added";
    }else{
        cout<<"\nCategory not found. Error"<<endl;
    }
}
void OwnRecipeBook::showInfo() const {
    cout<<"Name: "<<getName()<<endl;
    cout<<"Author: "<<getAuthor()<<endl;
    cout<<"Price: "<<getPrice()<<endl;
}

OwnRecipeBook::OwnRecipeBook(string newName, vector<Dish> newDishes, string newAuthor,int newPrice)
    : RecipeBook(newName,newAuthor,newPrice), dishes(newDishes){}

OwnRecipeBook::~OwnRecipeBook() {}

OwnRecipeBook &OwnRecipeBook::operator=(OwnRecipeBook &other) {
    if(this == &other){
        return *this;
    }
    RecipeBook::operator=(other);
    this->dishes = other.dishes;
    return *this;
}

bool OwnRecipeBook::operator==(OwnRecipeBook &other) {
    if(getName() == other.getName()
       && this->dishes.size() == other.dishes.size()){
        return true;
    }
    return false;

}

ostream &operator<<(ostream &output, OwnRecipeBook &p) {
    output<<"\n\nWelcome to "<<p.getName()<<endl;
    return output;
}

OwnRecipeBook::OwnRecipeBook(OwnRecipeBook &other)
    : RecipeBook(other), dishes(other.dishes){

}

void OwnRecipeBook::saveData() const {
    ofstream fout;
    fout.open("database.txt");
    
    if(!fout.is_open()){
        cout<<"\nError";
    }else{
        for(auto element : dishes){
            fout.write((char*)&element, sizeof(Dish));
        }
    }
    fout.close();
}
