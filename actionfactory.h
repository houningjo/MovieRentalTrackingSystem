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
#ifndef ACTION_FACTORY_H
#define ACTION_FACTORY_H

#include "action.h"

class ActionFactory
{
public:

	/**
	 * This is an enum with the types of Action objects available in the
	 * factory method. The ActionTypes will be used by the driver to pass
	 * the type of Action for the factory method to return and this member
	 * will also be used in the factory method switch case
	 */
	enum class ActionTypes {
		Borrow,
		Return,
		Inventory,
		History
	};

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
	static Action* createAction(ActionTypes at);
};

#endif