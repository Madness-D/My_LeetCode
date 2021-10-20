/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* creatList(vector<int> a){
        int n=a.size();
        ListNode* root=new ListNode(a[0]);
        ListNode* pnode=root;

        for(int i=0;i<n-1;i++){
            root->val=a[i];
            root->next=nullptr;

            ListNode *p= new ListNode();
            p->val=a[i+1];
            p->next=nullptr;

            root->next=p;
            //root=p;
            root=root->next;
        }

        root->next=nullptr;
        return pnode;
    }

    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        //先来一个暴力的方法，将链表里的数据存到数组里，sort，然后再构建一个链表
        vector<int> nums;
        ListNode* curr=head;
        while(curr){
            nums.push_back(curr->val);
            curr=curr->next;
        }
        //排序
        sort(nums.begin(),nums.end());
        ////构建新的链表
        // ListNode* res;
        // curr=res;
        // for(int i=0;i<nums.size();i++){
        //     curr->val=nums[i];
        //     curr=curr->next;
        // }
        
        return creatList(nums);
    }
};
// @lc code=end

