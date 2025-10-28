#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index

    for(int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];

        // If complement exists → found the pair
        if(mp.find(diff) != mp.end()) {
            return {mp[diff], i};
        }

        mp[nums[i]] = i; // Store index
    }

    return {}; // No solution case
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    cout << result[0] << " " << result[1]; // Output: 0 1
}
