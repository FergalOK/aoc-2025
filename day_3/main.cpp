#include <iostream>
#include <fstream>
#include <cassert>
#include <regex>

int main(int argc,  char** argv) {
    assert(argc == 2);
    std::ifstream file(argv[1]);

    int32_t result_part1 = 0;

    for (std::string line; std::getline(file, line);) {
        char joltage[2];
        size_t prev_index = 0;
        for (size_t i = 0; i < 2; i++) {
            char max = '0';
            size_t index_max = -1;
            for (size_t j = prev_index; j < line.size() + i - 1; j++) {
                if (line[j] > max) {
                    max = line[j];
                    index_max = j;
                }
                max = std::max(max, line[j]);
            }
            prev_index = index_max + 1;
            joltage[i] = max;
        }
        result_part1 += std::stoi(joltage);
    }
    std::cout << "Result (part 1): " << result_part1 << std::endl;
    // std::cout << "Result (part 2): " << result_part2 << std::endl;
}
