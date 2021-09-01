/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 * 如果转换为int 或者long，可能会溢出，不行
 * 逆序，也就是说第一个都是个位，分别相加，超过10就进1？
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res=new ListNode(-1);
    ListNode* p=res;//移动指针
    int sum=0;
    bool jinwei=false;
    while(l1 || l2){
        sum=0;
        if(l1){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->val;
            l2=l2->next;
        }
        if(jinwei){sum++;}
        p->next=new ListNode(sum%10);
        p=p->next;
        jinwei=sum>=10?true:false;
    }
    if(jinwei){//最后需要进位
        p->next=new ListNode(1);
    }
    return res->next;
    }
};
// @lc code=end

