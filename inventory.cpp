/**
 * File name: inventory.h
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/24/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the Inventory class is to display all of the Media
 * items in the inventory
 * ---------------------------------------------------------------------------
 * This class inherits from the Action class
 */

#include "inventory.h"

/**
 * This method will display all of the items in the media object
 * inventory
 *
 * @param mediaType: this will be the Media object that the Action
 *                   object will perform an action determined
 *                   by the current Action object
 *
 * @param customerTable: the customer object will not be used for the
 *                       inventory action
 * 
 * @param customerID: the customer id will not be used for the inventory
 *                    action
 *
 * @param mediaData: this string will be empty, it will not be used for the 
 *                   Inventory action
 *
 */
bool Inventory::doAction(Media*& mediaType, Customer*& customerTable, int customerID, string mediaData)
{
	mediaType->displayMediaInventory();

	return true;
}