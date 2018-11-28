//
// Created by lunar on 12/11/18.
//

#include "Paragraph.hpp"


Paragraph::Paragraph(std::string_view name, std::weak_ptr<Report> owner) : _name(name), _report(std::move(owner)) {



}

RTVal Paragraph::run() {

	_body.run();

	return {};

}