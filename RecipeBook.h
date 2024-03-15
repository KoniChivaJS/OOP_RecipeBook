//
// Created by eduard on 07.03.24.
//

#ifndef LAB2_1_RECIPEBOOK_H
#define LAB2_1_RECIPEBOOK_H
#include <string>
#include <vector>
#include "IBook.h"
using namespace std;
class RecipeBook : public IBook{
private:
    string name;
    string author;
    int price;
public:
    RecipeBook(string& newName,string& newAuthor,int newPrice);

    string getName() const override final;
    void setName(string& name);
    void setAuthor(string& author);
    string getAuthor() const override final;
    int getPrice() const override final;
    void setPrice(int price);
    RecipeBook(RecipeBook& other);
    RecipeBook& operator = (RecipeBook &other);
    ~RecipeBook();
};


#endif //LAB2_1_RECIPEBOOK_H
