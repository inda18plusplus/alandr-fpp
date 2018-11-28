//
// Created by lunar on 12/11/18.
//

#include <algorithm>
#include "Report.hpp"

#include "Paragraph.hpp"

Report::Report(const std::string &name, std::shared_ptr<Report> addressee) : _addressee(std::move(addressee)), _name(name) {



}

void Report::addParagraph(std::shared_ptr<Paragraph> p) {

	_ownParagraphs[p->name()] = p;

}

std::shared_ptr<Paragraph> Report::paragraph(const std::string &name) {

	if(_ownParagraphs.count(name)) {
		return _ownParagraphs[name];
	}

	if(!_addressee.expired()) {
		auto p = _addressee.lock()->paragraph(name);

		if(p) {
			return p;
		}
	}

	for(auto& interface : _interfaces) {
		auto p = interface.lock()->paragraph(name);

		if (p) {
			return p;
		}
	}

	return nullptr;

}

void Report::setAddressee(std::shared_ptr<Report> addressee) {

	_addressee = addressee;

}

void Report::addInterface(std::shared_ptr<Report> interface) {

	_interfaces.push_back(interface);

}

std::shared_ptr<Paragraph> Report::mainParagraph() {

	auto p = std::find_if(_ownParagraphs.begin(), _ownParagraphs.end(), [](auto& p){
		return p.second->isMain();
	});

	if(p == _ownParagraphs.end()) {
		return {};
	}

	return p->second;

}