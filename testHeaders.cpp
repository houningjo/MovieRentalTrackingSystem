#include "actionfactory.h"
#include "mediafactory.h"
#include "media.h"
#include "history.h"
#include "borrow.h"
#include "return.h"
#include "inventory.h"
#include "customer.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "customer.h"

#include <iostream>
using namespace std;

int main()
{
	// cout << endl << endl << "----------Testing MediaFactory-------------" << endl << endl;
	// Media *invalidMedia = MediaFactory::createMedia(static_cast<MediaFactory::MediaTypes>(2));
	// cout << "Passing invalid media type " << (invalidMedia == nullptr ? "pass" : "fail") << endl;

	// Media *dvdMedia = MediaFactory::createMedia(MediaFactory::MediaTypes::DVDType);
	// cout << "DVD media " << (dvdMedia != nullptr ? "pass" : "fail") << endl;
	// cout << endl << endl << "----------Testing DVD-------------" << endl << endl;
	// cout << "Building media inventory using data4movies.txt" << endl;
	// dvdMedia->buildMediaInventory("bin/data4movies.txt");
	// cout << "---------Displaying Movies--------" << endl << endl;
	// dvdMedia->displayMediaInventory();
	// cout << endl;
	
	// for (int i = 0; i < 8; i++)
	// {
	// 	cout << "Borrow You've Got Mail: " << (dvdMedia->borrowMedia("F You've Got Mail, 1998") ? "pass" : "fail") << endl;
	// 	cout << "Borrow Good Morning Vietnam: " << (dvdMedia->borrowMedia("D Barry Levinson, Good Morning Vietnam,") ? "pass" : "fail") << endl;
	// 	cout << "Borrow Katherine Hepburn movie: " << (dvdMedia->borrowMedia("C 5 1940 Katherine Hepburn") ? "pass" : "fail") << endl;
	// 	cout << "Borrow Sleepless in Seattle: " << (dvdMedia->borrowMedia("F Sleepless in Seattle, 1993") ? "pass" : "fail") << endl; 
	// }
	
	// cout << "---------Displaying Movies--------" << endl << endl;
	// dvdMedia->displayMediaInventory();
	// cout << endl;
	
	// for (int i = 0; i < 5; i++)
	// {
	// 	cout << "Return Katherine Hepburn movie: " << (dvdMedia->returnMedia("C 5 1940 Katherine Hepburn") ? "pass" : "fail") << endl;
	// 	cout << "Return Ruth Gordon movie: " << (dvdMedia->returnMedia("C 3 1971 Ruth Gordon") ? "fail" : "pass") << endl;
	// 	cout << "Return You've Got Mail: " << (dvdMedia->returnMedia("F You've Got Mail, 1998") ? "pass" : "fail") << endl;
	// 	cout << "Return Good Morning Vietnam: " << (dvdMedia->returnMedia("D Barry Levinson, Good Morning Vietnam,") ? "pass" : "fail") << endl;

	// }

	// cout << "Movie does not exist: " << (dvdMedia->borrowMedia("D Steven Sprielberg, Bogus Title,") ? "fail" : "pass") << endl;

	// cout << "---------Displaying Movies--------" << endl << endl;
	// dvdMedia->displayMediaInventory();
	// cout << endl;

	// cout << endl << endl << "----------Testing ActionFactory-------------" << endl << endl;
	// // fake customer just to test the following classes
	// Customer *customer;
	// Action *invalidAction = ActionFactory::createAction(static_cast<ActionFactory::ActionTypes>(9));
	// cout << "Passing invalid action type " << (invalidMedia == nullptr ? "pass" : "fail") << endl;
	
	// cout << endl << endl << "----------Borrow-------------" << endl << endl;
	// Action *borrowAction = ActionFactory::createAction(ActionFactory::ActionTypes::Borrow);
	// cout << "Borrow Action " << (borrowAction != nullptr ? "pass" : "fail") << endl;
	
	// cout << "Borrow 9 1938 Cary Grant: " << (borrowAction->doAction(dvdMedia, customer, 0, "C 9 1938 Cary Grant") ? "pass" : "fail") << endl;
	// cout << "Borrow 3 1971 Ruth Gordon: " << (borrowAction->doAction(dvdMedia, customer, 0, "C 3 1971 Ruth Gordon") ? "pass" : "fail") << endl;
	// cout << "Borrow Dogfight: " << (borrowAction->doAction(dvdMedia, customer, 0, "D Nancy Savoca, Dogfight,") ? "pass" : "fail") << endl;
	// cout << "Borrow Schindler's List: " << (borrowAction->doAction(dvdMedia, customer, 0, "D Steven Spielberg, Schindler's List,") ? "pass" : "fail") << endl;
	// cout << "Borrow Fargo: " << (borrowAction->doAction(dvdMedia, customer, 0, "F Fargo, 1996") ? "pass" : "fail") << endl;

	// cout << "---------Displaying Movies--------" << endl << endl;
	// dvdMedia->displayMediaInventory();
	// cout << endl;
	// delete borrowAction;

	// cout << endl << endl << "----------Return-------------" << endl << endl;
	// Action *returnAction = ActionFactory::createAction(ActionFactory::ActionTypes::Return);
	// cout << "Return Action " << (returnAction != nullptr ? "pass" : "fail") << endl;
	
	// cout << "Return 9 1938 Cary Grant: " << (returnAction->doAction(dvdMedia, customer, 0, "C 9 1938 Cary Grant") ? "pass" : "fail") << endl;
	// cout << "Return 3 1971 Ruth Gordon: " << (returnAction->doAction(dvdMedia, customer, 0, "C 3 1971 Ruth Gordon") ? "pass" : "fail") << endl;
	// cout << "Return Dogfight: " << (returnAction->doAction(dvdMedia, customer, 0, "D Nancy Savoca, Dogfight,") ? "pass" : "fail") << endl;
	// cout << "Return Schindler's List: " << (returnAction->doAction(dvdMedia, customer, 0, "D Steven Spielberg, Schindler's List,") ? "pass" : "fail") << endl;
	// cout << "Return Fargo: " << (returnAction->doAction(dvdMedia, customer, 0, "F Fargo, 1996") ? "pass" : "fail") << endl;

	// cout << "---------Displaying Movies--------" << endl << endl;
	// dvdMedia->displayMediaInventory();
	// cout << endl;
	// delete returnAction;

	// cout << endl << endl << "----------Inventory-------------" << endl << endl;
	// Action *inventoryAction = ActionFactory::createAction(ActionFactory::ActionTypes::Inventory);
	// cout << "Inventory Action " << (inventoryAction != nullptr ? "pass" : "fail") << endl;
	// cout << "Displaying Inventory " <<  endl;
	// inventoryAction->doAction(dvdMedia, customer);
	// cout << endl;

	// delete inventoryAction;

	// //delete customer;
	// delete dvdMedia;

	// cout << endl << endl << "----------Testing Comedy-------------" << endl << endl;
	// Comedy comedy;
	// comedy.addMovie("100,Nora Ephron,Sleepless in Seattle,1993  ");
	// comedy.addMovie("1,Woody Allen,Annie Hall,1977");
	// comedy.addMovie("100,Me,Sleepless in Seattle,2001");
	// cout << "---------Displaying Movies--------" << endl << endl;
	// comedy.display();
	// cout << endl;
	// cout << "Borrow Sleepless in Seattle: " << (comedy.borrowMovie("Sleepless in Seattle,1993") ? "pass" : "fail") << endl;
	// cout << "Borrow Annie Hall: " << (comedy.borrowMovie("Annie Hall,1977") ? "pass" : "fail") << endl;
	// cout << "Borrow Annie Hall: " << (comedy.borrowMovie("Annie Hall,1977") ? "fail" : "pass") << endl;
	// cout << "---------Displaying Movies--------" << endl << endl;
	// comedy.display();
	// cout << endl;
	// cout << "Return Annie Hall: " << (comedy.returnMovie("Annie Hall,1977") ? "pass" : "fail") << endl;
	// cout << "---------Displaying Movies--------" << endl << endl;
	// comedy.display();
	// cout << endl;
	// cout << "Return Annie Hall: " << (comedy.returnMovie("Annie Hall,1977") ? "fail" : "pass") << endl;


	// cout << endl << endl << "----------Testing Drama-------------" << endl << endl;
	// Drama drama;
	// drama.addMovie("1,Barry Levinson,Good Morning Vietnam,1988");
	// drama.addMovie("22,Barry Levinson,Another Movie,1990");
	// drama.addMovie("33,Steven Spielberg,Schindler's List,1993");
	// cout << "---------Displaying Movies--------" << endl << endl;
	// drama.display();
	// cout << endl;
	// cout << "Borrow Good Morning Vietnam: " << (drama.borrowMovie("Barry Levinson,Good Morning Vietnam,") ? "pass" : "fail") << endl;
	// cout << "Borrow Good Morning Vietnam: " << (drama.borrowMovie("Barry Levinson,Good Morning Vietnam,") ? "fail" : "pass") << endl;
	// cout << "Return Good Morning Vietnam: " << (drama.returnMovie("Barry Levinson,Good Morning Vietnam,") ? "pass" : "fail") << endl;
	// cout << "Borrow Good Morning Vietnam: " << (drama.borrowMovie("Barry Levinson,Good Morning Vietnam,") ? "pass" : "fail") << endl;
	// cout << "Borrow Another Movie: " << (drama.borrowMovie("Barry Levinson,Another Movie,") ? "pass" : "fail") << endl;
	// cout << "Borrow Another Movie: " << (drama.borrowMovie("Barry Levinson,Another Movie,") ? "pass" : "fail") << endl;
	// cout << "Borrow Another Movie: " << (drama.borrowMovie("Barry Levinson,Another Movie,") ? "pass" : "fail") << endl;
	// cout << "---------Displaying Movies--------" << endl << endl;
	// drama.display();
	// cout << endl;
	// cout << "Return Another Movie: " << (drama.returnMovie("Barry Levinson,Another Movie,") ? "pass" : "fail") << endl;
	// cout << "Return Another Movie: " << (drama.returnMovie("Barry Levinson,Another Movie,") ? "pass" : "fail") << endl;
	// cout << "Borrow Schindler's List: " << (drama.borrowMovie("Steven Spielberg,Schindler's List,") ? "pass" : "fail") << endl;
	// cout << "Borrow Schindler's List: " << (drama.borrowMovie("Steven Spielberg,Schindler's List,") ? "pass" : "fail") << endl;
	// cout << "Borrow Schindler's List: " << (drama.borrowMovie("Steven Spielberg,Schindler's List,") ? "pass" : "fail") << endl;
	// cout << "Borrow Schindler's List: " << (drama.borrowMovie("Steven Spielberg,Schindler's List,") ? "pass" : "fail") << endl;
	// cout << "---------Displaying Movies--------" << endl << endl;
	// drama.display();
	// cout << endl;

	// cout << endl << endl << "----------Testing Classic-------------" << endl << endl;
	// Classic classic;
	// classic.addMovie("10,Michael Curtiz,Casablanca,Ingrid Bergman 8 1942");
	// classic.addMovie("10,Michael Curtiz,Casablanca,Humphrey Bogart 8 1942");
	// classic.addMovie("33,Victor Flemming,The Wizard of Oz,Judy Garland 7 1939");
	// cout << "---------Displaying Movies--------" << endl << endl;
	// classic.display();
	// cout << endl;
	// cout << "Borrow 8 1942 Ingrid Bergman: " << (classic.borrowMovie("8 1942 Ingrid Bergman") ? "pass" : "fail") << endl;
	// cout << "Borrow 8 1942 Humphrey Bogart: " << (classic.borrowMovie("8 1942 Humphrey Bogart") ? "pass" : "fail") << endl;
	// cout << "---------Displaying Movies--------" << endl << endl;
	// classic.display();
	// cout << endl;
	// cout << "Borrow 8 1942 Ingrid Bergman: " << (classic.borrowMovie("8 1942 Ingrid Bergman") ? "pass" : "fail") << endl;
	// cout << "Return 8 1942 Humphrey Bogart: " << (classic.returnMovie("8 1942 Humphrey Bogart") ? "pass" : "fail") << endl;
	// cout << "Return 8 1942 Humphrey Bogart: " << (classic.returnMovie("8 1942 Humphrey Bogart") ? "pass" : "fail") << endl;
	// cout << "Return 8 1942 Humphrey Bogart: " << (classic.returnMovie("8 1942 Humphrey Bogart") ? "pass" : "fail") << endl;
	// cout << "---------Displaying Movies--------" << endl << endl;
	// classic.display();
	// cout << endl;
	// cout << "Return 8 1942 Ingrid Bergman: " << (classic.returnMovie("8 1942 Ingrid Bergman") ? "fail" : "pass") << endl;
	// cout << "Return 7 1939 Judy Garland: " << (classic.returnMovie("7 1939 Judy Garland") ? "fail" : "pass") << endl;
	// cout << "Borrow 7 1939 Judy Garland: " << (classic.borrowMovie("7 1939 Judy Garland") ? "pass" : "fail") << endl;
	// cout << "Borrow 7 1939 Judy Garland: " << (classic.borrowMovie("7 1939 Judy Garland") ? "pass" : "fail") << endl;
	// cout << "Borrow 7 1939 Judy Garland: " << (classic.borrowMovie("7 1939 Judy Garland") ? "pass" : "fail") << endl;
	// cout << "---------Displaying Movies--------" << endl << endl;
	// classic.display();
	// cout << endl;
	

	// Customer test
	//HashTable<int, string> table1(10);
	//table1.insert(0, "a");
	//string temp;
	// cout << "findV: " << table1.findV(0, temp) << endl;
	// cout << "findV: " << table1.findV(10, temp) << endl;


	cout << endl << endl << "----------- Testing Customer ------------" << endl << endl;
	Customer c1;
	c1.addHistory(10, "test1");
	c1.addHistory(10, "test2");
	c1.displayHistory(10);
	
	// CustomerInfo c1;
	// c1.setName("C1");
	// c1.addHistoryInfo("test1");
 //    c1.addHistoryInfo("test2");
 //    cout << "c1: " << c1 << endl;
 	Customer c2;
 	c2.buildCustomerTable("customers.txt");

 	// add history
 	cout << "add history" << endl;
 	c2.addHistory(3333, "action 1");
 	c2.addHistory(3333, "action 2");
 	c2.addHistory(3333, "action 3");

 	c2.addHistory(2000, "action 1");
 	c2.addHistory(2000, "action 2");
 	c2.addHistory(2000, "action 3");

 	// display history
 	cout << "display history" << endl;
 	cout << endl;
 	c2.displayHistory(3333);
 	c2.displayHistory(8888);
 	c2.displayHistory(4444);
 	c2.displayHistory(9999);
 	c2.displayHistory(6666);
 	c2.displayHistory(7777);
 	c2.displayHistory(1111);
 	c2.displayHistory(1000);
 	c2.displayHistory(9000);
 	c2.displayHistory(8000);
 	c2.displayHistory(5000);
 	c2.displayHistory(2000);
 	c2.displayHistory(2345); // invalid testing

	return 0;
}