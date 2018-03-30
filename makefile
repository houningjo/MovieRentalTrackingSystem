test:
	g++ -std=c++11 -o bin/testHeaders testHeaders.cpp mediafactory.cpp dvd.cpp comedy.cpp classic.cpp drama.cpp movieutilities.cpp actionfactory.cpp borrow.cpp return.cpp inventory.cpp history.cpp customer.cpp

product:
	g++ -std=c++11 -o movieRental movierental.cpp mediafactory.cpp dvd.cpp comedy.cpp classic.cpp drama.cpp movieutilities.cpp actionfactory.cpp borrow.cpp return.cpp inventory.cpp history.cpp customer.cpp customerInfo.cpp
