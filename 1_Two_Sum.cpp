#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for(int i = 0; i < nums.size() - 1; i++) {
            if(result.size() > 0) break;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    result = {i, j};
                    break;
                }
            }
        }

        return result;
        
    }

    // not my solution  O(N)
    vector<int> twoSum(vector<int> &numbers, int target) {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                //+1 because indices are NOT zero based
                result.push_back(hash[numberToFind] + 1);
                result.push_back(i + 1);
                return result;
            }

            //number was not found. Put it in the map.
            hash[numbers[i]] = i;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,5,7,17,9,3,8,13};
    vector<int> result = s.twoSum(nums, 21);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}