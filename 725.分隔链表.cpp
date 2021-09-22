/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //循环一次得到链表长度len
        int  len=0;
        ListNode* curr=head;
        while(curr){
            len++;
            curr=curr->next;
        }
        int perlen=len/k;
        int num=len-perlen*k;
        //前num个,perlen+1,后面的k-num个,perlen

        vector<ListNode*> res(k,nullptr);
        curr = head;
        for (int i = 0; i < k && curr != nullptr; i++) {
            res[i] = curr;
            int partSize = perlen + (i < num ? 1 : 0);
            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }
            //使每个的最后一个元素的指针指向null
            ListNode *next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        return res;


    }
};
// @lc code=end

