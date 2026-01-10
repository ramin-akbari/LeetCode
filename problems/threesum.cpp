#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ranges>

namespace ThreeSum {
    std::vector<std::vector<int> > twoPtr(std::vector<int> &nums) {
        std::ranges::sort(nums);
        std::vector<std::vector<int> > output;
        int idx = 0;
        while (idx < nums.size()) {
            const int target = nums[idx];
            int left = idx + 1;
            int right = static_cast<int>(nums.size()) - 1;

            while (left < right) {
                const int sumOfAll = target + nums[left] + nums[right];
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

    std::vector<std::vector<int> > hashMap(std::vector<int> &nums) {
        std::vector<std::vector<int> > output;
        std::unordered_map<int, std::unordered_set<int> > bucket;
        std::unordered_map<int, int> finder;
        for (const auto num: nums) ++finder[num];
        for (int i = 0; i < nums.size(); ++i) {
            if (bucket.contains(nums[i])) continue;
            int target = nums[i];
            auto &targetBucket = bucket[target];

            for (int j = i + 1; j < nums.size(); ++j) {
                if (targetBucket.contains(nums[j])) continue;

                auto bucketIt = bucket.find(nums[j]);
                if (bucketIt != bucket.end() && bucketIt->second.contains(target)) continue;

                const int sumTwo = -(nums[i] + nums[j]);

                bucketIt = bucket.find(sumTwo);
                if (bucketIt != bucket.end() && bucketIt->second.contains(target)) continue;

                auto it = finder.find(sumTwo);
                if (it == finder.end()) continue;
                if (it->second <= (static_cast<int>(sumTwo == nums[j]) + static_cast<int>(sumTwo == target))) continue;

                output.push_back({target, nums[j], sumTwo});
                targetBucket.insert({sumTwo, nums[j]});
            }
        }


        return output;
    }
};
