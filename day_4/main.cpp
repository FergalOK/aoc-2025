#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <unordered_set>

int main(int argc,  char** argv) {
    assert(argc >= 2);
    std::ifstream file(argv[1]);

    std::vector<std::string> map;
    for (std::string line; std::getline(file, line);) map.push_back(line);

    int64_t result_part2 = 0;
    std::unordered_set<char*> removed;
    do {
        removed.clear();
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

                if (count < 4) removed.insert(&map[y][x]);
            }
        }
        if (result_part2 == 0) std::cout << "Result (part 1): " << removed.size() << std::endl;
        result_part2 += removed.size();
        for (char* location : removed) *location = '.';
    } while (removed.size() != 0);

    std::cout << "Result (part 2): " << result_part2 << std::endl;
}
