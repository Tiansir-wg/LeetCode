#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len == 1){
            return s;
        }

        // 子串的起点，最大长度
        int start = 0,maxLen = 1;

        //dp[i][j] 表示i~j之间的子串是回文的
        vector<vector<int> > dp(len,vector<int>(len,0));

        // 单个字符是回文的，长度为2的两个相等字符是回文的
        for(int i = 0;i < len;i++){
            dp[i][i] = 1;
            if(i + 1 < len && s[i] == s[i+1]){
                dp[i][i+1] = 1;
                start = i;
                maxLen = 2;
            }
        }

        // 因为判断dp[i][j] 时要用到dp[i + 1][j - 1]，所以
        // 要不断变化子串的起始位置
        for(int sublen = 3;sublen <= len;sublen++){
            for(int i = 0;i + sublen - 1 < len;i++){
                int j = i + sublen - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1] == 1){
                    dp[i][j] = 1;
                    if(maxLen < sublen){
                        maxLen = sublen;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
int main(){
    Solution so;
    string str = "ababa";
    cout << so.longestPalindrome(str);
    return 0;
}