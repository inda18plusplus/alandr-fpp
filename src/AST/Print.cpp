//
// Created by lunar on 23/11/18.
//

#include "Print.hpp"

#include <iostream>

Print::Print(std::shared_ptr<ValueGetter> getter) : _getter(std::move(getter)) {



}

void Print::run() {

	RTVal val = _getter->get();

	if(!val) {
		throw std::runtime_error("No value!");
	}

	if(std::holds_alternative<std::string>(*val)) {

		std::cout << std::get<std::string>(*val) << std::flush;

	} else if(std::holds_alternative<double>(*val)) {

		std::cout << std::get<double>(*val) << std::flush;

	} else {

		std::cout << std::get<bool>(*val) << std::flush;

	}

}
