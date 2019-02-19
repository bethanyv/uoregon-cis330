// Author Bethany Van Meter

#include "cipher.hpp"
#include "date.hpp"
#include <iostream>

// Single-argument constructor, initialized key to 2
Date::Date() : Cipher(), date("042198") {
}


std::string
Date::encrypt( std::string &inputText ) {
	std::string text = inputText;

    std::string::size_type len = text.length();

    std::string number_str = this->date; // ex. 042198
    std::string completed_numbers; // ex. 0 41 9842 198
	
    for (int i = 0; i != len; ++i) {
        if(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z') {
            completed_numbers += number_str[i % 6];
        }
    }
    
    int counter = 0; // for indexing into number_str
    for (int i = 0; i != len; ++i) {
        if(text[i] != ' ') {
            counter += 1;
            // lowercase
            if (text[i] >= 'a' && text[i] <= 'z') {
                // change index from number_str into int and index into LOWER and change text[i] to this letter
                
            }
            // uppercase
            else if (text[i] >= 'A' && text[i] <= 'Z') {
                // change index from number_str into int and index into HIGHER and change text[i] to this letter

            }
        }
    }

	return text;
}

std::string
Date::decrypt( std::string &text ) {
	std::string::size_type len = text.length();
    
    return text;
}
