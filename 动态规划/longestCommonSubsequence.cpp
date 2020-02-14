#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.length();
        int len2 = text2.length();

        // 有一个为空串则最长公共子序列长度为0
        if(len1 == 0 || len2 == 0){
            return 0;
        }

        // dp[i][j]表示第一个字符串的1~i之间和第二个字符串的
        // 1~j之间的最长公共子序列
        int dp[len1 + 1][len2 + 1];

        for (int j = 0; j <= len1; j++)
        {
            for (int k = 0; k <= len2; k++)
            {
                // 初始状态，空的子串和任意字符串的最长公共子序列是0
                if(j == 0 || k == 0){
                    dp[j][k] = 0;
                }else if (text1[j - 1] == text2[k - 1])
                {
                    dp[j][k] = dp[j - 1][k - 1] + 1;
                }else
                {
                    dp[j][k] = max(dp[j - 1][k], dp[j][k - 1]);
                }
            }
        }

        return dp[len1][len2];
    }
};
int main(){
    Solution so;
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << so.longestCommonSubsequence(str1,str2) << endl;
    return 0;
}