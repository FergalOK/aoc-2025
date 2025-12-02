#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc,  char** argv) {
    assert(argc == 2);
    std::ifstream file(argv[1]);

    int32_t result = 0;
    int32_t position = 50;
    for (std::string line; std::getline(file, line);) {
        int32_t move = std::stoi(line.substr(1));
        position += line[0] == 'R' ? move : -move;
        position = (position + 100) % 100;
        if (position == 0) result++;
    }
    
    std::cout << "Result (part 1): " << result << std::endl;
}
