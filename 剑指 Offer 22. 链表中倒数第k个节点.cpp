/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //先遍历一次，得到n，再遍历输出？
 //快慢指针
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        //遍历
        // int len=0;
        // ListNode* curr=head;
        // for(curr;curr;curr=curr->next){
        //     len++;
        // }
        // for(curr=head;len>k;len--){
        //     curr=curr->next;
        // }
        // return curr;

        //快慢指针
        ListNode* fast=head;
        ListNode* slow=head;
        //设置令fast比slow领先k
        for(int i=0;i<k;i++){
            fast=fast->next;
        }
        //一次遍历求答案
        for(;fast;fast=fast->next){
            slow=slow->next;
        }
        return slow;

    }
};