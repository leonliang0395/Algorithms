#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int peasant_divison_helper(int dividend, int divisor) {
    int tempResult = divisor;
    int quotient = 1;
    // Multiply by 2 until tempResult is equal to or greater than dividend
    while (tempResult < dividend) {
        tempResult <<= 1;
        quotient <<= 1;
    }

    if (tempResult == dividend) {
        return quotient;
    } else if (tempResult > dividend) {
        quotient >>= 1;
        return quotient + peasant_divison_helper(dividend - (tempResult >> 1), divisor);
    }
}

// Integer division without using '/' or '*'
// 13/0
// 13/-1
// 25/5
// 5/25
int peasant_divison(int dividend, int divisor) {
    if (divisor == 0) return -1;
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (dividend == 1) return divisor;
    if (dividend == divisor) return 1;

    int result = peasant_divison_helper(dividend, divisor);

    if ((divisor < 0) ^ (dividend < 0)) {
        result = 0 - result;
    }

    return result;

}

// Number to Excel Column
// 1->A
// Z->26
// AZ->52
string num_to_excel(int num) {
    if (num <= 0) return "invalid";
    ostringstream oss;
    while (num > 0) {
        if (num % 26 == 0) {
            oss << "Z";
            num = num / 26 - 1;
        } else {
            oss << "A" + (num % 26 - 1);
            num = num / 26;
        }
    }
    string result = oss.str();
    reverse(result.begin(), result.end());
    return result;
}

// Implementation of atoi
// atoi basically converts a number as a string into an integer.
// Think about test cases:
// 183
// 0
// -193
// -0
// abc
// +-0
// +-23+2
int atoi_manual(char* numStr) {
    if (numStr == nullptr) throw std::runtime_error();

    int result = 0;
    bool negative = false;
    int start = 0;
    if (numStr[0] == '-') {
        negative = true;
        ++start;
    }
    for (;numStr[start] != '\0'; ++start) {
        if (!isnum(numStr[start] - '0')) {
            throw std::runtime_error();
        }
        result = (result * 10) + (numStr[start] - '0');
    }

    if (negative) {
        result *= -1;
    } 

    return result;
}

// iterative inorder traversal of a binary tree
void iter_inorder_traversal(TreeNode* head) {
    if (head == nullptr) return;

    deque<TreeNode*> treeStack;
    while (!treeStack.empty() || head != nullptr) {
        // Go to the left most node while pushing onto the stack the nodes you pass by.
        if (head != nullptr) {
            treeStack.push_front(head);
            head = head->left;
        } else {
            head = treeStack.front();
            treeStack.pop();
            head = head->right;
        }
    }
}

void merge(vector<int>& vec, vector<int>& helper, int low, int middle, int high) {
    // copy both halves into helper array
    for (int i = low; i <= high; ++i) {
        helper[i] = vec[i];
    }

    int helperLeft = low; //Beginning of left half
    int helperRight = middle + 1; // Beginning of right half
    int current = low;

    // Iterate through helper array, compare left and right half, copying back the smaller 
    // element from the two halves into the original array
    while (helperLeft <= middle && helperRight <= high) {
        if (helper[helperLeft] <= helper[helperRight]) {
            array[current++] = helper[helperLeft++];
        } else {
            array[current++] = helper[helperRight++];
        }
    }

    // Copy rest of left side of array into target array
    int remaining = middle - helperLeft;
    for (int i = 0; i <= remaining; ++i) {
        array[current + i] = helper[helperLeft + i];
    }
}

void mergesort(vector<int>& vec, vector<int>& helper, int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;
        mergesort(vec, helper, low, middle);
        mergesort(vec, helper, middle + 1, high);
        merge(vec, helper, low, middle, high);
    }
}

// Hamming distance is the number of bits that differ between two numbers.
int hammingDistance(int x, int y) {
    int diff = x^y;
    int count = 0;
    while (diff)
    {
        count += diff & 1;
        diff >>= 1;
    }
    return count;
}

int main() {

    return 0;
}