#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include "card.h"
#include <iostream>
#include <vector>
using namespace std;

class CardManager{
private:
    vector<Card*> myclasses;    //STL Vector사용, stack..
    string name;
    int count;          //총 이수과목
    int total_credit;   
    double gpa;
public:
    CardManager(){
        count=0; total_credit=0;
    }
    ~CardManager();
    int getCount(){return count;}
    int getAllCredit(){return total_credit;}
    double getGpa(){return gpa;};

    void printAll(); // Print all cards
    void findCards(string name); // Search a card by name from all cards
    void loadCards(string filename);
    void sortByCode();
    void addCard(); // Add a card
    void editCard(); // Change grade of a card
    void Filter();  //#8
    void Save();    //#9
};

#endif