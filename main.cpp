#include <vector>
#include <print>
#include "problems/threesum.cpp"


int main() {
    std::vector<int> test = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    for (const auto &v: ThreeSum::hashMap(test))
        std::println("{:<5d},{:<5d},{:<5d}", v[0], v[1], v[2]);

}
