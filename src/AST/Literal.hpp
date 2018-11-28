//
// Created by lunar on 12/11/18.
//

#ifndef FIMPLUSPLUS_LITERAL_HPP
#define FIMPLUSPLUS_LITERAL_HPP

#include <string>
#include <variant>

#include "Type.hpp"
#include "ValueGetter.hpp"
#include "RTVal.hpp"

class Literal : public ValueGetter {

	RTVal _value;

public:
	explicit Literal(bool b);
	explicit Literal(double i);
	explicit Literal(const std::string& s);

	RTVal get() override { return _value; }
	void run() override {}

};


#endif //FIMPLUSPLUS_LITERAL_HPP
