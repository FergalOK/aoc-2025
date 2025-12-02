#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <regex>

int main(int argc,  char** argv) {
    assert(argc == 2);
    std::ifstream file(argv[1]);

    int64_t result_part1 = 0;
    int64_t result_part2 = 0;

    std::regex re("(\\d*)-(\\d*)");
    std::smatch m;
    for (std::string line; std::getline(file, line, ',') && std::regex_search(line, m, re);) {
        for (int64_t id = stol(m[1]); id <= stol(m[2]); id++) {
            std::string id_str = std::to_string(id);
            for (int32_t i = 2; i <= id_str.size(); i++) {
                int32_t step = id_str.size() / i;
                if (id_str.size() % i != 0) continue;
                std::string repeated = id_str.substr(0, step);
                bool success = true;
                for (int32_t j = 1; j < i; j++) {
                    std::string test = id_str.substr(j * step, step);
                    if (repeated.compare(test) != 0) {
                        success = false;
                        break;
                    }
                }
                if (success) {
                    result_part2 += id;
                    break;
                }
            }
            std::string first = id_str.substr(0, id_str.size()/2);
            std::string last = id_str.substr(id_str.size()/2);
            if (first.compare(last) == 0) result_part1 += id;
        }
    }

    std::cout << "Result (part 1): " << result_part1 << std::endl;
    std::cout << "Result (part 2): " << result_part2 << std::endl;
}
