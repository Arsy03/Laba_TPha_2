#pragma once
#include "Prices.h"

class Menu {
protected:
    int count = 0;
    Prices* list;
    int exit = 1;
public:
    void Main_options();
    void Options();
    void Show_All();
    void Edit();
    void Add();
    void delete_price();
    void delete_prices(int ind);
    void Eject();
    void Analyze();
};