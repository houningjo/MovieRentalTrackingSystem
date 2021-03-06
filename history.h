/**
 * File name: history.h
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/24/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the History class is to perform an action on the Customer
 * table object. History will diplay the customer's rental history
 * ---------------------------------------------------------------------------
 * This class inherits from the Action class
 */
#ifndef HISTORY_H
#define HISTORY_H

#include "action.h"

class History : public Action
{

public:

	/**
	 * This method will perform display the customer
	 * history that will increase the number of the item in stock
	 *
	 * @param mediaType: this object will not be used, it will be null
	 *                   for the History action
	 *
	 * @param customerTable: the customer object will be used to add the
	 *                       rental history
	 * 
	 * @param customerID: this will determine the key to search the customer
	 *                    in the customer table
	 *
	 * @param mediaData: this string will be empty, it will not be used for the 
	 *                   History action
	 *
	 */
	virtual bool doAction(Media*& mediaType, Customer*& customerTable, int customerID = -1, string mediaData = "");
};

#endif