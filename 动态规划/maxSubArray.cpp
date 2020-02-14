#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        // dp[i] 表示以下表为i的字符结束的数组的最大子段和
        vector<int> dp(len);
        dp[0] = nums[0];
        for(int i = 1;i < len;i++){
            dp[i] = max(dp[i - 1] + nums[i],nums[i]);
        }

        // 选取一个最大值
        int maxIndex = 0;
        for(int i = 1;i < len;i++){
            if(dp[i] > dp[maxIndex]){
                maxIndex = i;
            }
        }
        return dp[maxIndex];
    }
};

