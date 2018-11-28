//
// Created by lunar on 12/11/18.
//

#include "Literal.hpp"


Literal::Literal(bool b) : _value(b) {
	setType(TYPE::BOOL);
}
Literal::Literal(double i) : _value(i) {
	setType(TYPE::INT);
}
Literal::Literal(const std::string &s) : _value(s) {
	setType(TYPE::STRING);
}