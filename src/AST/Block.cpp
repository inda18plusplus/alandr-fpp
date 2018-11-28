//
// Created by lunar on 23/11/18.
//

#include "Block.hpp"

void Block::run() {

	for (auto& e : _expressions) {
		e->run();
	}

}