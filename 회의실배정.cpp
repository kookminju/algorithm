#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int> > arr)
{
    int answer = 1;

    sort(arr.begin(), arr.end());
    int end = arr[0][1];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i][0] >= end) {
            answer++;
            end = arr[i][1];
        } else {
            if (arr[i][1] < end){
                end = arr[i][1];
            }
        }
    }
    return answer;
}
