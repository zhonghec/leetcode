#include<iostream>
using namespace std;
string longestPalindrome(string s) {
    int length = s.length(), left = 0, max_len = 0;
    string ans = "";
    bool dp[length][length];
    if(length == 1) return s;
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++)
            dp[i][j] = true;
    }
    for(int j=1; j<length; j++){
        for(int i=0; i<length; i++){
            if(s[i] != s[j]) dp[i][j] = false;
            else{
                if(j-i < 3) dp[i][j] = true;
                else dp[i][j] = dp[i+1][j-1];
            }
            if(dp[i][j] && j-i+1 > max_len){
                left = i;
                max_len = j-i+1;
            }
        }
    }
    for(int i=left; i<(left+max_len); i++) ans += s[i];
    return ans;
}
int main(){
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}