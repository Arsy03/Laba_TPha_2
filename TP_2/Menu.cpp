#include "Menu.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void sort_list(Prices* list, int cnt) {
    for (int i = 0; i < cnt - 1; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (list[i].get_store().compare(list[j].get_store()) > 0) {
                Prices tmp1 = list[i];
                Prices tmp2 = list[j];
                list[i] = tmp2;
                list[j] = tmp1;
            }
        }
    }
}

struct vector {
public:
    size_t size;
    pair<string, string> el;
    vector* data;

    vector() {
        data = nullptr;
        size = 0;
    }

    void insert(pair<string, string>& new_el);

};

void vector::insert(pair<string, string>& new_el) {
    vector* backup = new vector[size];
    for (int i = 0; i < size; i++) {
        backup[i] = data[i];
    }
    data = new vector[size + 1];
    data[size].el = new_el;
    for (int i = 0; i < size; i++) {
        data[i] = backup[i];
    }
    size++;
}

void Menu::Analyze() {
    ifstream f;
    f.open("E:\\Workspace\\Clion_Projects\\TP_2\\Example.txt");
    vector v_s;

    string s;
    string t, first_word;
    while (!f.eof()) {
        f >> t;
        if (s == "") {
            s += t;
            first_word = t;
        }
        else s += " " + t;

        if (t[t.size() - 1] == '.') {
            pair<string, string> p = { s, first_word };
            v_s.insert(p);
            s = "";
        }
    }

    for (int i = 0; i < v_s.size - 1; i++) {
        for (int j = i + 1; j < v_s.size; j++) {
            if (v_s.data[i].el.second.size() != 1 && v_s.data[j].el.second.size() == 1) {
                pair<string, string> tmp1, tmp2;
                tmp1 = v_s.data[i].el;
                tmp2 = v_s.data[j].el;
                v_s.data[i].el = tmp2;
                v_s.data[j].el = tmp1;
            }
        }
    }

    for (int i = 0; i < v_s.size; i++) {
        cout << v_s.data[i].el.first << '\n';
    }

    delete[] v_s.data;
}

void Menu::Main_options() {
    Options();
    char c;
    cin >> c;
    while (c != '0') {
        switch (c) {
            case '1':
                Show_All();
                break;
            case '2':
                Add();
                break;
            case '3':
                delete_price();
                break;
            case '4':
                Edit();
                break;
            case '5':
                Analyze();
                break;
            default:
                //Eject();
                break;
        }
        Options();
        cin >> c;
    }
}

void Menu::Options() {
    cout << "\nOptions:" << endl;
    cout << "Task #1" << endl;
    cout << "1 - Show all prices" << endl;
    cout << "2 - Add new price" << endl;
    cout << "3 - Delete a price" << endl;
    cout << "4 - Edit" << endl;
    cout << "Task #2" << endl;
    cout << "5 - File analyzer" << endl;
    cout << "0 - Exit" << endl;
    cout << ">>> ";
}

void Menu::Show_All() {
    if (count == 0) {
        cout << "There's nothing to show.\n";
    }
    else {
        for (int i = 0; i < count; i++) {
            cout << i + 1 << "| ";
            list[i].show();
        }
    }
}

void Menu::Edit() {
    Show_All();
    string back;
    int num;
    cout << "Enter the number of store" << endl;
    cin >> num;

    int num_ord;
    cout << "Enter the number of option" << endl;
    cin >> num_ord;
    list[num - 1].get_data()[num_ord - 1].rewrite();
}

void Menu::Add() {
    Price* price = new Price;
    price->rewrite();

    int num = -1;
    for (int i = 0; i < count; i++) {
        if (price->get_store() == list[i].get_store()) {
            num = i;
            break;
        }
    }
    if (num == -1) {
        Prices* backup = new Prices[count];
        for (int i = 0; i < count; i++) {
            backup[i] = list[i];
        }

        string name_payer;
        name_payer = price->get_store();

        list = new Prices[count + 1];
        list[count] = *(new Prices(name_payer));
        for (int i = 0; i < count; i++) {
            list[i] = backup[i];
        }
        count++;
        num = count - 1;
    }

    list[num].insert(price);
    sort_list(list, count);
}

void Menu::delete_price() {
    Show_All();
    cout << "Enter the number of store" << endl;
    int num;
    cin >> num;
    cout << "Enter the number of option" << endl;
    int ind;
    cin >> ind;
    if (list[num - 1].get_size() == 1)
        delete_prices(num - 1);
    else
        this->list[num - 1].remove(ind);
}

void Menu::delete_prices(int ind) {
    Prices backup;
    Prices* buff;
    for (int i = ind; i < count - 1; i++) {
        backup = list[i];
        list[i] = list[i + 1];
        list[i + 1] = backup;
    }
    buff = new Prices[count - 1];
    for (int i = 0; i < count - 1; i++) {
        buff[i] = list[i];
    }
    list = new Prices[count - 1];
    for (int i = 0; i < count - 1; i++) {
        list[i] = buff[i];
    }
    count--;
}

void Menu::Eject() {
    exit = 0;
}