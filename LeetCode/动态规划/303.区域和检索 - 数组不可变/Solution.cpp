/*
给定一个整数数组  nums，
求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，
包含 i,  j 两点。
*/
#include <vector>
using namespace std;

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        sums[0] = nums[0];
        for (int i = 1; i <= nums.size(); i++)
            sums[i] = sums[i - 1] + nums[i];
    }

    int sumRange(int i, int j)
    {
        return sums[j + 1] - sums[i];
    }

private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */