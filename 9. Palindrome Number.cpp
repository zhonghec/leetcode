#include<iostream>
#include<vector>
using namespace std;
bool isPalindrome(int x) {
    vector<int> s;
    if(x < 0) return false;
    else if(x >= 0 && x < 10) return true;
    else{
        while(x){
            s.push_back(x % 10);
            x /= 10;
        }
        for(int i=0; i<s.size(); i++){
            if(s.at(i) != s.at(s.size()-i-1)) return false;
        }
        return true;
    }
}
int main(){
    int x;
    cin >> x;
    if(isPalindrome(x)) cout << "true\n";
    else cout << "false\n";
    return 0;
}