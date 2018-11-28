//
// Created by lunar on 22/11/18.
//

#ifndef FIMPLUSPLUS_PARAGRAPHPARSER_HPP
#define FIMPLUSPLUS_PARAGRAPHPARSER_HPP

#include <string_view>
#include <memory>

#include "AST/Paragraph.hpp"
#include "AST/ParagraphCall.hpp"
#include "AST/Print.hpp"
#include "Token.hpp"
#include "punctuation.hpp"

class ReportParser;
class ParagraphParser {

	std::string_view _str;
	std::size_t _readPos = 0;

	std::weak_ptr<ReportParser> _parent;

	std::shared_ptr<Report> _report;
	std::shared_ptr<Paragraph> _paragraph;

	TOKEN getToken(std::string_view str);

	std::size_t disToPuncutation() const { return _str.find_first_of(punctuationMarks, _readPos) - _readPos; }

public:
	ParagraphParser(std::weak_ptr<ReportParser> parent, std::string_view str, std::string_view name,
		                bool isMain);

	void parseParagraph();

	std::shared_ptr<ParagraphCall> handleCall(std::string_view str);
	std::shared_ptr<Print> handlePrint(std::string_view str);

	std::shared_ptr<Paragraph> paragraph() { return _paragraph; }

};


#endif //FIMPLUSPLUS_PARAGRAPHPARSER_HPP
