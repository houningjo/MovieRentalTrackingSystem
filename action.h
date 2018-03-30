/**
 * File name: action.h
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/24/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the Action class is to provide an Action interface
 * for the action type classes, i.e., Borrow, Return, Inventory and
 * History. This class defines the public function that the derived
 * classes must have.
 * ---------------------------------------------------------------------------
 * This class uses the following STD classes:
 * string
 */
#ifndef ACTION_H
#define ACTION_H

#include <string>
#include "media.h"
#include "customer.h"

using namespace std;

class Action
{

public:

	/**
	 * Pure virtual destructor so that derived classes will need
	 * to implement its own destructor to handle any pointers
	 * created in its class such as the pointer to the items
	 * of the inventory
	 */
	virtual ~Action() = 0;

	/**
	 * This method will determine the action that the Action derived
	 * classes will make, e.g., Borrow will decrease the number of the
	 * item in stock, Return will increase the number of the item in
	 * stock
	 *
	 * @param mediaType: this will be the Media object that the Action
	 *                   object will perform an action determined
	 *                   by the current Action object
	 * 
	 * @param customerID: the default value is -1 determining that the
	 *                    customer ID is optional parameter and is not
	 *                    used for all actions. The customer ID will be
	 *                    used for Borrow, Return and History
	 *
	 * @param customerTable: this is the customer table that contains
	 *                       all of the customers. This is used to store
	 *                       the rental history
	 *
	 * @param mediaData: optional parameter that will be used for some actions
	 *                   such as Borrow and Return. This string will contain
	 *                   the search values of the media item , e.g., movie
	 *                   attributes such as title, director, release year, etc
	 *
	 * @return returns true if the command was successful
	 *
	 */
	virtual bool doAction(Media*& mediaType, Customer*& customerTable, int customerID = -1, string mediaData = "") = 0;

};

inline Action::~Action() {}

#endif