/**
 * File name: actionfactory.h
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/24/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the ActionFactory class is to provide an Action type selector 
 * using a factory method. The class provides the types of Action objects that
 * can be returned. The driver calls the static function and passes the type
 * of object to return and the factory method will select and return the
 * specified object.
 * ---------------------------------------------------------------------------
 * This class uses the following STD classes:
 */

#include "actionfactory.h"
#include "borrow.h"
#include "return.h"
#include "inventory.h"
#include "history.h"

/**
 * This is a factory method that receives a ActionTypes that determines
 * the type of object the driver wants to receive. The factory method 
 * uses a switch case to determine which object to return
 * 
 * @param ActionTypes: this is the type of Action that the driver
 *                    wants to receive
 *                
 * @return Action: the return object is an object derived from the
 *                 Action class
 */
Action* ActionFactory::createAction(ActionTypes at)
{
	switch(at)
	{
		case ActionTypes::Borrow:
			return new Borrow;

		case ActionTypes::Return:
			return new Return;

		case ActionTypes::Inventory:
			return new Inventory;

		case ActionTypes::History:
			return new History;
	}

	return nullptr;
}
