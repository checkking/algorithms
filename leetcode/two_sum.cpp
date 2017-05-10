/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
#include <vector>
#include <unordered_map>

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    unordered_map<int> map;
    for (vector<int>::const_iterator itr = numbers.begin();
            itr != numbers.end(); ++itr) {
        if (map.cont(target - *itr)) {
            result.push_back(map[target - *itr]);
            result.push_back(itr - numbers.begin() + 1);
            return result;
        }
        map[*itr] = itr - numbers.begin() + 1;
    }

    return result;
}
