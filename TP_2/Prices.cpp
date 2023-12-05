#include "Prices.h"
#include <iostream>

using namespace std;

Prices::Prices() {
    size = 0;
    data = nullptr;
}

Prices::Prices(string n_payer) {
    size = 0;
    data = nullptr;
    store = n_payer;
    cout << "---Constructor Prices was called---" << endl;
}

Prices::~Prices() {
    cout << "---Destructor Prices was called---" << endl;
}

int Prices::get_size() {return size;}
string Prices::get_store() {return store;}
Price* Prices::get_data() {return data;}

void Prices::set_size(int new_size) {size = new_size;}
void Prices::set_store(string new_store) {store = new_store;}

void Prices::insert(Price* new_Price) {
    Price* backup = new Price[size];
    for (size_t i = 0; i < size; i++) {
        backup[i] = data[i];
    }
    data = new Price[size + 1];
    data[size] = *(new_Price);
    for (size_t i = 0; i < size; i++) {
        data[i] = backup[i];
    }
    size++;
}

void Prices::remove(int& indx) {
    Price* backup = new Price[size - 1];
    for (size_t i = 0; i < indx - 1; i++) {
        backup[i] = data[i];
    }
    for (size_t i = indx; i < size; i++) {
        backup[i - 1] = data[i];
    }
    size--;
    data = new Price[size];
    for (size_t i = 0; i < size; i++) {
        data[i] = backup[i];
    }
}

void Prices::show() {
    cout << "Store > " << store << endl;
    if (size == 0) {
        cout << "Store is empty" << endl;
        exit(0);
    }

    for (int i = 0; i < size; i++) {
        cout << endl << i + 1 << ")";
        data[i].show();
    }
}