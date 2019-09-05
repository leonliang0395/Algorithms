#include "common.h"

void rotateLayer(vector<vector<int>> &a , int start, int end) {
    for (int cur = 0; start + cur < end; ++cur) {
        int top = a[start][start + cur]; // save the top
        a[start][start + cur] = a[end - cur][start]; // left to top
        a[end - cur][start] = a[end][end - cur]; // bottom to left
        a[end][end - cur] = a[start + cur][end];// right to bottom
        a[start + cur][end] = top;// top to right
    }
}

void rotateMatrix(vector<vector<int>> &a) {
    if (a.empty() || a.size() != a[0].size()) {
        return;
    }

    for (int layer = 0; layer < a.size() / 2; ++layer) {
        rotateLayer(a, layer, a.size() - 1 - layer);
    }
}

int maxTwoTrades(const vector<int> &arr) {
    // Create the max to i vector
    vector<int> maxToI(arr.size());
    int maxProfitNow = 0;
    int minSoFar = numeric_limits<int>::max();
    for (int i = 0; i < arr.size(); ++i) {
        minSoFar = min(minSoFar, arr[i]);
        maxProfitNow = max(arr[i] - minSoFar, maxProfitNow);
        maxToI[i] = maxProfitNow;
    }

    // Create the max from i vector
    vector<int> maxFromI(arr.size());
    maxProfitNow = 0;
    int maxSoFar = numeric_limits<int>::min();
    for (int i = arr.size() - 1; i >= 0; --i) {
        maxSoFar = max(maxSoFar, arr[i]);
        maxProfitNow = max(maxSoFar - arr[i], maxProfitNow);
        maxFromI[i] = maxProfitNow;
    }

    int maxTwoTrades = 0;
    for (int i = 0; i < arr.size(); ++i) {
        maxTwoTrades = max(maxToI[i] + maxFromI[i], maxTwoTrades);
    }

    return maxTwoTrades;
}

int subarraySum(vector<int>& nums, int sum) {
    // STL map to store number of subarrays 
    // starting from index zero having  
    // particular value of sum. 
    unordered_map<int, int> prevSum; 

    int res = 0; 

    // Sum of elements so far. 
    int currsum = 0; 

    for (int i = 0; i < nums.size(); i++) { 

        // Add current element to sum so far. 
        currsum += nums[i]; 

        // If currsum is equal to desired sum, 
        // then a new subarray is found. So 
        // increase count of subarrays. 
        if (currsum == sum)  
            res++;         

        // currsum exceeds given sum by currsum  
        //  - sum. Find number of subarrays having  
        // this sum and exclude those subarrays 
        // from currsum by increasing count by  
        // same amount. 
        if (prevSum.find(currsum - sum) !=  
                                prevSum.end())  
            res += (prevSum[currsum - sum]); 
        

        // Add currsum value to count of  
        // different values of sum. 
        prevSum[currsum]++; 
    } 

    return res; 
}

pair<pair<int, int>, int> maxContiguousSubarray(const vector<int> &arr) {
    int maxSoFar = arr[0];
    int maxNow = arr[0];
    int start = 0;
    int end = 0;
    int currStart = 0;

    for (int i = 0; i < arr.size(); ++i) {
        maxNow = maxNow + arr[i];
        if (maxNow < arr[i]) {
            maxNow = arr[i];
            currStart = i;
        }

        if (maxNow > maxSoFar) {
            maxSoFar = maxNow;
            start = currStart;
            end = i;
        }
    }

    return std::make_pair(std::make_pair(start, end), maxSoFar);
}

void DNF (std::vector<int> &vec, int i) {
    if (vec.size() <= 1) return;

    int low = -1;
    int mid = -1;
    int high = vec.size();

    while (mid + 1 < high) {
        if (vec[mid + 1] < vec[i]) {
            std::swap(vec[mid + 1], vec[low + 1]);
            ++mid;
            ++low;
        } else if (vec[mid + 1] == vec[i]) {
            ++mid;
        } else {
            std:;swap(vec[mid + 1], vec[high - 1]);
            --high;
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
            vec[current++] = helper[helperLeft++];
        } else {
            vec[current++] = helper[helperRight++];
        }
    }

    // Copy rest of left side of array into target array
    int remaining = middle - helperLeft;
    for (int i = 0; i <= remaining; ++i) {
        vec[current + i] = helper[helperLeft + i];
    }
}

// Classic mergesort
void mergesort(vector<int>& vec, vector<int>& helper, int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;
        // The goal here is to build the recursion stack until the leaf levels.
        // Since mergesort will return when low >= high, this is when the first call is referring to a subarray of size 1.
        // At that point, the second mergesort call will be from middle + 1, which is the element right next to the left array element.
        mergesort(vec, helper, low, middle);
        mergesort(vec, helper, middle + 1, high);
        merge(vec, helper, low, middle, high);
    }
}

int main() {
    return 0;
}