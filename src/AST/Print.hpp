//
// Created by lunar on 23/11/18.
//

#ifndef FIMPLUSPLUS_PRINT_HPP
#define FIMPLUSPLUS_PRINT_HPP

#include <memory>

#include "ValueGetter.hpp"
#include "Expression.hpp"

class Print : public Expression {

	std::shared_ptr<ValueGetter> _getter;

public:
	Print(std::shared_ptr<ValueGetter> getter);

	void run() override;

};


#endif //FIMPLUSPLUS_PRINT_HPP
