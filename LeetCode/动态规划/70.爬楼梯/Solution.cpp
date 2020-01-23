/*
假设你正在爬楼梯，需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶，你有多少种不同的方法可以爬到楼顶呢？
*/
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int nums[n + 1];
        nums[1] = 1;
        nums[2] = 2;
        for(int i = 3; i <= n; i++)
            nums[i] = nums[i - 1] + nums[i - 2];
        return nums[n];
    }
};