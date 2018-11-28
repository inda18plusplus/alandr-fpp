//
// Created by lunar on 15/11/18.
//

#include "strUtil.hpp"

#include <cstdlib>

std::string_view stripWhiteSpace(std::string_view str) {

	std::size_t firstChar = str.find_first_not_of(whitespace);
	std::size_t len = str.find_last_not_of(whitespace) - firstChar + 1;

	return {str.data() + firstChar, len};

}

std::optional<double> asDouble(std::string_view str) {

	char* c;
	double d = strtod(str.data(), &c);

	if(c == str.data()) {
		return {};
	}

	return d;

}