// Author: Bethany Van Meter

#include <string>

#ifndef DATE_HPP_
#define DATE_HPP_

#include "cipher.hpp"

class Date : public Cipher {
public:
    Date(); // constructor
    
	virtual std::string encrypt( std::string &text );
	virtual std::string decrypt( std::string &text );
private:
	// string date for the numerical date
	std::string date;
	// save the alphabets as upper and lower so case is preserved
	std::string LOWER = "abcdefghijklmnopqrstuvwxyz";
	std::string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};

#endif /* DATE_HPP_ */
