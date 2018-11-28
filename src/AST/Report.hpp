//
// Created by lunar on 12/11/18.
//

#ifndef FIMPLUSPLUS_REPORT_HPP
#define FIMPLUSPLUS_REPORT_HPP

#include "Token.hpp"

#include <map>
#include <memory>
#include <string>
#include <vector>

class Paragraph;

class Report : public Token { //AKA class

	std::weak_ptr<Report> _addressee;
	std::vector<std::weak_ptr<Report>> _interfaces;

	std::string _name;

	std::map<std::string, std::shared_ptr<Paragraph>> _ownParagraphs;

public:
	Report(const std::string &name, std::shared_ptr<Report> addressee);

	void addParagraph(std::shared_ptr<Paragraph> p);
	std::shared_ptr<Paragraph> paragraph(const std::string& name);

	const std::string& name() const { return _name; }
	void setName(std::string_view str) { _name = str; }

	void setAddressee(std::shared_ptr<Report> addressee);

	void addInterface(std::shared_ptr<Report> interface);

	std::shared_ptr<Paragraph> mainParagraph();

};

#endif //FIMPLUSPLUS_REPORT_HPP
