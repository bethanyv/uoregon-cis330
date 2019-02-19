// Author Bethany Van Meter

#include "cipher.hpp"
#include "date.hpp"

// Single-argument constructor, initialized key to 2
Date::Date() : Cipher(), date("04/21/98") {
}


std::string
Date::encrypt( std::string &inputText ) {
	std::string text = inputText;
    std::string::size_type len_date = text.length();
    std::string number_str;
    
    for(int i = 0; i != len_date; ++i) {
        if(text[i] != '/') {
            number_str += text[i];
        }
    }
	
    for (int i = 0; i != len; ++i) {
        
    }
	return text;
}

std::string
Date::decrypt( std::string &text ) {
	std::string::size_type len = text.length();
    
    return text;
}
