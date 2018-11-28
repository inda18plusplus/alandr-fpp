//
// Created by lunar on 22/11/18.
//

#include "ParagraphParser.hpp"

#include "ReportParser.hpp"
#include "AST/Paragraph.hpp"
#include "AST/Literal.hpp"
#include "strUtil.hpp"

ParagraphParser::ParagraphParser(std::weak_ptr<ReportParser> parent, std::string_view str, std::string_view name,
                                 bool isMain)
	: _str(str), _parent(std::move(parent)) {

	_report = _parent.lock()->report();

	_paragraph = std::make_shared<Paragraph>(name, _parent.lock()->report());
	_paragraph->setMain(isMain);

}

TOKEN ParagraphParser::getToken(std::string_view str) {

	if(str.substr(0, 6) == "I said") {
		return TOKEN::ACTION_PRINT;
	}
	if(str.substr(0, 12) == "I remembered") {
		return TOKEN::PARAGRAPH_CALL;
	}

}

void ParagraphParser::parseParagraph() {

	_str = _str.substr(disToPuncutation() + 1);

	std::size_t lastPunct = _str.find_last_of(punctuationMarks, _str.length() - 2);
	_str = _str.substr(0, lastPunct + 1);

	for(;;) {

		if((disToPuncutation() + _readPos) == std::string::npos) {
			break;
		}

		auto line = _str.substr(_readPos, disToPuncutation() + 1);
		_readPos += line.length();
		line = stripWhiteSpace(line);

		TOKEN tok = getToken(line);

		std::shared_ptr<Expression> expression = nullptr;
		switch (tok) {
			case TOKEN::PARAGRAPH_CALL:
				expression = handleCall(line);
				break;

			case TOKEN::ACTION_PRINT:
				expression = handlePrint(line);
				break;

		}

		_paragraph->addExpression(expression);

	}


}

std::shared_ptr<ParagraphCall> ParagraphParser::handleCall(std::string_view str) {

	auto name = stripWhiteSpace(str.substr(12, str.length() - 12 - 1));

	auto call = std::make_shared<ParagraphCall>(_report->paragraph(std::string(name)));

	return call;

}

std::shared_ptr<Print> ParagraphParser::handlePrint(std::string_view str) {

	str = stripWhiteSpace(str.substr(6, str.length() - 6 - 1));

	std::shared_ptr<ValueGetter> value;
	if(str[0] == '"') {
		value = std::make_shared<Literal>(std::string(str.substr(1, str.length() - 2)));
	} else if(auto d = asDouble(str)) {
		value = std::make_shared<Literal>(*d);
	} else if(str == "true") {
		value = std::make_shared<Literal>(true);
	} else if(str == "false") {
		value = std::make_shared<Literal>(false);
	} else {
		//TODO: Identifier parsing here.
	}

	auto ret = std::make_shared<Print>(value);

	return ret;

}