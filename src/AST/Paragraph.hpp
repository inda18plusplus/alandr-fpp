//
// Created by lunar on 12/11/18.
//

#ifndef FIMPLUSPLUS_PARAGRAPH_HPP
#define FIMPLUSPLUS_PARAGRAPH_HPP

#include "Token.hpp"

#include <memory>
#include <string>
#include <vector>
#include <utility>

#include "Type.hpp"
#include "Paragraph.hpp"
#include "Report.hpp"
#include "RTVal.hpp"
#include "ValueGetter.hpp"
#include "Expression.hpp"
#include "Block.hpp"

class Paragraph { //AKA method

	std::string _name;

	std::weak_ptr<Report> _report;

	std::vector<std::pair<TYPE, std::string>> _parameters;

	bool _main = false;

	Block _body;

public:
	Paragraph(std::string_view name, std::weak_ptr<Report> owner);

	const std::string& name() { return _name; }

	bool isMain() { return _main; }
	void setMain(bool b) { _main = b; }

	void addExpression(std::shared_ptr<Expression> e) { _body.addExpression(e); }

	RTVal run();

};


#endif //FIMPLUSPLUS_PARAGRAPH_HPP
