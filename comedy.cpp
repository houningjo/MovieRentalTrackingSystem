/**
 * File name: comedy.cpp
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/22/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the Comedy class is to hold the info of all the movies 
 * that are categorized in the Comedy genre. This class inherits from the Movie
 * class.
 * ---------------------------------------------------------------------------
 * This class inherits from the Movie class
 */

#include "comedy.h"

/**
 * This method is inherited as protected but in the child class
 * it will be set to private. This method will sort the movies
 * as they are inserted in the vector of movies
 * 
 * @param MovieAttributes the new movie that will be added to the
 * 								vector
 */
void Comedy::insert(const MovieAttributes ma)
{
	// TODO this is linear and can be improved to binary search
	// or change the vector to BST
	vector<MovieAttributes>::iterator it = movies.begin();
	for (; it != movies.end(); it++)
	{
		if (ma.title < it->title || (ma.title == it->title && ma.year < it->year))
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
void Comedy::addMovie(const string movieInfo)
{
	// this method assumes the input is correct
	// Comedy movie string:
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
void Comedy::display()
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
bool Comedy::borrowMovie(const string mediaData)
{
	// comedy mediaData is formatted like this:
	// title, year
	string title = "";
	int year = 0;
	MovieUtilities::comedyMediaData(mediaData, title, year);
	bool retstatus = false;
	
	for (auto &m : movies)
	{
		if (title == m.title && year == m.year)
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
bool Comedy::returnMovie(const string mediaData)
{
	// comedy mediaData is formatted like this:
	// title, year
	string title = "";
	int year = 0;
	MovieUtilities::comedyMediaData(mediaData, title, year);
	bool retstatus = false;
	
	for (auto &m : movies)
	{
		if (title == m.title && year == m.year)
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