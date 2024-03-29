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
    bool isRecipesBought() const;
    string getAuthor() const override;
    void actionBuyBook();
    PopularRecipeBooks(string newName = "Unknown",
            int newPrice = 0,
            bool boughtStatus = false,
            vector<string> newBooks={},
            string newAuthor = "Unknown");
    ~PopularRecipeBooks();

};


#endif //LAB2_1_POPULARRECIPEBOOKS_H
