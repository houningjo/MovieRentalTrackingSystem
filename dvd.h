/**
 * File name: dvd.h
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/22/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the DVD class is to hold the inventory of all the available 
 * Movies. The Movies will be contained in a data structure. This class inherits 
 * from the Media class.
 * ---------------------------------------------------------------------------
 * This class inherits from the Movie class
 * This class uses the following STD classes:
 * fstream
 */
#ifndef DVD_H
#define DVD_H

#include "media.h"
#include "movie.h"

using namespace std;

class DVD : public Media
{
private:

	/**
	 * The vector will hold a Movie pointer. The data structure should
	 * look like this:
	 * [   0   ][   1  ][    2   ]
	 * [Comedy*][Drama*][Classic*]
	 * Each Movie object will contain its own data structure holding the
	 * list of movies in its category.
	 */
	vector<Movie*> dvds;
public:

	DVD();

	/**
	 * The destructor will loop the data structure that holds
	 * the Movie pointer objects and delete them
	 */
	~DVD();

	/**
	 * This method will open and read a file to the list of items
	 * the Media object should have in the inventory. A Movie obj
	 * will be created for each line that contains a valid Movie
	 * item. 
	 * 
	 * @param fileName: this is the path and file name to the file
	 *                  that will be parsed. The file contains the
	 *                  list of items that will be inserted in the
	 *                  inventory
	 */
	virtual void buildMediaInventory(const string fileName) override;

	/**
	 * This method will loop the data structure holding the Movie objs
	 * and display each item. This method will format and use the
	 * iostream cout to display each Movie in the data structure.
	 */
	virtual void displayMediaInventory() override;

	/**
	 * This method will use the passed in media data to find the movie
	 * if the movie is found and the stock shows available then it will
	 * decrease the stock number by one
	 * 
	 * @param  mediaData: is a string with the movie data to search
	 * 
	 * @returns true if the movie was found and stock was decreased by one
	 *               otherwise will return false
	 */
	virtual bool borrowMedia(const string mediaData) override;

	/**
	 * This method will use the passed in media data to find the movie
	 * if the movie is found and the stock is not max stock then it will
	 * increase the stock number by one
	 * 
	 * @param  mediaData: is a string with the movie data to search
	 * 
	 * @returns true if the movie was found and stock was increased by one
	 *               otherwise will return false
	 */
	virtual bool returnMedia(const string mediaData) override;
};

#endif