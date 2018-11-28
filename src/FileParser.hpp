//
// Created by lunar on 15/11/18.
//

#ifndef FIMPLUSPLUS_FILEPARSER_HPP
#define FIMPLUSPLUS_FILEPARSER_HPP

#include <memory>
#include <vector>

#include "AST/Report.hpp"
#include "ReportParser.hpp"

class ProgramParser;
class FileParser : public std::enable_shared_from_this<FileParser> {

	std::weak_ptr<ProgramParser> _parent;

	const std::string _string;
	std::size_t _readPos = 0;

	std::vector<std::shared_ptr<ReportParser>> _reports;

	size_t disToPuncutation() const;

public:
	FileParser(std::weak_ptr<ProgramParser> parent, std::string&& str);

	void readDeclarations(); //Read the names inheritance diagram of the reports

	std::shared_ptr<Report> getReport(const std::string_view name);

};


#endif //FIMPLUSPLUS_FILEPARSER_HPP
