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
        // //哈希法
        // unordered_set<ListNode*> st;
        // ListNode *currA=headA,*currB=headB;
        // while(currA || currB){
        //     if(currA){
        //         if(st.find(currA)!=st.end()) return currA;
        //         else {st.insert(currA);
        //         currA=currA->next;
        //         }
        //     }
        //     if(currB){
        //         if(st.find(currB)!=st.end()) return currB;
        //         else {st.insert(currB);
        //         currB=currB->next;}
        //     }
        // }
        // return nullptr;

        // //上面的方法，空间复杂度较高
        // //先求出两个链表的长度，再让长的链表移动到与短链表末尾对齐
        // //逐个对比是否相等
        // ListNode* currA=headA,*currB=headB;
        // //求a b长度
        // int la=0,lb=0;
        // while(currA){
        //     la++;currA=currA->next;
        // }
        // while(currB){
        //     lb++;currB=currB->next;
        // }
        // //重置curr指针
        // currA=headA;
        // currB=headB;
        // //交换，确保currA指向的是长的链表
        // if(la<lb){
        //     swap(currA,currB);
        //     swap(la,lb);
        // }
        // //移动，使尾部对齐
        // int t=la-lb;
        // while(t--){
        //     currA=currA->next;
        // }
        // //比较，找交点
        // while(currA){
        //     if(currA==currB) return currA;
        //     else{
        //         currA=currA->next;
        //         currB=currB->next;
        //     }
        // }
        // return nullptr;

        //双指针，当走完一遍后交换再走一遍，相交则会相遇，否则会同时到达nullptr
        ListNode *curA=headA,*curB=headB;
        while(curA!=curB){
            curA=curA?curA->next:headB;
            curB=curB?curB->next:headA;
        }
        return curA;
    }
};