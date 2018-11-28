//
// Created by lunar on 14/11/18.
//

#ifndef FIMPLUSPLUS_EXPRESSION_HPP
#define FIMPLUSPLUS_EXPRESSION_HPP


class Expression {

public:
	virtual ~Expression() = default;

	virtual void run() = 0;

};


#endif //FIMPLUSPLUS_EXPRESSION_HPP
