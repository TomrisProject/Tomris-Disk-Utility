#include <iostream>
#include <filesystem>
#include <vector>

using PathBase = std::filesystem::path;

using namespace std;

struct Utility {
    static auto show_disks(){
        auto it = filesystem::directory_iterator("/dev");
        std::vector<PathBase> vec;
        int cnt{};
        std::ranges::for_each(it, [&](const auto x){
            const auto& path = x.path();
            std::string str = path.stem().string();
            if (str.rfind("rdisk", 0) == 0) {
                vec.push_back(path);
                ++cnt;
            }
        });

        return vec;
    };
};


int main(){
    auto disks = Utility::show_disks();

    std::for_each(disks.begin(), disks.end(), [&](const PathBase& x){
                std::cout << x << '\n';
    });

}
