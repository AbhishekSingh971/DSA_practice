
// Definition for singly-linked list.
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;
        
        // Traverse both lists until both are exhausted and no carry
        while (l1 != nullptr || l2 != nullptr || carry) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            cout<<"Adding: "<<val1<<" + "<<val2<<" + carry "<<carry<<endl;
            
            int sum = val1 + val2 + carry;
            carry = sum / 10;              // Carry for next iteration
            int digit = sum % 10;          // Current digit
            
            current->next = new ListNode(digit);
            current = current->next;
            
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        
        return dummyHead->next;
    }
    
    void printList(ListNode* head) {
        cout << "[";
        while (head != nullptr) {
            cout << head->val;
            if (head->next != nullptr) cout << ",";
            head = head->next;
        }
        cout << "]" << endl;
    }

    ListNode* createNode(vector<int> values){
        if(values.empty()) return nullptr;

        ListNode* head = new ListNode(values[0]);
        ListNode* currentNode = head;
        for(int i=1;i<values.size();i++){
            currentNode->next =new ListNode(values[i]);
            currentNode = currentNode->next;
        }
        return head;
    }
};

int main(){
    Solution solution = Solution();
    
    // Example 1: 342 + 465 = 807
    // [2,4,3] represents 342, [5,6,4] represents 465
    ListNode* l1 = solution.createNode({2, 4, 3});
    ListNode* l2 = solution.createNode({5, 6, 4});
    ListNode* result = solution.addTwoNumbers(l1, l2);
    cout << "Example 1: ";
    solution.printList(result);
    cout << "Explanation: 342 + 465 = 807" << endl << endl;    
    return 0;
}