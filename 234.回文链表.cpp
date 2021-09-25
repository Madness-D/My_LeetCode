/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        ////存到数组里,双指针.复杂度O(n+m/2)=O(n)
        // vector<int> temp;
        // while(head){
        //     temp.push_back(head->val);
        //     head=head->next;
        // }
        // int l=0,r=temp.size()-1;
        // while(l<r){
        //     if(temp[l]!=temp[r]) return false;
        //     ++l;
        //     --r;
        // }
        // return true;


        //快慢指针找到中点
        //然后反转,比较
        //https://leetcode-cn.com/problems/palindrome-linked-list/solution/wo-de-kuai-man-zhi-zhen-du-cong-tou-kai-shi-gan-ju/

        if(head == NULL || head->next == NULL) {
            return true;
        }
        ListNode *slow = head, *fast = head;
        ListNode *pre = head, *prepre = NULL;
        //快慢指针找到中点,同时pre和prepre实现了反转
        while(fast != NULL && fast->next != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = prepre;
            prepre = pre;
        }
        
        if(fast != NULL) {
            slow = slow->next;
        }
        //这个时候,slow继续向后,遍历后半部分
        //pre遍历已经反转的前半部分
        while(pre != NULL && slow != NULL) {
            if(pre->val != slow->val) {
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end

