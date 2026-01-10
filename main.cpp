#include <vector>
#include <print>
#include "problems/threesum.cpp"

int main() {
    std::vector<int> test = {1,-1,0,1,2};
    for (const auto &v:ThreeSum::twoPtr(test))
        std::println("{:<5d},{:<5d},{:<5d}",v[0],v[1],v[2]);
}