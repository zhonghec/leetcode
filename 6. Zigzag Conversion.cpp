#include<iostream>
#include<vector>
using namespace std;
string convert(string s, int numRows) {
    vector<char> c[numRows];
    string ans = "";
    int len = s.length(), cnt = 0, flag = 0;
    if(numRows == 1) return s;
    while(cnt < len){
        if(flag) break;
        for(int i=0; i<numRows-1; i++){
            c[i].push_back(s.at(cnt));
            if(cnt + 1 == len){
                flag = 1;
                break;
            }
            else cnt++;
        }
        if(flag) break;
        for(int i=numRows-1; i>0; i--){
            c[i].push_back(s.at(cnt));
            if(cnt + 1 == len){
                flag = 1;
                break;
            }
            else cnt++;
        }
    }
    for(int i=0; i<numRows; i++){
        for(auto j : c[i]) ans += j;
    }
    return ans;
}
int main(){
    string s;
    cin >> s;
    int numRows;
    cin >> numRows;
    cout << convert(s, numRows) << endl;
    return 0;
}