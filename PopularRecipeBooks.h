//
// Created by eduard on 22.02.24.
//

#ifndef LAB2_1_POPULARRECIPEBOOKS_H
#define LAB2_1_POPULARRECIPEBOOKS_H
#include <string>
#include <vector>
using namespace std;
class PopularRecipeBooks {
private:
    string name;
    int price;
    bool isBought;
    vector<string> books;
    string author;
public:
    void getBooks() const;
    bool isRecipesBought() const;
    void actionBuyBook();
//    PopularRecipeBooks(string newName = "Unknown",
//            int newPrice = 0,
//            bool boughtStatus = false,
//            vector<string> newBooks={},
//            string newAuthor = "Unknown");
    PopularRecipeBooks();
    PopularRecipeBooks(string newName,int newPrice,bool boughtStatus);
    PopularRecipeBooks(string newName,int newPrice,bool boughtStatus, vector<string> newBooks, string newAuthor);
    ~PopularRecipeBooks();

};


#endif //LAB2_1_POPULARRECIPEBOOKS_H
