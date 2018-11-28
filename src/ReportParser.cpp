//
// Created by lunar on 22/11/18.
//

#include "ReportParser.hpp"

#include "FileParser.hpp"
#include "punctuation.hpp"
#include "strUtil.hpp"

#include <fmt/format.h>
using namespace fmt::literals;

ReportParser::ReportParser(std::weak_ptr<FileParser> parent, const std::string_view &name, std::string_view addressee,
                           const std::vector<std::string_view> &interfaces, std::string_view str)
		: _file(std::move(parent)), _name(name), _addressee(addressee), _interfaces(interfaces), _str(str) {

	_report = std::shared_ptr<Report>(new Report(std::string(_name), {})); //make_shared doesn't work for some reason...

}

void ReportParser::connectInheritance() {

	auto access = _file.lock();

	auto addressee = access->getReport(_addressee);
	if(!addressee) {
		throw std::runtime_error("Report {} uses undeclared addressee {}"_format(_name, _addressee));
	}

	_report->setAddressee(addressee);

	for(auto& interfaceName : _interfaces) {

		auto interface = access->getReport(interfaceName);

		if(!interface) {
			throw std::runtime_error("Report {} uses undeclared interface {}"_format(_name, interfaceName));
		}

		_report->addInterface(interface);

	}

}

void ReportParser::readSignatures() {

	for(;;) {

		std::size_t startPos = _str.find("I learned", _readPos);

		if(startPos == std::string::npos)
			break;

		_readPos += startPos + 9;

		bool isMain = false;
		std::size_t lastWord = _str.find_last_not_of(punctuationMarks, startPos - 1);
		if(lastWord != std::string::npos) {
			if(_str.substr(lastWord - 5, 5) == "Today") {
				startPos = lastWord - 5;

				isMain = true;
			}
		}

		std::size_t punc = disToPuncutation();

		std::string_view name = stripWhiteSpace(_str.substr(_readPos, punc));
		_readPos += punc;

		std::size_t endStart = _str.find("That's all about", _readPos);

		_readPos += endStart - _readPos;

		punc = disToPuncutation();

		_readPos += punc + 1;

		auto str = _str.substr(startPos, _readPos - startPos);

		auto parser = std::make_shared<ParagraphParser>(weak_from_this(), str, name, isMain);

		_report->addParagraph(parser->paragraph());
		_paragraphParsers.push_back(parser);

	}

}

bool ReportParser::ownsMain() {

	int mains = std::count_if(_paragraphParsers.begin(), _paragraphParsers.end(), [](auto& p){ return p->paragraph()->isMain(); });

	if(mains > 1) {
		throw std::runtime_error("Multiple main declarations in {}"_format(_name));
	}

	return mains;

}

size_t ReportParser::disToPuncutation() const {

	return _str.find_first_of(punctuationMarks, _readPos) - _readPos;

}

void ReportParser::parseParagraphs() {

	for(auto& p : _paragraphParsers) {
		p->parseParagraph();
	}

}