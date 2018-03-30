/**
 * File name: customer.h
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/25/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the Customer class is to implement a Hash Table to
 * store the customers. The Hash table will have the custoemr id as
 * the key and the customer info as the value. The customer value will be
 * a struct that holds the customer name and a list of rental history
 * ---------------------------------------------------------------------------
 * This class uses the following STD classes:
 * string
 * list
 * fstream
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <list>
#include <string>
#include <iterator>
#include "hashTable.h"
#include "customerInfo.h"

using namespace std;

class Customer
{
private:

	int size = 10;	// cannot be 0 due to 0 cannot be moded
	HashTable<int, CustomerInfo> customerTable;

public:

	Customer(int size) : size(size), customerTable(size){};

	/**
	 * This method will verify that the customer exists in the
	 * hash table
	 * 
	 * @param  id: this is the customer id
	 * @returns true if the customer was found, otherwise
	 *               returns false
	 */
	bool customerExists(int id);

	/**
	 * This method adds a new customer to the customer table. 
	 * @param id: the customer id
	 * @param name: the customer name
	 * @param action: the action in customer's history
	 */
	void addCustomer(int id, string name, string action = "");

	/**
	 * This will search the customer and add the rental history
	 * to the list
	 * 
	 * @param id: this is the customer id
	 * @param action: this is the details of the rental action
	 */
	void addHistory(int id, string action);

	/**
	 * This is search the customer and display the list of the 
	 * rental history
	 * 
	 * @param id: this is the customer id
	 */
	void displayHistory(int id);

	/**
	 * This method will parse a file that contains the list
	 * of customers in the store. This method will fill
	 * out the customer hash table
	 * 
	 * @param filename: this is the file that will be parsed
	 *                  that contains the customer id and name
	 */
	void buildCustomerTable(string filename);
	
};

#endif
