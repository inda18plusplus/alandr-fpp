//
// Created by lunar on 14/11/18.
//

#ifndef FIMPLUSPLUS_VARDECL_HPP
#define FIMPLUSPLUS_VARDECL_HPP

#include "Token.hpp"

#include <string>

#include "Literal.hpp"

class VarDecl : public Token {

	std::string _name;

	Literal _value;

public:


};


#endif //FIMPLUSPLUS_VARDECL_HPP
