/**
 * File name: movieutilities.h
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
#ifndef MOVIE_UTILITIES_H
#define MOVIE_UTILITIES_H

#include <string>

using namespace std;

class MovieUtilities
{
private:

	/**
	 * firstcommaPos determines the position of the first comma
	 * in the movieInfo string
	 */
	int firstcommaPos = 0;

	/**
	 * seccommaPos determines the position of the second comma
	 * in the movieInfo string
	 */
	int seccommaPos = 0;

	/**
	 * thirdcommaPos determines the position of the third comma
	 * in the movieInfo string
	 */
	int thirdcommaPos = 0;

	/**
	 * firstrightPos determines the position of the first space
	 * from right to left in the movieInfo string
	 */
	int firstrightPos = 0;

	/**
	 * secrightPos determines the position of the second space
	 * from right to left in the movieInfo string
	 */
	int secrightPos = 0;

	/**
	 * determines if the movie info is a classic movie, it is
	 * set in the constructor
	 */
	bool isClassic = false;

	/**
	 * it is the movie info string, it is set in the constructor
	 */
	string movieInfo = "";

	/**
	 * This method finds the position of the commas in the movie info
	 * string and sets the firstcommaPos, seccommaPos, thirdcommaPos
	 */
	void setCommaPositions();

	/**
	 * This method finds the position of the spaces, in the classic
	 * movie info, that are from right to left. This sets the 
	 * firstrightPos, secrightPos
	 */
	void setSpacePositions();

	/**
	 * Removes a trailing space in the first char of the string
	 * @param  field the string to verify if it contains a trailing space
	 * @return the same string if it does not contain a trailing space
	 *         but returns a new string when a trailing space is found to remove it
	 */
	static string removeFrontSpace(const string field);

public:

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
	MovieUtilities(const string movieInfo, const bool isClassic);

	/**
	 * Parses the movieInfo string to get the stock number
	 * @return the stock integer
	 */
	int getStock();

	/**
	 * Parses the movieInfo string to get the director field
	 * @return the director string field
	 */
	string getDirector();

	/**
	 * Parses the movieInfo string to get the title field
	 * @return the title string field
	 */
	string getTitle();

	/**
	 * Parses the movieInfo string to get the actor field
	 * This method is only used in the classic class
	 * @return the actor string field
	 */
	string getActor();

	/**
	 * Parses the movieInfo string to get the month field
	 * This method is only used in the classic class
	 * @return the month integer field
	 */
	int getMonth();

	/**
	 * Parses the movieInfo string to get the year field
	 * @return the year integer field
	 */
	int getYear();

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
	static void comedyMediaData(string mediaData, string &title, int &year);

	/**
	 * static function used in the drama class to parse the media data
	 * in the borrow and return methods of the drama class. This function
	 * parses the string mediaData and copies the value of the director field
	 * to the director parameter and copies the value of the title field to
	 * the title parameter.
	 * 
	 * @param mediaData string that holds the mediaData formatted:
	 *                  title, year
	 * @param director  reference string, that returns the value of
	 *                  the director field
	 * @param title     reference int, that returns the value of the
	 *                  title field
	 */
	static void dramaMediaData(string mediaData, string &director, string &title);

	/**
	 * static function used in the classic class to parse the media data
	 * in the borrow and return methods of the classic class. This function
	 * parses the string mediaData and copies the value of the month field
	 * to the month parameter and copies the value of the year field to
	 * the year parameter and copies the value of the actor field to the
	 * actor parameter.
	 * 
	 * @param mediaData string that holds the mediaData formatted:
	 *                  title, year
	 * @param month     reference int, that returns the value of
	 *                  the month field
	 * @param year      reference int, that returns the value of
	 *                  the year field
	 * @param actor     reference string, that returns the value of
	 *                  the actor field
	 */
	static void dramaMediaData(string mediaData, int &month, int &year, string &actor);
};

#endif