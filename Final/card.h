#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card{
private:
    string code;
    string name;
    int credit;
    string grade;
    double score;
    
public:
    Card(string code, string name, int credit); 
    Card(string code, string name, int credit, string grade);
    Card(Card* card, string grade);
    ~Card(){};
    void setGrade(string newgrade); //새로추가
    string getGrade(){return grade;};   //새로추가
    string getCode(){return code;};
    string getName(){return name;};
    int getCredit(){return credit;};
    string toString();
    string toStringShort();
    double getScore(){return score;};

    static bool cmpCode(Card* c1, Card* c2){
        return (c1->getCode() < c2->getCode());     //과목 코드끼지 대소비교. 
    }
};
#endif