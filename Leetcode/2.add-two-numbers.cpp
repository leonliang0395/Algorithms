/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 0 + 5 + 2 = 7
        // (7 + ((4 + 6) / 10 )) * 10 = 80 + (4+6) % 10 = 80
        // 80 * 10 + 4 + 3 = 807

        // 9999 + 9999
        // i = 0
        // 9 + 9 = 18 / 10 = 1
        // Set 1 as carryover
        // currentSum += (18 % 10) * 10^0

        // i = 1
        // 9 + 9 + 1carryover = 19
        // 19 / 10 = 1 carryover
        // currentSum += (18 % 10) * 10^1

        int carryOver = 0;
        int sum = 0;

        ListNode* result = nullptr;
        ListNode* curr = nullptr;

        while(l1 && l2) {
            int currentSum = l1->val + l2->val + carryOver;
            // set next carryover
            carryOver = currentSum / 10;
            int digitToAdd = currentSum % 10;
            if (result == 0) {
                result = new ListNode(digitToAdd);
                curr = result;
            } else {
                curr->next = new ListNode(digitToAdd);
                curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        // Iterate through the remaining digits on l1 or l2 if there are any
        if (l1) {
            while (l1) {
                if (result) {
                    int currentSum = l1->val + carryOver;
                    carryOver = currentSum / 10;
                    int digitToAdd = currentSum % 10;
                    curr->next = new ListNode(digitToAdd);
                    curr = curr->next;
                } else {
                    result = new ListNode(l1->val);
                }
                l1 = l1->next;
            }
        } else if (l2) {
            while (l2) {
                if (result) {
                    int currentSum = l2->val + carryOver;
                    carryOver = currentSum / 10;
                    int digitToAdd = currentSum % 10;
                    curr->next = new ListNode(digitToAdd);
                    curr = curr->next;
                } else {
                    result = new ListNode(l1->val);
                    curr = result;
                }
                l2 = l2->next;
            }
        } 
        
        // Last addition yields a carry over.
        if (carryOver == 1) {
            curr->next = new ListNode(carryOver);
        }

        return result;
    }
};

