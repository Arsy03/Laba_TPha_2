#pragma once
#include <string>

using namespace std;

class Price {

private:
    string store;
    string thing;
    int summ;
public:
    Price();
    Price(string new_store, string new_thing, int new_summ);
    Price(Price& Price_copy);
    ~Price();

    string get_store();
    string get_thing();
    int get_summ();

    void set_store(string new_store);
    void set_thing(string new_thing);
    void set_summ(int new_summ);

    void show();
    void rewrite();
};