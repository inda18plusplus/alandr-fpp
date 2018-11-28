//
// Created by lunar on 12/11/18.
//

#include "ProgramParser.hpp"

#include <stdexcept>
#include <sstream>

#include <fmt/format.h>
using namespace fmt::literals;

ProgramParser::ProgramParser(const std::vector<fs::path> &paths) : _paths(paths), _celestia(new Celestia), _reports{_celestia} {



}

void ProgramParser::parse() {

	for (const auto& p : _paths) {

		std::ifstream f(p);

		if(!f) {
			throw std::runtime_error("The file {} does not exist"_format(p.string()));
		}
		std::stringstream ss;
		ss << f.rdbuf();

		_fileParsers.emplace_back(std::make_shared<FileParser>(weak_from_this(), std::move(ss.str())));

	}

	for(auto& f : _fileParsers) {
		f->readDeclarations();
	}

	for(auto& r : _reportParsers) {
		r->connectInheritance();
	}

	for(auto& r : _reportParsers) {
		r->readSignatures();
	}

	for(auto& r : _reportParsers) {
		r->parseParagraphs();
	}

}

void ProgramParser::addReportParser(const std::shared_ptr<ReportParser> &parser) {

	_reportParsers.push_back(parser);
	addReport(parser->report());

}

void ProgramParser::addReport(const std::shared_ptr <Report> &rep) {

	if(getReport(rep->name())) {
		throw std::runtime_error("Duplicate declaration of report {}"_format(rep->name()));
	}

	_reports.push_back(rep);

}

std::shared_ptr<Report> ProgramParser::getReport(const std::string_view name) {

	auto p = std::find_if(_reports.begin(), _reports.end(), [&name](auto p){
		return p->name() == name;
	});

	if(p == _reports.end()) {
		return {};
	}

	return *p;

}

void ProgramParser::run() {

	auto mainHolder = std::find_if(_reports.begin(), _reports.end(), [](auto& r){ return r->mainParagraph(); });

	(*mainHolder)->mainParagraph()->run();

}