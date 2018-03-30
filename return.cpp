/**
 * File name: return.h
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/24/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the Return class is to perform an action on the Media
 * inventory object. Return will check if the movie exists, if so
 * it will increase the stock number by one.
 * ---------------------------------------------------------------------------
 * This class inherits from the Action class
 */

#include "return.h"

/**
 * This method will perform the return action that will increase 
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
 */
bool Return::doAction(Media*& mediaType, Customer*& customerTable, int customerID, string mediaData)
{
	if(!customerTable->customerExists(customerID))
	{
		return false;
	}

	if (mediaType->returnMedia(mediaData))
	{
		string action = "Return " + mediaData;
		customerTable->addHistory(customerID, action);
		return true;
	}
	
	return false;
}