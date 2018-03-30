/**
 * File name: customer.cpp
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

#include <list>
#include <string>
#include <fstream>
#include "customer.h"

using namespace std;

/**
 * This method will verify that the customer exists in the
 * hash table
 * 
 * @param  id: this is the customer id
 * @returns true if the customer was found, otherwise
 *               returns false
 */
bool Customer::customerExists(int id){
	return customerTable.exist(id); 
}

/**
 * This method adds a new customer to the customer table. 
 * @param id: the customer id
 * @param name: the customer name
 * @param action: the action in customer's history
 */
void Customer::addCustomer(int id, string name, string action){
	CustomerInfo newCustomer;
	newCustomer.setName(name);
	
	if(action != ""){
		newCustomer.addHistoryInfo(action);
	}
	customerTable.insert(id, newCustomer);
}

/**
 * This will search the customer and add the rental history
 * to the list
 * 
 * @param id: this is the customer id
 * @param action: this is the details of the rental action
 */
void Customer::addHistory(int id, string action){

	if(customerTable.exist(id)){	// customer does not exist
		CustomerInfo* temp = customerTable.findV(id);
		temp->addHistoryInfo(action);

	}	
}

/**
 * This is search the customer and display the list of the 
 * rental history
 * 
 * @param id: this is the customer id
 */
void Customer::displayHistory(int id){
	if(!customerTable.exist(id)){
		cout << "Customer not found." << endl;
	}
	else{
		customerTable.display(id);
	}
}

/**
 * This method will parse a file that contains the list
 * of customers in the store. This method will fill
 * out the customer hash table
 * 
 * @param filename: this is the file that will be parsed
 *                  that contains the customer id and name
 */
void Customer::buildCustomerTable(string filename){
	
	ifstream file2(filename);
	while(!file2.eof()){
		int customerID;
		file2 >> customerID;

		string customerName;
		getline(file2, customerName);

		CustomerInfo ci;
		ci.setName(customerName);

		customerTable.insert(customerID, ci);
	}
	file2.close();
}
