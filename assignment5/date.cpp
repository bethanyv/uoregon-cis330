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
        int add_index; // for the numerical value of the index in the number str
        if(text[i] != ' ') {
            add_index = completed_numbers[counter] - 48;
            counter += 1;
            // lowercase
            if (text[i] >= 'a' && text[i] <= 'z') {
                // change index from number_str into int and index into LOWER and change text[i] to this letter
                std::size_t found_index = this->LOWER.find(text[i]);
                text[i] = LOWER[(found_index + add_index) % 26];
            }
            // uppercase
            else if (text[i] >= 'A' && text[i] <= 'Z') {
                // change index from number_str into int and index into HIGHER and change text[i] to this letter
                std::size_t found_index = this->UPPER.find(text[i]);
                text[i] = UPPER[(found_index + add_index) % 26];
            }
        }
    }

	return text;
}

std::string
Date::decrypt( std::string &text ) {
	std::string::size_type len = text.length();

    std::string number_str = this->date;
    std::string completed_numbers; // ex. 0 41 9842 198
    
    for (int i = 0; i != len; ++i) {
        if(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z') {
            completed_numbers += number_str[i % 6];
        }
    }

    int counter = 0; // for indexing into number_str
    for (int i = 0; i != len; ++i) {
        int sub_index; // for the numerical value of the index in the number str
        if(text[i] != ' ') {
            sub_index = completed_numbers[counter] - 48;
            counter += 1;
            // lowercase
            if (text[i] >= 'a' && text[i] <= 'z') {
                // change index from number_str into int and index into LOWER and change text[i] to this letter
                std::size_t found_index = this->LOWER.find(text[i]);
                int ind = found_index - sub_index;

                if(ind < 0) {
                ind = 26 + ind;
                }
                // HERE CHANGE IF NEGATIVE
                text[i] = LOWER[ind % 26];
            }
            // uppercase
            else if (text[i] >= 'A' && text[i] <= 'Z') {
                // change index from number_str into int and index into HIGHER and change text[i] to this letter
                std::size_t found_index = this->UPPER.find(text[i]);
                int ind = found_index - sub_index;

                if(ind < 0) {
                ind = 26 + ind;
                }

                text[i] = UPPER[ind % 26];
            }
        }
    }

    return text;

}
