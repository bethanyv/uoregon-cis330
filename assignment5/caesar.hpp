// Author: Bethany Van Meter
#include <string>

#ifndef CAESAR_HPP_
#define CAESAR_HPP_

#include "cipher.hpp"

class Caesar : public Cipher {
public:
    Caesar(); // constructor

	// Default destructor 
    
	virtual std::string encrypt( std::string &text );
	virtual std::string decrypt( std::string &text );
private:
	int key;
	std::string LOWER = "abcdefghijklmnopqrstuvwxyz ";
	std::string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};

#endif /* CAESAR_HPP_ */
