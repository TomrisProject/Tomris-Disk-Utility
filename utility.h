#include <iostream>
#include <array>
#include <filesystem>
#include <ranges>

using namespace std;

using PathBase = std::filesystem::path;

struct Utility {
    static std::vector<PathBase> show_disks();
};
