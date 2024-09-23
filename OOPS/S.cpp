#include<bits/stdc++.h>
using namespace std;

/* S: single responsibilty principle
it mean there should only have a reason to change for example
*/

class Marker{
    public:
    string name;
    string color;
    int year;
    int price;
    Marker(string name,string color,int year,int price){
        this->name=name;
        this->color=color;
        this->price=price;
        this->year=year;
    }
    Marker(){
        
    }
};

class Invoice{
    private:
    Marker marker;
    int quantity;

    public:
    Invoice(Marker marker,int quantity){
        this->marker=marker;
        this->quantity=quantity;
    }

    //we need to calculate the total amount...but if there is a chnage in calc then we need to make chnages in class

    int total(){
        int price=((marker.price)*this->quantity);
        return price;
    }

    //function fr printing and for saving to db

    void print(){

    }
    void save(){

    }
};
//if we want to save different db then we need to change in inoice class as well as i fhtere is chnage in print func then we need to chnage incice class

//to solve this we will create function for this print and save seprate

class Invoiceprint{
    private:
    Invoice invoice;

    public:
    void print(Invoice invoice){
        this->invoice=invoice;
    }
};
//similarly with db save
