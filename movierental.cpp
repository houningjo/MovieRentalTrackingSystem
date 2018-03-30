/**
 * File name: movierental.cpp
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 03/12/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the Borrow class is to perform an action on the Media
 * inventory object. Borrow will check if the movie is available, if so
 * it will decrease the stock number by one.
 * ---------------------------------------------------------------------------
 * This class inherits from the Action class
 */

#include "actionfactory.h"
#include "mediafactory.h"
#include "action.h"
#include "media.h"
#include "customer.h"

#include <fstream>
#include <iostream>

using namespace std;

/**
 * This function is to parse the commands strings for the
 * borrow and return actions. The customer id is converted
 * to an int and the media type and media data are separated
 * into two individual substrings.
 * 
 * @param command   the command string read from the command
 *                  text
 * @param mediaType this is the string that is returned and contains
 *                  the letter that determines the media type
 * @param id        this is the customer id that is converted to
 *                  an int
 * @param mediaData this is the data with the movie details
 */
void parseBorrowReturnCmds(const string command, string &mediaType, int &id, string &mediaData)
{
	// borrow and return commands are formatted:
	// CMD ID MediaType MediaData
	// MediaData differs between movie genres therefore
	// the genre classes handle parsing that substring
	int firstSpace = command.find(' ');
	int secondSpace = command.find(' ', firstSpace + 1);
	int thirdSpace = command.find(' ', secondSpace + 1);

	id = stoi(command.substr(firstSpace + 1, secondSpace - firstSpace - 1));
	mediaType = command.substr(secondSpace + 1, 1); // 1 char in length
	mediaData = command.substr(thirdSpace + 1);
}

/**
 * This function verifies that the media type in the command
 * is a supported media type
 * 
 * @param  mediaType is the string that holds the media type
 *                   
 * @return true if the media type is supported
 */
bool currentSupportedMediaTypes(string mediaType)
{
	if (mediaType == "D") return true;

	return false;
}

/**
 * This function processes the commands and creates an
 * action to process the type of action
 * 
 * @param  media    is the object that holds the media inventory
 * @param  customer is the object that holds the customer htable
 * @param  command  is the string with the command to process
 * @return          returns true if the action was successful
 */
bool processCommand(Media *&media, Customer *&customer, const string command)
{
	bool retStatus = false;
	Action *actionType = nullptr;
	char cmd = command.at(0);

	if (cmd == 'I')
	{
		actionType = ActionFactory::createAction(ActionFactory::ActionTypes::Inventory);
		cout << endl;
		cout << "Inventory" << endl;
		actionType->doAction(media, customer);
		cout << endl;
		retStatus = true;
	}
	else if (cmd == 'H')
	{
		actionType = ActionFactory::createAction(ActionFactory::ActionTypes::History);
		cout << endl;
		cout << "Customer Rental History" << endl;
		int custId = stoi(command.substr(command.find(' ')));
		actionType->doAction(media, customer, custId);
		cout << endl;
		retStatus = true;
	}
	else if (cmd == 'B' || cmd == 'R')
	{
		int custId = 0;
		string mediaType = "";
		string mediaData = "";
		parseBorrowReturnCmds(command, mediaType, custId, mediaData);

		if (currentSupportedMediaTypes(mediaType))
		{
			if (cmd == 'B') actionType = ActionFactory::createAction(ActionFactory::ActionTypes::Borrow);
			else actionType = ActionFactory::createAction(ActionFactory::ActionTypes::Return);
			
			retStatus = actionType->doAction(media, customer, custId, mediaData);
		}
	}

	delete actionType;

	return retStatus;
}

/**
 * This function reads the amount of customers
 * to set the customer hashtable
 * 
 * @param filename this is the customer file
 * 
 * @return  			the amount of customers
 */
int getCustomerTableSize(const string filename)
{
	ifstream filecust(filename);
	if(!filecust){
		cout << "File could not be opened." << endl;
		return -1;
	}

	int fileSize = 0;
	while(!filecust.eof()){
		string line;
		getline(filecust, line);
		fileSize++;
	}

	filecust.close();
	if (fileSize > 1) fileSize--; // minus the extra line

	return fileSize;
}

/**
 * Main program
 * 
 * @return 0 for sucess, -1 if the cmd file was not openned
 */
int main()
{
	// open commands file
	ifstream cmdFile("data4commands.txt");
	if (!cmdFile)
	{
		cout << "Error openning command file." << endl;
		return -1;
	}

   // Build DVD inventory
	Media *dvdMedia = MediaFactory::createMedia(MediaFactory::MediaTypes::DVDType);
	dvdMedia->buildMediaInventory("data4movies.txt");
	
	// Build customer db
	string filename = "data4customers.txt";
	int filesize = getCustomerTableSize(filename);
	if (filesize < 0) return -1;
	Customer *customer = new Customer(filesize);
	customer->buildCustomerTable(filename);
	
	// process commands
	string line;
	while (getline(cmdFile, line))
	{
		if (!processCommand(dvdMedia, customer, line))
		{
			cout << "Error: could not process command. " << line << endl;
		}
	}

	delete dvdMedia;
	delete customer;

	return 0;
}