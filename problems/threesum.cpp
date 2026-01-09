#include <vector>

namespace ThreeSum {
    std::vector<std::vector<int> > twoPtr(std::vector<int> &nums) {
        std::vector<std::vector<int> > output;
        int idx = 0;
        while (idx < nums.size()) {
            const int target = nums[idx];
            int left = idx + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sumOfAll = target + nums[left] + nums[right];
                if (!sumOfAll) {
                    output.push_back({target, nums[left++], nums[right--]});
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    continue;
                }

                if (sumOfAll > 0) --right;
                else ++left;
            }


            ++idx;
            while (idx < nums.size() && nums[idx] == target) ++idx;
        }


        return output;
    }
};
