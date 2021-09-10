/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {


public:
struct ListNode
{
    int data;
    ListNode* next;
    ListNode():data(0),next(nullptr){}
    ListNode(int val):data(val),next(nullptr){}
};
    //ListNode* head;
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummyhead=new ListNode();
        sz=0;
    }
    

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=sz||index<0) return -1;
        ListNode* curr=dummyhead->next;
        for(int i=0;i<index;i++){//***
            curr=curr->next;
        }
        return curr->data;

    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newHead=new ListNode(val);
        newHead->next=dummyhead->next;
        dummyhead->next=newHead;
        sz++;

    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* newTail=new ListNode(val);
        ListNode* curr=dummyhead;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=newTail;
        sz++;

    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index==sz){addAtTail(val);return;}
        if(index>sz){return;}
        if(index<0){addAtHead(val);return;}
        else{
        ListNode* newIndex=new ListNode(val);
        ListNode* curr=dummyhead;
        sz++;
        for(int i=0;i<index;i++){
            curr=curr->next;
        }
        newIndex->next=curr->next;
        curr->next=newIndex;

        }

    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0||index>=sz){return;}
        ListNode* curr=dummyhead;
        for(int i=0;i<index;i++){
            curr=curr->next;
        }
        curr->next=curr->next->next;
        sz--;
    }
private:
    ListNode* dummyhead;
    int sz;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

