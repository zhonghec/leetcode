#include<iostream>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    int size = nums.size();
    int flag = 0;
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(nums.at(i)+nums.at(j) == target){
                ans.push_back(i);
                ans.push_back(j);
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    return ans;
}

int main(){
    vector<int> s;
    int target = 0;
    while(1){
        int num;
        cin >> num;
        if(!num) break;
        s.push_back(num);
    }
    cin >> target;
    vector<int> ans = twoSum(s, target);
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}