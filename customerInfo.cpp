/**
 * File name: customerInfo.cpp
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/25/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the CustomerInfo class will hold the customers name and the
 * list of the rental history. The class will be the value of the Hash table.
 * ---------------------------------------------------------------------------
 * This class uses the following STD classes:
 * string
 * list
 * iterator
 */
#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "customerInfo.h"

using namespace std;

/**
 * This method sets the customer's name to Cname.
 * @param Cname: the passed in customer name
 */
void CustomerInfo::setName(string Cname){
    name = Cname;
}

/**
 * This method add a history action of the customer.
 * @param action: the history action 
 */
void CustomerInfo::addHistoryInfo(string action){
    list<string>::iterator it;
    it = historyList.begin();
    historyList.insert(it, action);
}

/**
 * This method displays all history actions of the customer.
 */
void CustomerInfo::displayHistoryList() const{
    cout << name << endl;
    
    list<string>::const_iterator it2;
    
    for (it2 = historyList.begin(); it2 != historyList.end(); it2++){
        cout << *it2 << endl;
    }
    cout << endl;
}

/**
 * This method overloads the output operator for CustomerInfo object.
 * @param output: the output stream
 * @param ci: the reference CustomerInfo 
 */
ostream& operator << (ostream& output, const CustomerInfo& ci){
    
    ci.displayHistoryList();
    
    return output;
}

