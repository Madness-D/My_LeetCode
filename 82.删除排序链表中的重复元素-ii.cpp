/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
//和下一题相比，这一题的头结点可能被删除，因此需要设置哑结点
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){return head;}
    
        ListNode* prehead=new ListNode(0,head);
        ListNode* curr=prehead;

        while(curr->next && curr->next->next){//&& 的顺序也有影响
            if(curr->next->val==curr->next->next->val){
                    int x=curr->next->val;
                    while(curr->next && curr->next->val==x){
                        curr->next=curr->next->next;
                    }
            }else{
                curr=curr->next;
            }
        }

        return  prehead->next;


    }
};
// @lc code=end

