#include<iostream>
#include<algorithm>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int start = 0, end = 0, len = 0;
    while(end != s.length()){
        if(s.length() == 1){
            len = 1;
            break;
        }
        if(start != end){
            int tmp_start = 0;
            for(int i = start; i < end; i++){
                if(s[i] == s[end]) tmp_start = i + 1;
            }
            if(tmp_start != 0) start = tmp_start;
            len = max(len, end - start + 1);
        }
        end++;
    }
    return len;
}
int main(){
    string s;
    getline(cin, s);
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}