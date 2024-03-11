//
// Created by eduard on 22.02.24.
//

#include "PopularRecipeBooks.h"
#include <iostream>
#include <string>
#include <utility>

using namespace std;

bool PopularRecipeBooks::isRecipesBought() const {
    if(isBought){
        return true;
    }
    return false;
}
void PopularRecipeBooks::actionBuyBook() {
    int choice;
    cout<<"\nHi! Do you want to buy my book? (by "<<getAuthor()<<" )";
    cout<<"\nIt`ll cost: "<<getPrice()<<" грн. "<<endl;
    cout<<"\nSubmit purchase: (0 - leave it, 1 - buy): ";
    cin>>choice;
    switch (choice) {
        case 0:
            cout<<"\nYou denied a purchase."<<endl;
            break;
        case 1:
            cout<<"\nYou`ve successfully bought a book"<<endl;
            isBought = true;
            break;
        default:
            cout<<"Wrong choice."<<endl;
            break;
    }

}
void PopularRecipeBooks::getBooks() const {
    cout<<endl;
    for(const auto & book : books){
        cout<<book<<endl;
    }
}

PopularRecipeBooks::PopularRecipeBooks(string newName,int newPrice, bool boughtStatus ,vector<string> newBooks, string newAuthor)
    : RecipeBook(newName,newAuthor,newPrice), isBought(boughtStatus), books(newBooks) {}

PopularRecipeBooks::~PopularRecipeBooks() {

}

float PopularRecipeBooks::getPrice() const {
    return RecipeBook::getPrice() * 1.25;
}
