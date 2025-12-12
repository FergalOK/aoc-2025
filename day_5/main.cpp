#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <regex>

int main(int argc,  char** argv) {
    assert(argc >= 2);
    std::ifstream file(argv[1]);

    int64_t result = 0;

    std::string line;
    std::regex re("(\\d*)-(\\d*)");
    std::smatch m;
    std::vector<std::pair<int64_t, int64_t>> ranges;
    while (std::getline(file, line) && std::regex_search(line, m, re)) {
        ranges.push_back({stol(m[1]), stol(m[2])});
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
}
