//
// Created by eduard on 07.03.24.
//

#include "RecipeBook.h"

RecipeBook::RecipeBook(string& newName, string& newAuthor, int newPrice)
    :name(newName),author(newAuthor),price(newPrice){}

string RecipeBook::getName() const {
    return this->name;
}

void RecipeBook::setName(string &name) {
    this->name = name;
}

void RecipeBook::setPrice(int price) {
    this->price = price;
}

int RecipeBook::getPrice() const {
    return this->price;
}

RecipeBook &RecipeBook::operator=(RecipeBook &other) {
    if(this == &other){
        return *this;
    }
    this->name = other.name;
    this->author = other.author;
    this->price = other.price;
    return *this;
}
