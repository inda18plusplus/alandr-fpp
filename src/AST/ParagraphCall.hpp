//
// Created by lunar on 23/11/18.
//

#ifndef FIMPLUSPLUS_PARAGRAPHCALL_HPP
#define FIMPLUSPLUS_PARAGRAPHCALL_HPP

#include <memory>

#include "ValueGetter.hpp"
#include "Paragraph.hpp"

class ParagraphCall : public ValueGetter {

	std::shared_ptr<Paragraph> _paragraph;

public:
	ParagraphCall(std::shared_ptr<Paragraph> paragraph);

	RTVal get() override { return _paragraph->run(); }
	void run() override { get(); }

};


#endif //FIMPLUSPLUS_PARAGRAPHCALL_HPP
