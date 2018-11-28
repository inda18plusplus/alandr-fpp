//
// Created by lunar on 22/11/18.
//

#ifndef FIMPLUSPLUS_REPORTPARSER_HPP
#define FIMPLUSPLUS_REPORTPARSER_HPP

#include <string>
#include <string_view>
#include <vector>
#include <memory>

#include "AST/Report.hpp"
#include "AST/Paragraph.hpp"

#include "ParagraphParser.hpp"

class FileParser;
class ReportParser : public std::enable_shared_from_this<ReportParser> {

	std::weak_ptr<FileParser> _file;

	std::shared_ptr<Report> _report;

	std::string_view _name;

	std::string_view _addressee;
	std::vector<std::string_view> _interfaces;

	std::vector<std::shared_ptr<ParagraphParser>> _paragraphParsers;

	std::string_view _str;

	std::size_t _readPos = 0;

	std::size_t disToPuncutation() const;

public:
	ReportParser(std::weak_ptr<FileParser> parent, const std::string_view &name, std::string_view addressee,
		             const std::vector<std::string_view> &interfaces, std::string_view str);

	void connectInheritance();
	void readSignatures();
	void parseParagraphs();

	bool ownsMain();

	std::shared_ptr<Report> report() { return _report; }

};


#endif //FIMPLUSPLUS_REPORTPARSER_HPP
