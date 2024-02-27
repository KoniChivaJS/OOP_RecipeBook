#include <iostream>
#include "Dish.h"
#include "RecipeBook.h"
#include "PopularRecipeBooks.h"
#include <string>
using namespace std;

void makeNewDish(RecipeBook &HowToCook){
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

class Math{
private:
    int a;
    int b;
public:
    static int addNum(int a,int b){
        return a + b;
    }
};
int main() {
    RecipeBook HowToCook("HowToCook",{});
    RecipeBook CopyBook(HowToCook);
    PopularRecipeBooks allRecipes("100BooksList",99,false,
                                 {"La Pizzas - `link`","Baguettes - `link`","National Dishes - `link`","100 Types of pasta - `link`"},
                                 "Antonio Prip.");

    while (true){
        int choice = 0;
        cout<<"\n\nWelcome to "<<HowToCook.getName()<<endl;

        cout<<"1: Make New Dish"<<endl;
        cout<<"2: Get dishes"<<endl;

        if(allRecipes.isRecipesBought()){
            cout<<"3: Show Popular Recipes"<<endl;
        }else{
            cout<<"3: Buy Popular Recipe Books"<<endl;
        }
        cout<<"4: Change name of RecipeBook"<<endl;
        cout<<"5: Make Copy RecipeBook"<<endl;
        cout<<"6: Show Copy RecipeBook"<<endl;
        cout<<"7: Compare RecipeBooks"<<endl;
        cout<<"8: Exit"<<endl;

        cout<<"Choose option: ";
        cin>>choice;
        if(choice == 1){
            makeNewDish(HowToCook);
        }else if(choice == 2){
            HowToCook.getDishes();
        }else if(choice == 3){
            if(allRecipes.isRecipesBought()){
                allRecipes.getBooks();
            }else{
                allRecipes.actionBuyBook();
            }
        }else if(choice == 4){
            string newName;
            cout<<"Enter new name: ";
            cin>>newName;
            HowToCook.setName(newName);
        }else if(choice == 5){
            CopyBook = HowToCook;
        }else if(choice == 6){
            CopyBook.getDishes();
        }
        else if(choice == 7){
            bool res = CopyBook == HowToCook;
            if(res){
                cout<<"The Books are Similar"<<endl;
            }else{
                cout<<"The Books are Diffetent"<<endl;
            }
        }else if(choice == 8){
            break;
        }


    }

    cout<<Math:addNum(1,2);

    return 0;
}
