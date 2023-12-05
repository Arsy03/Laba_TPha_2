#include "Price.h"
#include <iostream>

using namespace std;

Price::Price() {
    cout << "---Constructor Price without attributes was called---" << '\n';
}

Price::Price(string new_store, string new_thing, int new_summ) {
    store = new_store;
    thing = new_thing;
    summ = new_summ;
    cout << "---Constructor Price with attributes was called---" << endl;
}

Price::Price(Price& Price_copy) {
    thing = Price_copy.thing;
    summ = Price_copy.summ;
    cout << "---Copy constructor Price was called---" << endl;
}

Price::~Price() {
    cout << "---Destructor was called---" << endl;
}

string Price::get_store() {return store;}
string Price::get_thing() {return thing;}
int Price::get_summ() {return summ;}

void Price::set_store(string new_store) {store = new_store;}
void Price::set_thing(string new_thing) {thing= new_thing;}
void Price::set_summ(int new_summ) {summ = new_summ;}

void Price::show() {
    cout << "Thing > " << thing << '\n';
    cout << "Summ > " << summ << '\n';
}

void Price::rewrite() {
    cin.ignore(32767, '\n');

    if (store == "") {
        cout << "Enter new store > ";
        cin >> store;
    }

    cout << "Enter new thing > ";
    cin >> thing;

    cout << "Enter new cost > ";
    cin >> summ;
}