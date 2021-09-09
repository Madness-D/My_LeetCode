/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr){
            return nullptr;
        }
        ListNode* CurrA=headA;
        ListNode* CurrB=headB;
        // unordered_map<ListNode*,int> mp;
        // while(CurrA){
        //         mp[CurrA]++;
        //         CurrA=CurrA->next;
        // }
        // while(CurrB){
        //     if(mp[CurrB]){
        //         return CurrB;
        //     }else{
        //         CurrB=CurrB->next;
        //     }
        // }
        // return nullptr;

        //双指针
        while(CurrA!=CurrB){
            CurrA=CurrA!=nullptr?CurrA->next:headB;
            CurrB=CurrB!=nullptr?CurrB->next:headA;
        }
        return CurrA;

        
    }
};
// @lc code=end

