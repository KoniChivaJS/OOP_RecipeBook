//
// Created by eduard on 22.02.24.
//

#ifndef LAB2_1_POPULARRECIPEBOOKS_H
#define LAB2_1_POPULARRECIPEBOOKS_H
#include <string>
#include <vector>
#include "RecipeBook.h"
using namespace std;
class PopularRecipeBooks : public RecipeBook{
private:
    bool isBought;
    vector<string> books;
public:
    void getBooks() const;
    virtual float getPrice() const;
    bool isRecipesBought() const;
    void actionBuyBook();
    PopularRecipeBooks(string newName = "Unknown",
            int newPrice = 0,
            bool boughtStatus = false,
            vector<string> newBooks={},
            string newAuthor = "Unknown");
    ~PopularRecipeBooks();

};


#endif //LAB2_1_POPULARRECIPEBOOKS_H
