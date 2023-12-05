#pragma once
#include "Price.h"

class Prices {
private:
    int size;
    Price* data;
    string store;
public:
    Prices();
    Prices(string n_store);
    ~Prices();

    int get_size();
    string get_store();
    Price* get_data();

    void set_size(int new_size);
    void set_store(string new_store);

    void insert(Price* new_Price);
    void remove(int& indx);
    void show();
};