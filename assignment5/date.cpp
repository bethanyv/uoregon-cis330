// Author Bethany Van Meter

#include "cipher.hpp"
#include "date.hpp"

// Single-argument constructor, initialized key to 2
Date::Date() : Cipher(), date("04/21/98") {
}


std::string
Date::encrypt( std::string &inputText ) {
	std::string text = inputText;

    std::string::size_type len_date = Date->date.length();
    std::string::size_type len = text.length();

    std::string number_str; // ex. 042198
    std::string completed_numbers; // ex. 0 41 9842 198

    for(int i = 0; i != len_date; ++i) {
        if(text[i] != '/') {
            number_str += text[i];
        }
    }
	
    for (int i = 0; i != len; ++i) {
        if(text[i] != ' ') {
            completed_numbers += number_str[i % 6];
        }
        else if (text[i] == ' ') {
            completed_numbers += ' ';
        }
    }
    printf("%s\n", completed_numbers);
    // for (int i = 0; i != len; ++i) {
    //     if(text[i] != ' ') {
    //         if (text[i] >= 'a' && text[i] <= 'z') {
    //         }
    //         else if (text[i] >= 'A' && text[i] <= 'Z') {

    //         }
    //     }
    // }
	return text;
}

std::string
Date::decrypt( std::string &text ) {
	std::string::size_type len = text.length();
    
    return text;
}
