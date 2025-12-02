#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc,  char** argv) {
    assert(argc == 2);
    std::ifstream file(argv[1]);

    int32_t result_part1 = 0;
    int32_t result_part2 = 0;
    int32_t position = 50;
    for (std::string line; std::getline(file, line);) {
        int32_t move = std::stoi(line.substr(1));
        int16_t step = line[0] == 'R' ? 1 : -1;
        for (int32_t i = 0; i < move; i++) {
            position = (position + step + 100) % 100;
            if (position == 0) result_part2++;
        }
        if (position == 0) result_part1++;
    }
    
    std::cout << "Result (part 1): " << result_part1 << std::endl;
    std::cout << "Result (part 2): " << result_part2 << std::endl;
}
