#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <set>
#include <regex>

int main(int argc,  char** argv) {
    assert(argc >= 2);
    std::ifstream file(argv[1]);

    int64_t result = 0;

    std::string line;
    std::regex re("(\\d*)-(\\d*)");
    std::smatch m;
    std::set<std::pair<int64_t, int64_t>> ranges;
    while (std::getline(file, line) && std::regex_search(line, m, re)) {
        ranges.insert({stol(m[1]), stol(m[2])});
    }
    while (std::getline(file, line)) {
        int64_t needle = stol(line);
        for (auto [start, end] : ranges) {
            if (needle >= start && needle <= end) {
                result++;
                break;
            }
        }
    }

    std::cout << "Result (part 1): " << result << std::endl;

    int64_t result_part2 = 0;
    int64_t highest = -1;
    for (auto [start, end] : ranges) {
        int64_t new_start = std::max(highest+1, start);
        result_part2 += std::max(0l, end - new_start + 1);
        highest = std::max(highest, end);
    }

    std::cout << "Result (part 2): " << result_part2 << std::endl;
}
