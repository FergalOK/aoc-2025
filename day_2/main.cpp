#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <regex>

int main(int argc,  char** argv) {
    assert(argc == 2);
    std::ifstream file(argv[1]);

    int64_t result_part1 = 0;

    std::regex re("(.*)-(.*)");
    std::smatch m;
    for (std::string line; std::getline(file, line, ',') && std::regex_match(line, m, re);) {
        for (int64_t id = stol(m[1]); id <= stol(m[2]); id++) {
            std::string id_str = std::to_string(id);
            if (id_str.size() % 2 == 1) continue;

            std::string first = id_str.substr(0, id_str.size()/2);
            std::string last = id_str.substr(id_str.size()/2);
            if (first.compare(last) == 0) result_part1 += id;
        }
    }

    std::cout << "Result (part 1): " << result_part1 << std::endl;
}
