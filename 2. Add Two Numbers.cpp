#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *ans = new ListNode;
    ListNode *cur_a = l1, *cur_b = l2, *cur_ans = ans;
    int c_out = 0, flag = 0;
    while(1){
        if(flag) break;
        cur_ans->val = (cur_a->val + cur_b->val + c_out) % 10;
        c_out = (cur_a->val + cur_b->val + c_out) / 10;
        if(cur_a->next != nullptr && cur_b->next != nullptr){
            ListNode *tmp = new ListNode;
            cur_ans->next = tmp;
            cur_ans = cur_ans->next;
            cur_a = cur_a->next;
            cur_b = cur_b->next;            
        }
        else{
            if(cur_a->next == nullptr && cur_b->next == nullptr){
                if(c_out){
                    cur_ans->next = new ListNode;
                    cur_ans->next->val = c_out;
                    break;
                }
                break;
            }
            else if(cur_a->next == nullptr){
                while(1){
                    cur_b = cur_b->next;
                    if(cur_b->next == nullptr){
                        if(c_out){
                            cur_ans->next = new ListNode;
                            cur_ans->next->val = (cur_b->val + c_out) % 10;
                            if((cur_b->val + c_out) / 10 != 0){
                                cur_ans->next->next = new ListNode;
                                cur_ans->next->next->val = c_out;
                                flag = 1;
                                break;
                            }
                            flag = 1;
                            break;
                        }
                        else{
                            cur_ans->next = new ListNode;
                            cur_ans->next->val = cur_b->val;
                            flag = 1;
                            break;
                        }
                    }
                    cur_ans->next = new ListNode;
                    cur_ans->next->val = (c_out + cur_b->val) % 10;
                    c_out = (c_out + cur_b->val) / 10;
                    cur_ans = cur_ans->next;
                }
            }
            else if(cur_b->next == nullptr){
                while(1){
                    cur_a = cur_a->next;
                    if(cur_a->next == nullptr){
                        if(c_out){
                            cur_ans->next = new ListNode;
                            cur_ans->next->val = (cur_a->val + c_out) % 10;
                            if((cur_a->val + c_out) / 10 != 0){
                                cur_ans->next->next = new ListNode;
                                cur_ans->next->next->val = c_out;
                                flag = 1;
                                break;
                            }
                            flag = 1;
                            break;
                        }
                        else{
                            cur_ans->next = new ListNode;
                            cur_ans->next->val = cur_a->val;
                            flag = 1;
                            break;
                        }
                    }
                    cur_ans->next = new ListNode;
                    cur_ans->next->val = (c_out + cur_a->val) % 10;
                    c_out = (c_out + cur_a->val) / 10;
                    cur_ans = cur_ans->next;
                }
            }
        }
    }
    return ans;
}
int main(){
    ListNode *a = new ListNode;
    ListNode *b = new ListNode;
    ListNode *cur_a = a, *cur_b = b;
    string num1, num2;
    cin >> num1 >> num2;
    for(int i=num1.length()-1; i>=0; i--){
        cur_a->val = num1[i] - '0';
        if(i){
            ListNode *tmp = new ListNode;
            cur_a->next = tmp;
            cur_a = cur_a->next;            
        }
    }
    cur_a->next = nullptr;
    for(int i=num2.length()-1; i>=0; i--){
        cur_b->val = num2[i] - '0';
        if(i){
            ListNode *tmp = new ListNode;
            cur_b->next = tmp;
            cur_b = cur_b->next;            
        }
    }
    cur_b->next = nullptr;
    ListNode *ans = addTwoNumbers(a, b);
    ListNode *cur_ans = ans;
    while(cur_ans != nullptr){
        cout << cur_ans->val;
        cur_ans = cur_ans->next;
    }
    cout << endl;
    return 0;
}