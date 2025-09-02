// questions : https://leetcode.com/problems/add-two-numbers/



//MY CODE

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // pointers are passed by value
        // so temps not actually needed
        // if you ever want to pass a pointer by reference use & (eg: int* &x)
        
        ListNode* temp1=l1;
        ListNode* temp2 =l2;
        ListNode* l3= NULL;
        ListNode* mov;

        int carry=0;

        int num=0;

        while(temp1!=NULL || temp2 !=NULL){ 
            int d1=0;
            int d2=0;
            

            if(temp1 != NULL){
                d1=temp1->val;
                temp1=temp1->next;
            }

            if(temp2 != NULL){
                d2=temp2->val;
                temp2=temp2->next;
            }
            
            int sum=d1+d2+carry;
            carry=sum/10;
            int t=sum%10;
                

            ListNode* temp= new ListNode(t);
            if(l3==NULL) {
                l3=temp;
                mov=l3;
                }
            else{
                mov->next=temp;
                mov=mov->next;
            }
        }
        if(carry>0){
            ListNode* temp= new ListNode(carry);
            mov->next=temp;
            mov=mov->next;
        }
            
        
        return l3;
    }

};


// CLAUDE KA THODA CLEANER CODE
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1. Use a dummy node to simplify list creation.
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        int carry = 0;

        // 2. Loop as long as there are digits to process OR a carry exists.
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // 3. Get values, defaulting to 0 if a list is exhausted.
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            // 4. Create the new node and append it.
            current->next = new ListNode(sum % 10);
            current = current->next;
            
            // 5. Advance l1 and l2 pointers if they exist.
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        // The result is the list after the dummy node.
        ListNode* result = dummyHead->next;
        delete dummyHead; // Avoid memory leak
        return result;
    }
};