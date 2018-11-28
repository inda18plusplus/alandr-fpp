#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

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

#ifdef TIMING
	auto cStart = std::chrono::system_clock::now();
	p->parse();
	auto cEnd = std::chrono::system_clock::now();

	auto rStart = std::chrono::system_clock::now();
	p->run();
	auto rEnd = std::chrono::system_clock::now();

	std::cout << "Parsing took: " << std::chrono::duration_cast<std::chrono::microseconds>(cEnd - cStart).count() << "µs\n";
	std::cout << "Running took: " << std::chrono::duration_cast<std::chrono::microseconds>(rEnd - rStart).count() << "µs\n";
#else
	p->parse();
	p->run();
#endif //TIMING

	return 0;
}