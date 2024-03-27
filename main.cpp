#include <iostream>
#include "Dish.h"
#include "OwnRecipeBook.h"
#include "PopularRecipeBooks.h"
#include <string>
#include "User.h"
#include <fstream>
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
void changeDescription(OwnRecipeBook& HowToCook){
    string newName,newAuthor;
    int price = 0;
    cout<<"Enter new name: ";
    cin>>newName;
    cout<<"Enter an author: ";
    cin>>newAuthor;
    cout<<"Enter a price: ";
    cin>>price;

    HowToCook.setName(newName);
    HowToCook.setAuthor(newAuthor);
    HowToCook.setPrice(price);
}
void showBookName(RecipeBook &book){
    cout<<"Welcome to: "<<book.getName()<<endl;
}
bool authorisation(User &user){
    string login,password;
    cout<<"Enter Login: ";
    cin>>login;
    cout<<"Enter password: ";
    cin>>password;

    if(user.getLogin() == login && user.getPassword() == password){
        user.setAdmin(true);
        return true;
    }
    return false;

}

bool userMethods(OwnRecipeBook &HowToCook,PopularRecipeBooks &allRecipes, OwnRecipeBook &CopyBook, User &user){
    int choice = 0;
    showBookName(HowToCook);
    cout<<"1: Get dishes";
    allRecipes.isRecipesBought() ? cout<<"\n2: Show Popular Recipes" : cout<<"\n2: Buy Popular Recipe Books";
    cout<<"\n3: Show info about RecipeBook"
          "\n4: Log in admin account"
          "\n5: Exit"
          "\nChoose option: ";
    cin>>choice;

    switch (choice) {
        case 1:
            HowToCook.getDishes();
            break;
        case 2:
            allRecipes.isRecipesBought() ? allRecipes.getBooks() : allRecipes.actionBuyBook();
            break;
        case 3:
            HowToCook.showInfo();
            break;
        case 4:
            authorisation(user) ? cout<<"\nSuccess" : cout<<"\nError. Wrong password or login" ;
            cout<<endl;
            break;
        case 5:
            return false;
        default:
            cout<<"Wrong choice!"<<endl;
            break;
    }
    return true;
}
bool adminMethods(OwnRecipeBook &HowToCook,PopularRecipeBooks &allRecipes, OwnRecipeBook &CopyBook, User &user){
    int choice = 0;
    showBookName(HowToCook);
    cout<<"Logged as Admin";
    cout<<"\n1: Get dishes";
    cout<<"\n2: Make a new Dish"
          "\n3: Show popular recipes"
          "\n4: Change description"
          "\n5: Make Copy RecipeBook"
          "\n6: Show Copy RecipeBook"
          "\n7: Compare RecipeBooks"
          "\n8: Show info about RecipeBook"
          "\n9: Log out"
          "\n10: Exit"
          "\nChoose option: ";
    cin>>choice;

    switch (choice) {
        case 1:
            HowToCook.getDishes();
            break;
        case 2:
            makeNewDish(HowToCook);
            break;
        case 3:
            allRecipes.getBooks();
            break;
        case 4:
            changeDescription(HowToCook);
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
            HowToCook.showInfo();
            break;
        case 9:
            user.setAdmin(false);
            cout<<"\nLogged out"<<endl;
            break;
        case 10:
            HowToCook.saveData();
            return false;
        default:
            cout<<"Wrong choice!"<<endl;
            break;
    }
    return true;
}

int main() {
    OwnRecipeBook HowToCook("HowToCook", {});
    OwnRecipeBook CopyBook(HowToCook);
    PopularRecipeBooks allRecipes("100BooksList",99,false,
                                                    {"La Pizzas - `link`","Baguettes - `link`","National Dishes - `link`","100 Types of pasta - `link`"},
                                                    "Aleg Tenet");
    User user("konichiva","oleg","konichiva@gmail.com",false);

    bool whileWorking = true;
    while (whileWorking){
        whileWorking = user.getAdmin()
                ? adminMethods(HowToCook,allRecipes,CopyBook,user)
                : userMethods(HowToCook,allRecipes,CopyBook,user);

    }


    return 0;
}
