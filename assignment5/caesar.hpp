// Author: Bethany Van Meter

#include <string>

#ifndef CAESAR_HPP_
#define CAESAR_HPP_

#include "cipher.hpp"

class Caesar : public Cipher {
public:
    Caesar(); // constructor
    
	virtual std::string encrypt( std::string &text );
	virtual std::string decrypt( std::string &text );
private:
	// need key to know how much to shift by,
	// UPPER and LOWER for indexing into correct positions
	// kept seperate for space, and capitaliziation
	int key;
	std::string LOWER = "abcdefghijklmnopqrstuvwxyz ";
	std::string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};

#endif /* CAESAR_HPP_ */
