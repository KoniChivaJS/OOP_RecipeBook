//
// Created by eduard on 07.03.24.
//

#ifndef LAB2_1_RECIPEBOOK_H
#define LAB2_1_RECIPEBOOK_H
#include <string>
#include <vector>
using namespace std;
class RecipeBook {
private:
    string name;
    string author;
    int price;
public:
    RecipeBook(string& newName,string& newAuthor,int newPrice);

    string getName() const;
    void setName(string& name);
    void setAuthor(string& author);
    virtual string getAuthor() const;
    virtual float getPrice() const;
    void setPrice(int price);
    RecipeBook(RecipeBook& other);
    RecipeBook& operator = (RecipeBook &other);
    ~RecipeBook();
};


#endif //LAB2_1_RECIPEBOOK_H
