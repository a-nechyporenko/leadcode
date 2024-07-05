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

struct ListNode;

class Solution {
public:
    // Function to calculate the greatest common divisor (GCD) using Euclidean algorithm
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode* current = head;
        while (current && current->next) {
            // Calculate the GCD of current node value and next node value
            int current_val = current->val;
            int next_val = current->next->val;
            int greatest_common_divisor = gcd(current_val, next_val);

            // Insert a new node with the GCD value between the current and next node
            ListNode* new_node = new ListNode(greatest_common_divisor);
            new_node->next = current->next;
            current->next = new_node;

            // Move to the next pair of nodes
            current = current->next->next;
        }
        return head;
    }
};
