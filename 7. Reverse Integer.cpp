#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
int reverse(int x) {
    long digit = 0, s[10] = {0}, ans = 0;
    if(x <= 9 && x >= -9) return x;
    while(x != 0){
        s[digit++] = x % 10;
        x /= 10; 
    }
    for(int i=0; i<digit; i++)
        ans += pow(10, digit-i-1) * s[i];
    if(ans > INT_MAX || ans < INT_MIN) return 0;
    return ans;
}
int main(){
    int x;
    while(cin >> x){
        cout << reverse(x) << endl;
    }
    return 0;
}