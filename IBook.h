//
// Created by eduard on 15.03.24.
//

#ifndef LAB2_1_IBOOK_H
#define LAB2_1_IBOOK_H
#include <iostream>
#include <string>
using namespace std;
class IBook{
public:
    string virtual getName() const = 0;
    string virtual getAuthor() const = 0;
    int virtual getPrice() const = 0;
};
#endif //LAB2_1_IBOOK_H
