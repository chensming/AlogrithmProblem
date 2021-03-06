/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组
（子数组最少包含一个元素），返回其最大和。
*/


#include<limits.h>
#include<vector>
using namespace std;
//分治策略
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    int helper(vector<int>& nums, int left, int right){
    	if(left == right) 
    		return nums[left];

    	int p = (left + right) / 2;

    	int leftSum = helper(nums, left, p);
    	int rightSum = helper(nums, p + 1, right);
    	int crossSum = crossSumFunc(nums, left, right, p);

    	return max(max(leftSum, rightSum), crossSum);
    }


    int crossSumFunc(vector<int>& nums, int left, int right, int p){
    	if (left == right)
    		return nums[left];

    	int leftSubSum = INT_MIN;
    	int currSum = 0;
    	for(int i = p; i > left - 1; --i){
    		currSum += nums[i];
    		leftSubSum = max(leftSubSum, currSum);
    	}

    	int rightSubSum = INT_MIN;
    	currSum = 0;
    	for(int i = p + 1; i < right + 1; ++i){
    		currSum += nums[i];
    		rightSubSum = max(rightSubSum, currSum);
    	}

    	return leftSubSum + rightSubSum;
    }
};


//贪心策略
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currSum = nums[0], maxSum = nums[0];

        for(int i = 1; i < n; ++i){
        	currSum = max(nums[i], currSum + nums[i]);
        	maxSum = max(maxSum, currSum);
        }
    	return maxSum;
    }
};



//动态规划
class Solution3 {
public:
	int maxSubArray(vector<int>& nums){
		int n = nums.size();
		int maxSum = nums[0];
		for(int i = 1; i < n; ++i){
			if(nums[i - 1] > 0)
				nums[i] += nums[i - 1];
			maxSum = max(nums[i], maxSum);
		}
		return maxSum;
	}
};