#include <deque>
#include <iostream>
#include <vector>
using namespace std;

// Test Cases:
// Empty Vector
// One Element, Size One, Size Zero
// Two Elements, Size One, Size Two, Size Three
vector<int> slidingWindowSum(const vector<int> &vec, int windowSize) {
    deque<int> queue;
    int queueSum = 0;
    windowSize = windowSize > vec.size() ? vec.size() : windowSize;
    
    // Initialize queue to initial window
    for (int i = 0; i < windowSize; ++i) {
        queue.push_back(vec[i]);
        queueSum += vec[i];
    }

    // Push the first sum to the vector
    vector<int> result;
    result.push_back(queueSum);

    // Iterate through the rest of the vector
    int ptr = windowSize + 1;
    while(ptr < vec.size()) {
        queueSum -= queue.front();
        queue.pop_front();
        queueSum += vec[ptr];
        queue.push_back(vec[ptr]);
        result.push_back(queueSum);
    }

    // Print Vector
    return result;
}

