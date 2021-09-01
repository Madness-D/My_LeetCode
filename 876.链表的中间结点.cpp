/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
 * 
 * 遍历一遍，找到长度n
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len=0;
        ListNode* Res;
        Res=head;//不是=head->next
        while(Res){
            len++;
            Res=Res->next;
        }
        Res=head;
        int pt=len/2;
        for(int i=0;i<pt;i++){
            Res=Res->next;
        }
        return Res;
    }
};
// @lc code=end

