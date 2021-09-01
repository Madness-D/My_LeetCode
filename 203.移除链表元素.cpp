/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* preHead=new ListNode(0,head);
        ListNode* pre=preHead;
        while(pre->next!=nullptr){
            if(pre->next->val==val){
                pre->next=pre->next->next;
            }else{
                pre=pre->next;
            }
        }
    return preHead->next;
    }
};
// @lc code=end

