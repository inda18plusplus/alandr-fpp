//
// Created by lunar on 12/11/18.
//

#ifndef FIMPLUSPLUS_PARSER_HPP
#define FIMPLUSPLUS_PARSER_HPP

#include <filesystem>
#include <fstream>
#include <memory>
#include <vector>

#include "AST/Celestia.hpp"
#include "AST/Report.hpp"
#include "FileParser.hpp"
#include "ReportParser.hpp"
#include "Token.hpp"

namespace fs = std::filesystem;

class ProgramParser : public std::enable_shared_from_this<ProgramParser> {

	std::vector<fs::path> _paths;

	std::vector<std::shared_ptr<FileParser>> _fileParsers;
	std::vector<std::shared_ptr<ReportParser>> _reportParsers;

	std::shared_ptr<Celestia> _celestia;
	std::vector<std::shared_ptr<Report>> _reports;

public:
	explicit ProgramParser(const std::vector<fs::path>& paths);

	void parse();

	void run();

	void addReportParser(const std::shared_ptr <ReportParser> &parser);

	void addReport(const std::shared_ptr <Report> &rep);
	std::shared_ptr<Report> getReport(const std::string_view name);

};


#endif //FIMPLUSPLUS_PARSER_HPP
