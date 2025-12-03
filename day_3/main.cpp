#include <iostream>
#include <fstream>
#include <cassert>
#include <regex>

int main(int argc,  char** argv) {
    assert(argc >= 2);
    std::ifstream file(argv[1]);
    size_t n_batteries = argc == 3 ? std::stoi(argv[2]) : 2;

    int64_t result = 0;

    for (std::string line; std::getline(file, line);) {
        char joltage[n_batteries+1] {};
        size_t prev_index = 0;
        for (size_t i = 0; i < n_batteries; i++) {
            char max = '0';
            size_t index_max = -1;
            for (size_t j = prev_index; j < line.size() - n_batteries + i + 1; j++) {
                if (line[j] > max) {
                    max = line[j];
                    index_max = j;
                }
            }
            prev_index = index_max + 1;
            joltage[i] = max;
        }
        result += std::stol(joltage);
    }

    std::cout << "Result (" << n_batteries << " batteries): " << result << std::endl;
}
