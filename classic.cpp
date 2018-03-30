/**
* File name: classic.cpp
* Author name: Ning Hou, Erika Portilla
* Course: CSS502
* Date: 02/22/2018
* Last Modified:
* ---------------------------------------------------------------------------
* The purpose of the Classic class is to hold the info of all the movies 
* that are categorized in the CLassic genre. This class inherits from the Movie
* class.
* ---------------------------------------------------------------------------
* This class inherits from the Movie class
*/

#include "classic.h"

/**
 * This method is inherited as protected but in the child class
 * it will be set to private. This class needs to implement its
 * own sorting since the classic genre is sorted differently than
 * the default sorting by using the release date and then the 
 * major actor.
 * 
 * @param MovieAttributes the new movie that will be added to the
 * 								vector
 */
void Classic::insert(const MovieAttributes ma)
{
	vector<MovieAttributes>::iterator it = movies.begin();
	for (; it != movies.end(); it++)
	{
		// if it is the same movie insert the actor in the list and update the movie stock
		if (ma.director == it->director && ma.title == it->title &&
			 ma.year == it->year && ma.month == it->month)
		{
			// update the movie stock
			it->stock += ma.stock;
			it->maxStock += ma.maxStock;

			list<string>::iterator actor_it = it->actors.begin();
			bool inserted = false;
			for (; actor_it != it->actors.end(); actor_it++)
			{
				// sort the actors in the list
				if (ma.actors.front() < *actor_it)
				{
					it->actors.insert(actor_it, ma.actors.front());
					inserted = true;
					break;
				}
			}

			// insert in the last place if the actor was not inserted in the loop
			if (!inserted)
			{
				it->actors.push_back(ma.actors.front());
			}

			return;
		}
		// if the movie does not exist then look where to place the movie
		else if ((ma.year < it->year || (ma.year <= it->year && ma.month < it->month)) ||
			((ma.year <= it->year && ma.month <= it->month) && ma.actors.front() <= it->actors.front()))
		{
			movies.insert(it, ma);
			return;
		}
	}

	// if the movie was not inserted then insert in the back of the vector
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
void Classic::addMovie(const string movieInfo)
{
	// this method assumes the input is correct
	// Classic movie string:
	// stock number, director, title, majoractor month year
	
	MovieAttributes newMovie;
	MovieUtilities mu(movieInfo, true);

	// convert the stock string to integer
	int stock = mu.getStock();
	newMovie.stock = stock;
	newMovie.maxStock = stock;

	// get the director substring
	newMovie.director = mu.getDirector();

	// get the title substring
	newMovie.title = mu.getTitle();

	newMovie.actors.push_back(mu.getActor());

	// convert the month string to integer
	newMovie.month = mu.getMonth();

	// convert the year string to integer
	newMovie.year = mu.getYear();

	// insert the movie in the correct position by sorting title and year
	insert(newMovie);
}

/**
 * This method is inherited from the parent class. This method will
 * loop and display the vector movie values. 
 */
void Classic::display()
{
	for (auto &m : movies)
	{
		list<string>::iterator it = m.actors.begin();
		for (; it != m.actors.end(); it++)
		{
			cout << m.stock << ", ";
			cout << m.director << ", ";
			cout << m.title << ", ";
			cout << *it << " ";
			cout << m.month << " ";
			cout << m.year << endl;
		}
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
bool Classic::borrowMovie(const string mediaData)
{
	// classic mediaData is formatted like this:
	// month year actor
	int month = 0;
	int year = 0;
	string actor = "";
	MovieUtilities::dramaMediaData(mediaData, month, year, actor);
	bool retstatus = false;
	
	for (auto &m : movies)
	{
		if (month == m.month && year == m.year)
		{
			list<string>::iterator it = m.actors.begin();
			for (; it != m.actors.end(); it++)
			{
				if (*it == actor)
				{
					if (m.stock > 0)
					{
						m.stock--;
						retstatus = true;
					}

					return retstatus;
				}
			}
		}
		else if (m.month > month && m.year > year) break;
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
bool Classic::returnMovie(const string mediaData)
{
	// classic mediaData is formatted like this:
	// month year actor
	int month = 0;
	int year = 0;
	string actor = "";
	MovieUtilities::dramaMediaData(mediaData, month, year, actor);
	bool retstatus = false;
	
	for (auto &m : movies)
	{
		if (month == m.month && year == m.year)
		{
			list<string>::iterator it = m.actors.begin();
			for (; it != m.actors.end(); it++)
			{
				if (actor == *it)
				{
					if (m.stock < m.maxStock)
					{
						m.stock++;
						retstatus = true;
					}

					return retstatus;
				}
			}
		}
		else if (m.month > month && m.year > year) break;
	}

	return retstatus;
}
