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

class MoveExample {
private:
    int *data;
    int size;
public:
    MoveExample(int size){
        this->data = new int[size];
        this->size = size;
        for(int i = 0 ; i<size;i++){
            data[i] = i;
        }
        ShowData();
    };
    void ShowData(){
        for(int i = 0 ; i<size;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        if(data == nullptr){
            cout<<"Data in classCopy: nullptr";
        }
    }
    MoveExample(const MoveExample& other){
        this->size=other.size;
        data = new int;
        for(int i = 0; i < this->size; ++i){
            this->data[i] = other.data[i];
        }
    }
    MoveExample(MoveExample&& other)
        :data(other.data),size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
    }
    ~MoveExample(){
        cout<<"Destructor was called";
        delete[] data;
    }
};


int main() {
    MoveExample classCopy(5);
    MoveExample secondCopy = move(classCopy);
    secondCopy.ShowData();
    classCopy.ShowData();

    RecipeBook HowToCook("HowToCook",{});
    PopularRecipeBooks allRecipes("100BooksList",99,false,
                                 {"La Pizzas - `link`","Baguettes - `link`","National Dishes - `link`","100 Types of pasta - `link`"},
                                 "Antonio Prip.");

    while (true){
        int choice = 0;
        cout<<"\n\nWelcome to RecipeBook"<<endl;

        cout<<"1: Make New Dish"<<endl;
        cout<<"2: Get dishes"<<endl;

        if(allRecipes.isRecipesBought()){
            cout<<"3: Show Popular Recipes"<<endl;
        }else{
            cout<<"3: Buy Popular Recipe Books"<<endl;
        }

        cout<<"4: Exit"<<endl;

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
            break;
        }


    }



    return 0;
}
