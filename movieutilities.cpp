/**
 * File name: movieutilities.cpp
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 03/11/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the MovieUtilities class is to provide string parse
 * functions of movie commands and movie information strings. The functions 
 * will parse and return the pertaining movie field.
 * ---------------------------------------------------------------------------
 * This class uses the following STD classes:
 * string
 * ---------------------------------------------------------------------------
 * This class includes static functions to parse the media data in the command
 * strings. These functions are static because the string contains less fields
 * than the movieInfo.
 * The movieInfo is a class that has to be instantiated. The constructor will
 * receive the movieInfo string and a boolean to distinguish classic movies
 * since it requires spaces between fields
 */

#include "movieutilities.h"

/**
 * Constructor that sets the private members by setting the movieInfo
 * string and the boolean isClassic. It calls the setCommaPositions
 * and setSpacePositions
 *
 * @param movieInfo: is the string holding the movie info
 *
 * @param isClassic: is the boolean that determines if the current
 *                   movie is a classic movie
 */
MovieUtilities::MovieUtilities(const string movieInfo, const bool isClassic)
{
	this->movieInfo = movieInfo;
	this->isClassic = isClassic;

	setCommaPositions();
	if (isClassic) setSpacePositions();
}

/**
 * This method finds the position of the commas in the movie info
 * string and sets the firstcommaPos, seccommaPos, thirdcommaPos
 */
void MovieUtilities::setCommaPositions()
{
	firstcommaPos = movieInfo.find(',');
	seccommaPos = movieInfo.find(',', firstcommaPos + 1);
	thirdcommaPos = movieInfo.find(',', seccommaPos + 1);
}

/**
 * This method finds the position of the spaces, in the classic
 * movie info, that are from right to left. This sets the 
 * firstrightPos, secrightPos
 */
void MovieUtilities::setSpacePositions()
{
	firstrightPos = movieInfo.find_last_of(' ');
	secrightPos = movieInfo.find_last_of(' ', firstrightPos - 1);
}

/**
 * Removes a trailing space in the first char of the string
 * @param  field the string to verify if it contains a trailing space
 * @return the same string if it does not contain a trailing space
 *         but returns a new string when a trailing space is found to remove it
 */
string MovieUtilities::removeFrontSpace(const string field)
{
	string retStr = "";
	if (field.at(0) == ' ') retStr = field.substr(1);
	else retStr = field;

	string whitespaces(" \t\f\v\n\r");
	int pos = retStr.find_last_not_of(whitespaces);
	if (pos != string::npos)
	{
		retStr.erase(pos + 1);
	}

	return retStr;
}

/**
 * Parses the movieInfo string to get the stock number
 * @return the stock integer
 */
int MovieUtilities::getStock()
{
	return stoi(movieInfo.substr(0, firstcommaPos));
}

/**
 * Parses the movieInfo string to get the director field
 * @return the director string field
 */
string MovieUtilities::getDirector()
{	
	return removeFrontSpace(movieInfo.substr(firstcommaPos + 1, seccommaPos - firstcommaPos - 1));
}

/**
 * Parses the movieInfo string to get the title field
 * @return the title string field
 */
string MovieUtilities::getTitle()
{
	return removeFrontSpace(movieInfo.substr(seccommaPos + 1, thirdcommaPos - seccommaPos - 1));
}

/**
 * Parses the movieInfo string to get the actor field
 * This method is only used in the classic class
 * @return the actor string field
 */
string MovieUtilities::getActor()
{
	return removeFrontSpace(movieInfo.substr(thirdcommaPos + 1, secrightPos - thirdcommaPos - 1));
}

/**
 * Parses the movieInfo string to get the month field
 * This method is only used in the classic class
 * @return the month integer field
 */
int MovieUtilities::getMonth()
{
	return stoi(movieInfo.substr(secrightPos + 1, firstrightPos - secrightPos - 1));
}

/**
 * Parses the movieInfo string to get the year field
 * @return the year integer field
 */
int MovieUtilities::getYear()
{
	int year = 0;

	if (isClassic)
	{
		year = stoi(movieInfo.substr(firstrightPos + 1));
	}
	else
	{
		year = stoi(movieInfo.substr(thirdcommaPos + 1));
	}

	return year;
}

/**
 * static function used in the comedy class to parse the media data
 * in the borrow and return methods of the comedy class. This function
 * parses the string mediaData and copies the value of the title field
 * to the title parameter and copies the value of the year field to
 * the year parameter.
 * 
 * @param mediaData string that holds the mediaData formatted:
 *                  title, year
 * @param title     reference string, that returns the value of
 *                  the title field
 * @param year      reference int, that returns the value of the
 *                  year field
 */
void MovieUtilities::comedyMediaData(string mediaData, string &title, int &year)
{
	int commaPos = mediaData.find(',');
	title = removeFrontSpace(mediaData.substr(0, commaPos));
	year = stoi(mediaData.substr(commaPos + 1));
}

/**
 * static function used in the drama class to parse the media data
 * in the borrow and return methods of the drama class. This function
 * parses the string mediaData and copies the value of the director field
 * to the director parameter and copies the value of the title field to
 * the title parameter.
 * 
 * @param mediaData string that holds the mediaData formatted:
 *                  director, title
 * @param director  reference string, that returns the value of
 *                  the director field
 * @param title     reference int, that returns the value of the
 *                  title field
 */
void MovieUtilities::dramaMediaData(string mediaData, string &director, string &title)
{
	int commaPos = mediaData.find(',');
	int lastcommaPos = mediaData.find_last_of(',');
	director = removeFrontSpace(mediaData.substr(0, commaPos));
	// remove the last comma
	// did not use length because there can be space after the last comma
	// so find the last comma position and remove it by - 1 in the substr
	title = removeFrontSpace(mediaData.substr(commaPos + 1, lastcommaPos - commaPos - 1));
}

/**
 * static function used in the classic class to parse the media data
 * in the borrow and return methods of the classic class. This function
 * parses the string mediaData and copies the value of the month field
 * to the month parameter and copies the value of the year field to
 * the year parameter and copies the value of the actor field to the
 * actor parameter.
 * 
 * @param mediaData string that holds the mediaData formatted:
 *                  month year actor
 * @param month     reference int, that returns the value of
 *                  the month field
 * @param year      reference int, that returns the value of
 *                  the year field
 * @param actor     reference string, that returns the value of
 *                  the actor field
 */
void MovieUtilities::dramaMediaData(string mediaData, int &month, int &year, string &actor)
{
	int startingPos = 0;
	if (mediaData.at(0) == ' ') startingPos = 1;
	int firstPos = mediaData.find(' ', startingPos);
	int secPos = mediaData.find(' ', firstPos + 1);
	month = stoi(mediaData.substr(0, firstPos));
	year = stoi(mediaData.substr(firstPos + 1, secPos));
	actor = removeFrontSpace(mediaData.substr(secPos + 1));
}