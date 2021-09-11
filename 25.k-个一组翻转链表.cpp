/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
#include<iostream>
#include<utility>
using namespace std;

//  //Definition for singly-linked list.
//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
 
class Solution {
public:
    //在206的基础上修改，返回头和尾节点
    pair<ListNode*,ListNode*>reverseList(ListNode* head,ListNode *tail) {// 题206的题解，讲链表反转后返回链表
        ListNode* preNode=tail->next;//前驱节点
        ListNode* curr=head;//当前节点
        while(preNode!=tail){
            ListNode* temp=curr->next;//临时指针，存储下一个节点
            curr->next=preNode;
            preNode=curr;
            curr=temp;
        }
        return {tail,head};
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        //结合206题反转链表 和143题 重排链表
        //遍历，每k个节点，反转一下
        //大致思路正确，实现能力菜鸡
        if(k==1){
            return head;
        }
ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;

            pair<ListNode*, ListNode*> result = reverseList(head, tail);
            head = result.first;
            tail = result.second;
            //tie起到将pair解包的作用，这里是 C++17 的写法，也可以写成上面的样子
            //tie(head, tail) = reverseList(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;

    }
};
// @lc code=end

