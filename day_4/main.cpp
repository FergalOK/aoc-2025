#include <iostream>
#include <fstream>
#include <cassert>
#include <regex>

int main(int argc,  char** argv) {
    assert(argc >= 2);
    std::ifstream file(argv[1]);

    std::vector<std::string> map;
    int64_t result = 0;

    for (std::string line; std::getline(file, line);) map.push_back(line);

    for (int16_t y = 0; y < map.size(); y++) {
        for (int16_t  x = 0; x < map[0].size(); x++) {
            if (map[y][x] != '@') continue;
            size_t count = 0;
            for (int16_t dx : {-1, 0, 1}) {
                for (int16_t dy : {-1, 0, 1}) {
                    if (dx == 0 && dy == 0) continue;
                    if (x + dx < 0 || x + dx >= map[0].size()) continue;
                    if (y + dy < 0 || y + dy >= map.size()) continue;

                    if (map[y+dy][x+dx] == '@') count++;
                }
            } 

            if (count < 4) result++;
        }
    }

    std::cout << "Result (part 1): " << result << std::endl;
}
