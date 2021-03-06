/**
 * File name: drama.h
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
#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama : public Movie
{
private:

	/**
	 * This method is inherited as protected but in the child class
	 * it will be set to private. The default sorting is provided by the
	 * parent class and the Drama class does not need any special sorting.
	 * 
	 * @param MovieAttributes the new movie that will be added to the
	 * 								vector
	 */
	virtual void insert(const MovieAttributes ma) override;

public:

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
	virtual void addMovie(const string movieInfo) override;

	/**
	 * This method is inherited from the parent class. This method will
	 * loop and display the vector movie values. 
	 */
	virtual void display() override;
	
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
	virtual bool borrowMovie(const string mediaData) override;

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
	virtual bool returnMovie(const string mediaData) override;
	
};

#endif