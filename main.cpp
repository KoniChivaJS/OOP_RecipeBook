#include <iostream>
#include "Dish.h"
#include "RecipeBook.h"
#include <string>
#include <vector>
using namespace std;

void makeNewDish(RecipeBook &HowToCook){
    string name,type,author,recipe,ingredients;

    cout<<"Enter name: ";
    cin>>name;

    cout<<"Enter type of food: ";
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
    RecipeBook HowToCook("HowToCook",999,{});
    while (true){
        int choice = 0;
        cout<<"\nWelcome to RecipeBook"<<endl;

        cout<<"1: Make New Dish"<<endl;
        cout<<"2: Get dishes"<<endl;
        cout<<"3: Exit"<<endl;

        cout<<"Choose option: ";
        cin>>choice;
        if(choice == 1){
            makeNewDish(HowToCook);
        }else if(choice == 2){
            HowToCook.getDishes();
        }else if(choice == 3){
            break;
        }


    }



    return 0;
}
