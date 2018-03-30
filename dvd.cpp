/**
 * File name: dvd.cpp
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

#include "dvd.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"
#include <fstream>

DVD::DVD()
{
	Movie *comedy = new Comedy;
	dvds.push_back(comedy);
	
	Movie *drama = new Drama;
	dvds.push_back(drama);
	
	Movie *classic = new Classic;
	dvds.push_back(classic);
}

/**
 * The destructor will loop the data structure that holds
 * the Movie pointer objects and delete them
 */
DVD::~DVD()
{
	for (auto &d : dvds)
	{
		delete d;
	}
}

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
void DVD::buildMediaInventory(const string fileName)
{
	ifstream file(fileName);
	if (!file)
	{
		cout << "Error: Could not open movie file." << endl;
		return;
	}

	string line;

	while (getline(file, line))
	{
		switch (line.at(0))
		{
			// comedy
			case 'F':
				dvds[0]->addMovie(line.substr(2));
				break;

			//drama
			case 'D':
				dvds[1]->addMovie(line.substr(2));
				break;

			// classic
			case 'C':
				dvds[2]->addMovie(line.substr(2));
				break;
		}
	}
}

/**
 * This method will loop the data structure holding the Movie objs
 * and display each item. This method will format and use the
 * iostream cout to display each Movie in the data structure.
 */
void DVD::displayMediaInventory()
{
	for (auto &d : dvds)
	{
		d->display();
	}
}

/**
 * This method will use the passed in media data to find the movie
 * if the movie is found and the stock shows available then it will
 * decrease the stock number by one. The expected string input is
 * formatted: MovieChar Title,year, eg "F You've Got Mail,1998"
 * 
 * @param  mediaData: is a string with the movie data to search
 * 
 * @returns true if the movie was found and stock was decreased by one
 *               otherwise will return false
 */
bool DVD::borrowMedia(const string mediaData)
{
	bool retstatus = false;

	switch(mediaData.at(0))
	{
		// comedy
		case 'F':
			retstatus = dvds[0]->borrowMovie(mediaData.substr(1));
			break;

		//drama
		case 'D':
			retstatus = dvds[1]->borrowMovie(mediaData.substr(1));
			break;

		// classic
		case 'C':
			retstatus = dvds[2]->borrowMovie(mediaData.substr(1));
			break;
	}
	
	return retstatus;
}

/**
 * This method will use the passed in media data to find the movie
 * if the movie is found and the stock is not max stock then it will
 * increase the stock number by one. The expected string input is
 * formatted: MovieChar Title,year, eg "F You've Got Mail,1998"
 * 
 * @param  mediaData: is a string with the movie data to search
 * 
 * @returns true if the movie was found and stock was increased by one
 *               otherwise will return false
 */
bool DVD::returnMedia(const string mediaData)
{
	bool retstatus = false;

	switch(mediaData.at(0))
	{
		// comedy
		case 'F':
			retstatus = dvds[0]->returnMovie(mediaData.substr(1));
			break;

		//drama
		case 'D':
			retstatus = dvds[1]->returnMovie(mediaData.substr(1));
			break;

		// classic
		case 'C':
			retstatus = dvds[2]->returnMovie(mediaData.substr(1));
			break;
	}
	
	return retstatus;
}