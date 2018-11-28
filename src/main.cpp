#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "ProgramParser.hpp"

#include "strUtil.hpp"

namespace fs = std::filesystem;

int main(int argc, char** argv) {

	if(argc < 2) {
		std::cerr << "No file!\n";
		return 1;
	}

	std::vector<fs::path> files;

	for (int i = 1; i < argc; ++i) {
		files.emplace_back(fs::path(argv[i]));
	}

	auto p = std::make_shared<ProgramParser>(files);

	p->parse();

	p->run();

	return 0;
}