#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class Solution {
private:
// 以i位置为中心向两边扩散
int expandAroundCenter(string str,int left,int right){
    while(left >= 0 && right < str.length() && str[left] == str[right]){
        left--;
        right++;
    }
    return right - left - 1;
}
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len == 1){
            return s;
        }
        int start = 0,end = 0,maxLen = 0;
        for(int i = 0;i < len;i++){
            int len1 = expandAroundCenter(s,i,i);
            int len2 = expandAroundCenter(s,i,i+1);
            maxLen = max(maxLen,max(len1,len2));
            if(maxLen > end - start + 1){
                // 此处为了处理偶数个数的字符串
                start = i - (maxLen - 1) / 2;
                end = i + maxLen / 2;
            }
        }
        return s.substr(start,maxLen);
    }
};
int main(){
    string s = "babad";
    Solution so;
    cout << so.longestPalindrome(s) << endl;
    return 0;
}