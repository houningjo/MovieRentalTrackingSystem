/**
* File name: drama.cpp
* Author name: Ning Hou, Erika Portilla
* Course: CSS502
* Date: 02/22/2018
* Last Modified:
* ---------------------------------------------------------------------------
* The purpose of the Drama class is to hold the info of all the movies 
* that are categorized in the Drama genre. This class inherits from the Movie
* class.
* ---------------------------------------------------------------------------
* This class inherits from the Movie class
*/

#include "drama.h"

/**
 * This method is inherited as protected but in the child class
 * it will be set to private. The default sorting is provided by the
 * parent class and the Drama class does not need any special sorting.
 * 
 * @param MovieAttributes the new movie that will be added to the
 * 								vector
 */
void Drama::insert(const MovieAttributes ma)
{
	vector<MovieAttributes>::iterator it = movies.begin();
	for (; it != movies.end(); it++)
	{
		if (ma.director < it->director || (ma.director == it->director && ma.title < it->title))
		{
			movies.insert(it, ma);
			return;
		}
	}

	movies.push_back(ma);
}

/**
 * This method is inherited from the parent class. This is the public 
 * method that will receive the movie details to add to the class 
 * object. The parameters are the MovieAttributes as defined by the 
 * MovieAttributes struct. 
 *
 * @param movieInfo: this will contain the movie details, such as
 *                   title, director, release year, etc. This string
 *                   will be parsed to fill in the MovieAttributes
 */
void Drama::addMovie(const string movieInfo)
{
	// this method assumes the input is correct
	// Drama movie string:
	// stock number, director, title, release year
	
	// using substr to parse the string
	// using find to get the comma positions
	// using stoi to convert string to int
	
	MovieAttributes newMovie;
	MovieUtilities mu(movieInfo, false);

	// convert the stock string to integer
	int stock = mu.getStock();
	newMovie.stock = stock;
	newMovie.maxStock = stock;

	// get the director substring
	newMovie.director = mu.getDirector();

	// get the title substring
	newMovie.title = mu.getTitle();

	// convert the year string to integer
	newMovie.year = mu.getYear();

	// insert the movie in the correct position by sorting title and year
	insert(newMovie);
}

/**
 * This method is inherited from the parent class. This method will
 * loop and display the vector movie values. 
 */
void Drama::display()
{
	for (auto &m : movies)
	{
		cout << m.stock << ", ";
		cout << m.director << ", ";
		cout << m.title << ", ";
		cout << m.year << endl;
	}
}

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
bool Drama::borrowMovie(const string mediaData)
{
	// drama mediaData is formatted like this:
	// director, title,
	string director = "";
	string title = "";
	MovieUtilities::dramaMediaData(mediaData, director, title);
	bool retstatus = false;
	for (auto &m : movies)
	{
		if (director == m.director && title == m.title)
		{
			if (m.stock > 0)
			{
				m.stock--;
				retstatus = true;
			}

			break;
		}
	}

	return retstatus;
}

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
bool Drama::returnMovie(const string mediaData)
{
	// drama mediaData is formatted like this:
	// director, title,
	string director = "";
	string title = "";
	MovieUtilities::dramaMediaData(mediaData, director, title);
	bool retstatus = false;
	
	for (auto &m : movies)
	{
		if (director == m.director && title == m.title)
		{
			if (m.stock < m.maxStock)
			{
				m.stock++;
				retstatus = true;
			}

			break;
		}
	}

	return retstatus;
}