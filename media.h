/**
 * File name: media.h
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/24/2018
 * Last Modified: 03/09/2018
 * ---------------------------------------------------------------------------
 * The purpose of the Media class is to provide a Media interface
 * for the media type classes, i.e., DVD, (future) BlueRay, (future) Music. 
 * This class defines the two public must have method for the Media derived
 * classes, to build and display the inventory
 * ---------------------------------------------------------------------------
 * This class uses the following STD classes:
 * string
 */
#ifndef MEDIA_H
#define MEDIA_H

#include <string>

using namespace std;

class Media
{

public:

	/**
	 * Pure virtual destructor so that derived classes will need
	 * to implement its own destructor to handle any pointers
	 * created in its class such as the pointer to the items
	 * of the inventory
	 */
	virtual ~Media() = 0;

	/**
	 * This method will open and read a file to the list of items
	 * the Media object should have in the inventory. Each derived
	 * class should handle its own parsing of the inventory files
	 * 
	 * @param fileName: this is the path and file name to the file
	 *                  that will be parsed. The file contains the
	 *                  list of items that will be inserted in the
	 *                  inventory
	 */
	virtual void buildMediaInventory(const string fileName) = 0;

	/**
	 * This method will display the inventory. Each derived class
	 * will implement displaying of the items in the inventory.
	 * An example would be to loop the data structure and use
	 * the iostream to cout the data. Each derived class should also
	 * handle the formatting of the data. Each item should be in
	 * a new line.
	 */
	virtual void displayMediaInventory() = 0;

	/**
	 * This method will use the passed in media data to find the movie
	 * if the movie is found and the stock shows available then it will
	 * decrease the stock number by one. Each derived class will
	 * implement the searching of the media.
	 * 
	 * @param  mediaData: is a string with the movie data to search
	 * 
	 * @returns true if the movie was found and stock was decreased by one
	 *               otherwise will return false
	 */
	virtual bool borrowMedia(const string mediaData) = 0;


	/**
	 * This method will use the passed in media data to find the movie
	 * if the movie is found and the stock is not max stock then it will
	 * increase the stock number by one. Each derived class will
	 * implement the searching of the media.
	 * 
	 * @param  mediaData: is a string with the movie data to search
	 * 
	 * @returns true if the movie was found and stock was increased by one
	 *               otherwise will return false
	 */
	virtual bool returnMedia(const string mediaData) = 0;
};

/**
 * Pure virtual destructor so that derived classes will need
 * to implement its own destructor to handle any pointers
 * created in its class such as the pointer to the items
 * of the inventory
 */
inline Media::~Media() {}

#endif