#include <vector>
#include <string>
#include <climits>

using namespace std;

int solution(vector<string> arr)
{
    int answer;
    vector<int> num; //numbers
    vector<char> o; //operators

    for (int i = 0; i < arr.size(); i+=2) {
        num.push_back(stoi(arr[i]));
    }
    for (int i = 1; i < arr.size(); i+=2) {
        o.push_back(arr[i].front());
    }

    vector<vector<int>> dMax(num.size(), vector<int>(num.size(), INT_MIN));
    vector<vector<int>> dMin(num.size(), vector<int>(num.size(), INT_MAX));

    for (int i = 0; i < num.size(); i++) {
        dMax[i][i] = num[i];
        dMin[i][i] = num[i]
    }

    for (int d = 1; d < num.size(); d++) {
        for (int i = 0, k = d; k < num.size(); i++, k++) {
            for (int j = i; j < k; j++) {
                if (o[j] == '+') {
                    dMax[i][k] = max(dMax[i][k], dMax[i][j] + dMax[j+1][k]);
                    dMin[i][k] = min(dMin[i][k], dMin[i][j] + dMin[j+1][k]);
                } else if (o[j] == '-') {
                    dMax[i][k] = max(dMax[i][k], dMax[i][j] - dMin[j+1][k]);
                    dMin[i][k] = min(dMin[i][k], dMin[i][j] - dMax[j+1][k]);
                }
            }
        }
    }
    answer = dMax[0][num.size()-1];
    return answer;
}
