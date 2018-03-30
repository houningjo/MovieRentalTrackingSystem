/**
 * File name: mediafactory.cpp
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/24/2018
 * Last Modified: 03/09/2018
 * ---------------------------------------------------------------------------
 * The purpose of the MediaFactory class is to provide a Media type selector 
 * using a factory method. The class provides the types of Media objects that
 * can be returned. The driver calls the static function and passes the type
 * of object to return and the factory method will select and return the
 * specified object.
 * ---------------------------------------------------------------------------
 * This class uses the following STD classes:
 */


#include "mediafactory.h"
#include "dvd.h"

#include <iostream>
using namespace std;
/**
 * This is a factory method that receives a MediaTypes that determines
 * the type of object the driver wants to receive. The factory method 
 * uses a switch case to determine which object to return
 * 
 * @param MediaTypes: this is the type of Media that the driver
 *                    wants to receive
 *                
 * @return Media*: the return object is an object derived from the
 *                 Media class
 */
Media* MediaFactory::createMedia(MediaTypes mt)
{
	switch (mt)
	{
		case MediaTypes::DVDType:
			return new DVD;
	}

	return nullptr;
}