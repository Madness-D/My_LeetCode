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
        // //哈希
        // unordered_map<ListNode*, int> mp;
        // // ListNode* preHead=new ListNode(0,head);
        // // ListNode* cur=preHead;
        // while(head!=nullptr){
        //     if(mp[head]){return head;}
        //     else{
        //     mp[head]++;
        //     head=head->next;
        // }
        // }
        // return nullptr;

        //快慢指针
        //快指针比慢快一倍
        //设链表中环外部分的长度为a。slow 指针进入环后，又走了b的距离与 fast相遇
        //a+n(b+c)+b=2(a+b)
        //a=c+(n+1)(b+c)
        //相遇后设置一个指针从起点出发，会和slow指针相遇于环的起点
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr){
            if (fast->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow){//相遇
            ListNode* ptr=head;
            while(ptr!=slow){
                ptr=ptr->next;
                slow=slow->next;
            }
            return ptr;

            }
        }
        return nullptr;//相遇的地方不一定是入环的地方
    }
};
// @lc code=end

