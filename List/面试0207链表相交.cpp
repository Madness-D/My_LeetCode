/* ************************************************************************
> File Name:		面试0207链表相交.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-09 00:03:58
> Link:		https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/
> Description:		给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //哈希法
        unordered_set<ListNode*> st;
        ListNode *currA=headA,*currB=headB;
        while(currA || currB){
            if(currA){
                if(st.find(currA)!=st.end()) return currA;
                else {st.insert(currA);
                currA=currA->next;
                }
            }
            if(currB){
                if(st.find(currB)!=st.end()) return currB;
                else {st.insert(currB);
                currB=currB->next;}
            }
        }
        return nullptr;
    }
};