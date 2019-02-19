// Author Bethany Van Meter

#include "cipher.hpp"
#include "caesar.hpp"

// Single-argument constructor, initialized key to 2
Caesar::Caesar() : Cipher(), key(2) {
}


std::string
Caesar::encrypt( std::string &inputText ) {

	std::string text = inputText;
	std::string::size_type len = text.length();
    // found_index for finding the index of where the letter is in the alphabet
    std::size_t found_index = 0;

	for (int i = 0; i != len; ++i) {
        // if it's lowercase OR a space, handle with LOWER string
        if (text[i] >= 'a' && text[i] <= 'z' || text[i] == ' ') { 
            // find the index of the character in the string
            std::size_t found_index = this->LOWER.find(text[i]);
            // index to where the original character was PLUS the key. 
            // Modulo 27 for making sure the index isn't greater than the LOWER string
            text[i] = LOWER[(found_index + this->key) % 27];

        } else if(text[i] >= 'A' && text[i] <= 'Z') { 
            // find the index of the character in the UPPER string
            std::size_t found_index = this->UPPER.find(text[i]);
            // index to where the original character was PLUS the key. 
            // Modulo 26 for making sure the index isn't greater than the UPPER string
            text[i] = UPPER[(found_index + this->key) % 26];
        }
	}
	return text;
}

std::string
Caesar::decrypt( std::string &text ) {
	// Decrypt is opposite of encrypt with just subtracting the key instead of adding
	std::string::size_type len = text.length();
    std::size_t found_index = 0;

    for (int i = 0; i != len; ++i) {
         // if it's lowercase, handle differently than upper
        if (text[i] >= 'a' && text[i] <= 'z' || text[i] == ' ') {
            // find the index of where the character is in the LOWER string
            std::size_t found_index = this->LOWER.find(text[i]);
            // for the new index, subtract the key
            int index = found_index - this->key;

            // if the index is negative, make sure to add 27 (including space) 
            // to make it postive again
            if(index < 0) {
                index = 27 + index;
            }
            // index into correct index
            text[i] = LOWER[index];

        } else if(text[i] >= 'A' && text[i] <= 'Z') { // uppercase
            std::size_t found_index = this->UPPER.find(text[i]);
            int index = found_index - this->key;

            if(index < 0) {
                index = 26 + index;
            }

            text[i] = UPPER[index];
        }
    }
    return text;
}


