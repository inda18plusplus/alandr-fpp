//
// Created by lunar on 09/11/18.
//

#include "punctuation.hpp"

bool isPunctuation(char c) {

	return punctuationMarks.find(c) != std::string_view::npos;

}