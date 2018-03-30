/**
 * File name: movie.h
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/22/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the Movie class is to provide a Movie interface
 * for the genre classes. This class defines a struct that defines the
 * movie attributes (i.e., title, director, year, etc) and a container
 * to store the movies that are available. The interface provides protected 
 * data members and public and protected methods.
 * ---------------------------------------------------------------------------
 * This class uses the following STD classes:
 * vector
 * string
 * list
 * iostream
 */
#ifndef MOVIE_H
#define MOVIE_H

#include <vector>
#include <string>
#include <list>
#include <iostream>
#include "movieutilities.h"

using namespace std;

class Movie
{
protected:

	/**
	 * This struct defines the movie attributes that the genre classes
	 * will inherit. The movie attributes define the movies that
	 * pertain for that genre class
	 * stock: holds the number of copies this movie has available
	 * director: the name of the director of the movie
	 * title: the title of the movie
	 * year: the year the movie was released
	 * month: the month the movie was released (optional, not all classes
	 * 			will use this)
	 * actors: is a list of actors that appear in the movie (optional, not all classes
	 * 			will use this)
	 */
	struct MovieAttributes
	{
		int stock = 0;
		int maxStock = 0;
		string director = "";
		string title = "";
		int year = 0;
		int month = 0;
		list<string> actors;

	};

	/**
	 * Each entry in the vector is a movie. This genre classes will use this
	 * container to hold all the movies available for that genre object
	 */
	vector<MovieAttributes> movies;

	/**
	 * This is a pure virtual sort method that each class will need to 
	 * define its own sorting. The sort method will be used when a new
	 * movie_attribute is inserted in the vector.
	 * @param MovieAttributes the new movie that will be added to the
	 * 								vector
	 */
	virtual void insert(const MovieAttributes ma) = 0;

public:

	/**
	 * Empty virtual destructor.
	 */
	virtual ~Movie() = 0;

	/**
	 * This is the public method that will receive the movie details
	 * to add to the class object. The parameters are the MovieAttributes
	 * as defined by the MovieAttributes struct. The only two optional
	 * parameters would be the month and the actor name. The derived
	 * classes will need to implement there own add_movie method
	 *
	 * @param movieInfo: this will contain the movie details, such as
	 *                   title, director, release year, etc. This string
	 *                   will be parsed to fill in the MovieAttributes
	 */
	virtual void addMovie(const string movieInfo) = 0;

	/**
	 * This method will loop and display the vector movie values. This is
	 * a pure virtual method that the derived classes will have to
	 * implement to display the pertaining data accordingly
	 */
	virtual void display() = 0;

	/**
	 * This method will use the passed in media data to find the movie
	 * if the movie is found and the stock shows available then it will
	 * decrease the stock number by one. This method will be implemented
	 * by the derived classes
	 * 
	 * @param  mediaData: is a string with the movie data to search
	 * 
	 * @returns true if the movie was found and stock was decreased by one
	 *               otherwise will return false
	 */
	virtual bool borrowMovie(const string mediaData) = 0;

	/**
	 * This method will use the passed in media data to find the movie
	 * if the movie is found and the stock is not max stock then it will
	 * increase the stock number by one. This method will be implemented
	 * by the derived classes
	 * 
	 * @param  mediaData: is a string with the movie data to search
	 * 
	 * @returns true if the movie was found and stock was increased by one
	 *               otherwise will return false
	 */
	virtual bool returnMovie(const string mediaData) = 0;
};

/**
 * Empty virtual destructor
 */
inline Movie::~Movie() {}

#endif