//
// Created by lunar on 15/11/18.
//

#include "FileParser.hpp"

#include <stdexcept>

#include "ProgramParser.hpp"
#include "punctuation.hpp"
#include "strUtil.hpp"

#include <fmt/format.h>
using namespace fmt::literals;

FileParser::FileParser(std::weak_ptr<ProgramParser> parent, std::string &&str) :
		_parent(std::move(parent)), _string(str) {



}

void FileParser::readDeclarations() {

	for(;;) {

		std::string_view name;
		std::string_view addressee;
		std::vector<std::string_view> interfaces;

		std::size_t startPos = _string.find("Dear", _readPos);
		if(startPos == std::string::npos) {
			break;
		}

		std::size_t startDis = startPos - _readPos;
		_readPos += startDis;

		auto punc = disToPuncutation();
		std::string_view inheritance(_string.data() + _readPos + 4, punc - 4);
		inheritance = stripWhiteSpace(inheritance);

		if(inheritance.find(" and ") == std::string::npos) {
			addressee = inheritance;
		} else {
			//TODO: Parse interfaces
		}

		_readPos += punc + 1;

		punc = disToPuncutation();
		name = stripWhiteSpace(_string.substr(_readPos, punc));

		_readPos += _string.find("Your faithful student", _readPos) - _readPos;
		_readPos += disToPuncutation() + 1; //Eat "Your faithful student"
		_readPos += disToPuncutation() + 1; //Eat the name

		auto parser = std::make_shared<ReportParser>(weak_from_this(), name, addressee, interfaces, std::string_view(_string.data() + startPos, _readPos - startPos));

		_parent.lock()->addReportParser(parser);
		_reports.emplace_back(std::move(parser));

	}

}

size_t FileParser::disToPuncutation() const {

	return _string.find_first_of(punctuationMarks, _readPos) - _readPos;

}

std::shared_ptr<Report> FileParser::getReport(const std::string_view name) {

	//TODO: Imports

	auto access = _parent.lock();

	auto rep = access->getReport(name);

	return rep;

}