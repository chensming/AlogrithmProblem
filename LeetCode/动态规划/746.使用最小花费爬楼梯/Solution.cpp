/*dp[i] 表示到索引为 i 位置再选择向上爬一共需要的体力开销

状态转移方程：
dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]

输出： min(dp[len - 1], dp[len - 2])。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int size = cost.size();
        vector<int> dp(size, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < size; ++i)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        return min(dp[size - 1], dp[size - 1]);
    }
};


class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        size_t size = cost.size();
        //因为只参考了前两行的值，可以将状态数组的长度设置为 3。
        vector<int> dp(3, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < size; ++i) {
            dp[i % 3] = min(dp[(i - 1) % 3], dp[(i - 2) % 3]) + cost[i];
        }
        return min(dp[(size - 1) % 3], dp[(size - 2) % 3]);
    }
};

