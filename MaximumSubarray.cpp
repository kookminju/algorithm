#include <string>
#include <vector>
#include <climits>

using namespace std;

int FindMaxCrossingSubarray(vector<int>& a, const int& low, int& mid, int& high) {
    int leftsum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--) {
        sum = sum + a[i];
        if (sum > leftsum) {
            leftsum = sum;
        }
    }

    int rightsum = INT_MIN;
    sum = 0;

    for (int i = mid+1; i <= high; i++) {
        sum = sum + a[i];
        if (sum > rightsum) {
            rightsum = sum;
        }
    }
    return (leftsum + rightsum);
}

int FindMaximumSubarray(vector<int>& a, const int& low, int& high) {
    int leftsum, rightsum, crosssum;

    if (high == low) {
        return a[low];
    } else {
        int mid = (low + high) / 2;
        leftsum = FindMaximumSubarray(a, low, mid);
        rightsum = FindMaximumSubarray(a, mid+1, high);
        crosssum = FindMaxCrossingSubarray(a, low, mid, high);
        if (leftsum >= rightsum && leftsum >= crosssum) {
            return leftsum;
        } else if (rightsum >= leftsum && rightsum >= crosssum) {
            return rightsum;
        } else {
            return crosssum;
        }
    }
}

int solution(vector<int> param0) {
    int k = param0.size()-1;
    return FindMaximumSubarray(param0, 0, k);
}
