#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int len1 = word1.length();
        int len2 = word2.length();
        // dp[i][j]表示word1前i个字符转化为word2前j个字符
        int dp[len1 + 1][len2 + 1];

        // base case
        for (int i = 0; i <= len1; i++)
        {
            dp[i][0] = i;
        }

        for (int j = 0; j <= len2; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // 添加操作
                    int addDp = dp[i][j - 1] + 1;
                    // 删除操作
                    int delDp = dp[i - 1][j] + 1;
                    // 修改操作
                    int updDp = dp[i - 1][j - 1] + 1;
                    // 三个操作中次数最少的
                    dp[i][j] = min(min(addDp, delDp), updDp);
                }
            }
        }
        return dp[len1][len2];
    }
};

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    Solution so;
    cout << so.minDistance(str1, str2);
    return 0;
}