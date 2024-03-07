#include <iostream>
#include "Dish.h"
#include "OwnRecipeBook.h"
#include "PopularRecipeBooks.h"
#include <string>
using namespace std;

void makeNewDish(OwnRecipeBook &HowToCook){
    string name,type,author,recipe,ingredients;

    cout<<"Enter name: ";
    cin>>name;

    cout<<"Enter type of food (drink,food) : ";
    cin>>type;

    cout<<"Enter Author: ";
    cin>>author;

    cout<<"Enter Recipe: ";
    cin>>recipe;

    cout<<"Enter ingredients: ";
    cin>>ingredients;
    HowToCook.setDish(name,type,author,recipe,ingredients);

}


int main() {
    OwnRecipeBook HowToCook("HowToCook", {});
    OwnRecipeBook CopyBook(HowToCook);
    PopularRecipeBooks allRecipes("100BooksList",99,false,
                                 {"La Pizzas - `link`","Baguettes - `link`","National Dishes - `link`","100 Types of pasta - `link`"},
                                 "Antonio Prip.");
    bool whileWorking = true;
    while (whileWorking){
        int choice = 0;
        cout<<HowToCook<<endl;
        cout<<"1: Make New Dish"
              "\n2: Get dishes";
        allRecipes.isRecipesBought() ? cout<<"3: Show Popular Recipes"<<endl : cout<<"3: Buy Popular Recipe Books"<<endl ;
        cout<<"4: Change name of RecipeBook"
              "\n5: Make Copy RecipeBook"
              "\n6: Show Copy RecipeBook"
              "\n7: Compare RecipeBooks"
              "\n8: Exit"
              "\nChoose option: ";
        cin>>choice;

        switch (choice) {
            case 1:
                makeNewDish(HowToCook);
                break;
            case 2:
                HowToCook.getDishes();
                break;
            case 3:
                allRecipes.isRecipesBought() ? allRecipes.getBooks() : allRecipes.actionBuyBook();
                break;
            case 4:
                cout<<"Enter new name: ";
                cin >> HowToCook;
                break;
            case 5:
                CopyBook = HowToCook;
                break;
            case 6:
                CopyBook.getDishes();
                break;
            case 7:
                CopyBook == HowToCook ? cout<<"The Books are Similar"<<endl : cout<<"The Books are Diffetent"<<endl;
                break;
            case 8:
                whileWorking = false;
                break;
            default:
                cout<<"Wrong choice!"<<endl;
                break;
        }
    }

    return 0;
}
