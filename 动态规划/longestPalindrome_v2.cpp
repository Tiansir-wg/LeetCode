#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len == 1){
            return s;
        }

        int start = 0,maxLen = 1;
        // dp[i][j]表示字符串的i~j之间是回文串
        bool dp[len][len];
        for(int i = 0;i < len;i++){
            for(int j = i;j < len;j++){
                if(i == j){
                    dp[i][j] = true;
                }else if(dp[i + 1][j - 1] == true && s[i] == s[j]){
                    dp[i][j] = 1;
                }else if(j - i == 1 && s[i] == s[j]){
                    dp[i][j] = 1;
                    maxLen = 1;
                    start = i;
                }
            }
        }

        for(int i = 0;i < len;i++){
            for(int j = i;j < len;j++){
                if(dp[i][j] && j - i + 1 > maxLen){
                    maxLen =  j - i + 1; 
                    start = i; 
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