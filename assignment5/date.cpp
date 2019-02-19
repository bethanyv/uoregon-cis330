// Author Bethany Van Meter

#include "cipher.hpp"
#include "date.hpp"

// Single-argument constructor, initialized key to 2
Date::Date() : Cipher() {
}


std::string
Date::encrypt( std::string &inputText ) {

	std::string text = inputText;
	
	return text;
}

std::string
Date::decrypt( std::string &text ) {
	std::string::size_type len = text.length();
    
    return text;
}
