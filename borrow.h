/**
 * File name: borrow.h
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/24/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the Borrow class is to perform an action on the Media
 * inventory object. Borrow will check if the movie is available, if so
 * it will decrease the stock number by one.
 * ---------------------------------------------------------------------------
 * This class inherits from the Action class
 */
#ifndef BORROW_H
#define BORROW_H

#include "action.h"

class Borrow : public Action
{

public:

	/**
	 * This method will perform the Borrow action that will decrease 
	 * the number of the item in stock
	 *
	 * @param mediaType: this will be the Media object that the Action
	 *                   object will perform an action determined
	 *                   by the current Action object
	 *
	 * @param customerTable: the customer object will be used to add the
	 *                       rental history
	 * 
	 * @param customerID: this will determine the key to search the customer
	 *                    in the customer table
	 *
	 * @param mediaData: this string will contain the movie details
	 *
	 * @return returns true if the command was successful
	 */
	virtual bool doAction(Media*& mediaType, Customer*& customerTable, int customerID = -1, string mediaData = "") override;

};

#endif