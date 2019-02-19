// Author: Bethany Van Meter

#include <iostream>
#include <fstream>

#include "ioutils.hpp"
#include "cipher.hpp"
#include "date.hpp"

int main(int argc, const char *argv[]) {

	IOUtils io;
	io.openStream(argc,argv);
	std::string input, encrypted, decrypted;
	input = io.readFromStream();
	std::cout << "Original text:" << std::endl << input;

	// create new caesar cipher
	Date date;
	encrypted = date.encrypt(input);
	// print encryption
	std::cout << "Encrypted text:" << std::endl << encrypted;

	decrypted = date.decrypt(encrypted);
	// print decryption
	std::cout << "Decrypted text:" << std::endl << decrypted;

	if (decrypted == input) std::cout << "Decrypted text matches input!" << std::endl;
	else {
		std::cout << "Oops! Decrypted text doesn't match input!" << std::endl;
		return 1;   // Return non-zero to show it failed
	}

	return 0;
}
