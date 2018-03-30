/**
 * File name: borrow.cpp
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

#include "borrow.h"

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
bool Borrow::doAction(Media*& mediaType, Customer*& customerTable, int customerID, string mediaData)
{
	if(!customerTable->customerExists(customerID))
	{
		return false;
	}

	if (mediaType->borrowMedia(mediaData))
	{
		string action = "Borrow " + mediaData;
		customerTable->addHistory(customerID, action);
		return true;
	}
	
	return false;
}