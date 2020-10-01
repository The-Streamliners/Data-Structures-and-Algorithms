// C++ program to change all char from lower to uppper
#include <iostream> 
#include <vector>
#include <map>
using namespace std; 

// provide a vector of integer, find two numbers which can add up to target
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    map<int, int> maps;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        auto iter = maps.find(complement);
        if (iter != maps.end() && iter->second != i) {
            result.push_back(i);
            result.push_back(iter->second);
            break;
        }
        maps[nums[i]] = i;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
