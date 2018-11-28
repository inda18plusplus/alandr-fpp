//
// Created by lunar on 23/11/18.
//

#ifndef FIMPLUSPLUS_BLOCK_HPP
#define FIMPLUSPLUS_BLOCK_HPP

#include <vector>
#include <memory>

#include "Expression.hpp"

class Block : public Expression {

	std::vector<std::shared_ptr<Expression>> _expressions;

public:
	void addExpression(std::shared_ptr<Expression> e) { _expressions.emplace_back(e); }

	void run() override;

};


#endif //FIMPLUSPLUS_BLOCK_HPP
