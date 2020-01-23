/*
给定一个整数数组  nums，
求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，
包含 i,  j 两点。
//改代码出bug仍未解决!!!!
*/
#include <vector>
using namespace std;

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        if (nums.size() > 0)
        {
            sums = new int[nums.size() + 1];
            sums[0] = nums[0];
            for (int i = 0; i < nums.size(); i++)
                sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j)
    {
        return sums[j + 1] - sums[i];
    }

    ~NumArray()
    {
        delete[] sums;
    }

private:
    int *sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */