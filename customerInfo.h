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

using namespace std;

class CustomerInfo
{
protected:
    string name = "";
    list<string> historyList;
    
public:
	/**
	 * This method sets the customer's name to Cname.
	 * @param Cname: the passed in customer name
	 */
    void setName(string Cname);
    
    /**
     * This method add a history action of the customer.
     * @param action: the history action 
     */
    void addHistoryInfo(string action);
    
    /**
     * This method displays all history actions of the customer.
     */
    void displayHistoryList() const;
    
    /**
     * This method overloads the output operator for CustomerInfo object.
     * @param output: the output stream
     * @param ci: the reference CustomerInfo 
     */
    friend ostream& operator << (ostream& output, const CustomerInfo& ci);
};

