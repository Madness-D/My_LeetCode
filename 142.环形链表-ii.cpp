/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        //哈希
        unordered_map<ListNode*, int> mp;
        // ListNode* preHead=new ListNode(0,head);
        // ListNode* cur=preHead;
        while(head!=nullptr){
            if(mp[head]){return head;}
            else{
            mp[head]++;
            head=head->next;
        }
        }
        return nullptr;

        // //快慢指针，未完成
        // ListNode* slow=new ListNode(0,head);
        // ListNode* fast=head;
        // while(slow!=fast){
        //     if (fast == nullptr || fast->next == nullptr) {
        //         return nullptr;
        //     }
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // return slow;//相遇的地方不一定是入环的地方
    }
};
// @lc code=end

