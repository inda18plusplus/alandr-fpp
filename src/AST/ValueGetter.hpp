//
// Created by lunar on 15/11/18.
//

#ifndef FIMPLUSPLUS_VALUEGETTER_HPP
#define FIMPLUSPLUS_VALUEGETTER_HPP

#include "Type.hpp"
#include "Token.hpp"
#include "RTVal.hpp"
#include "Expression.hpp"

class ValueGetter : public Expression {

	TYPE _type = TYPE::NONE;

public:
	virtual ~ValueGetter() = default;

	TYPE type() { return _type; }
	void setType(TYPE t) { _type = t; }

	virtual RTVal get() = 0;

};


#endif //FIMPLUSPLUS_VALUEGETTER_HPP
