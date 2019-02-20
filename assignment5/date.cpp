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
        // if the text is a letter, encrypt a new number string per letter based on date
        if(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z') {
            // i % 6 since there are only 6 digits in the date
            completed_numbers += number_str[i % 6];
        }
    }
    
    // for indexing into number_str - don't want to use for loop because number string 
    // doesn't account for spaces when the for loop will (will produce index error if 
    // we don't have a count)
    int counter = 0; 
    for (int i = 0; i != len; ++i) {

        // add_index for the numerical value of the index in the number_str ("4" in "421")
        int add_index; 

        // if the character in the string is a letter, then encrypt it (otherwise don't do anything)
        if(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z') { 

            // subtract 48 because completed_numbers[counter] gets casted from a string to
            // an int, so we have to subtract 48 since ASCII codes of string numbers start at 48
            add_index = completed_numbers[counter] - 48;
            // add to counter to be able to index in next index in next iteration
            counter += 1;

            // lowercase
            if (text[i] >= 'a' && text[i] <= 'z') {
                // index into LOWER from finding current character and change text[i] to this
                // letter's index PLUS the add_index from the date number
                std::size_t found_index = this->LOWER.find(text[i]);
                text[i] = LOWER[(found_index + add_index) % 26];
            }

            // uppercase
            else if (text[i] >= 'A' && text[i] <= 'Z') {
                // same as LOWER except indexing into UPPER string instead
                std::size_t found_index = this->UPPER.find(text[i]);
                text[i] = UPPER[(found_index + add_index) % 26];
            }
        }
    }

	return text;
}

// decrypt the same as encrypt, just SUBTRACT the indexing instead of adding
std::string
Date::decrypt( std::string &text ) {
	std::string::size_type len = text.length();

    std::string number_str = this->date;
    std::string completed_numbers; // ex. 0 41 9842 198
    
    // create the number string
    for (int i = 0; i != len; ++i) {
        if(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z') {
            // i % 6 since there are only 6 digits in the date
            completed_numbers += number_str[i % 6];
        }
    }

    // for indexing into number_str
    int counter = 0; 
    for (int i = 0; i != len; ++i) {

        // for the numerical value of the index in the number str
        int sub_index; 

        // if the character in the string is a letter, then decrypt it (otherwise don't do anything)
        if(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z') {

            // subtract 48 because completed_numbers[counter] gets casted from a string to
            // an int, so we have to subtract 48 since ASCII codes of string numbers start at 48
            sub_index = completed_numbers[counter] - 48;

            // add to counter to be able to index in next index in next iteration
            counter += 1;

            // lowercase
            if (text[i] >= 'a' && text[i] <= 'z') {
                // index into LOWER from finding current character and change text[i] to this
                // letter's index MINUS the add_index from the date number
                std::size_t found_index = this->LOWER.find(text[i]);
                int ind = found_index - sub_index;

                // if it becomes negative, add 26 to the number so index can be correct (wrap-around)
                if(ind < 0) {
                    ind = 26 + ind;
                }
                text[i] = LOWER[ind];
            }
            // uppercase
            else if (text[i] >= 'A' && text[i] <= 'Z') {
                // same as LOWER except indexing into UPPER string instead
                std::size_t found_index = this->UPPER.find(text[i]);
                int ind = found_index - sub_index;

                // if it becomes negative, add 26 to the number so index can be correct (wrap-around)
                if(ind < 0) {
                    ind = 26 + ind;
                }
                text[i] = UPPER[ind];
            }
        }
    }

    return text;

}
