// Author: cdsss
// This is the code for LeetCode <1. TwoSum https://leetcode.com/problems/two-sum/>
//
// Description
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example: 
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return[0, 1].

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result;
	unordered_map<int, int> hashmap;
	for (int i = 0; i < nums.size(); ++i) {
		hashmap.insert(make_pair(nums[i], i));
		if (hashmap.find(target - nums[i]) != hashmap.end() && hashmap.find(target - nums[i])->second != i) {
			result.push_back(hashmap.find(target - nums[i])->second);
			result.push_back(i);
			break;
		}
	}
	return result;
}

int main() {
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> res = { 0, 1 };
	vector<int> result = twoSum(nums, target);
	if (result.size() == 0 && res.size() != 0) {
		cout << "FALSE" << endl;
		return false;
	}
	for (int i = 0; i < 2; ++i) {
		if (res[i] != result[i]) {
			cout << "FALSE" << endl;
			return false;
		}
	}
	cout << "True" << endl;
	return true;
}
