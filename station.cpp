#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1;
    int finish = n;
    int index = 0;

    while (start <= finish) {
        int left = stations[index] - w;
        int right = stations[index] + w;
        index++;
        while (start < left) {
            start = start + (2*w) + 1;
            answer++;
        }
        start = right + 1;
        if (index == stations.size() && start <= finish) {
            while (start <= finish) {
                start = start + (2*w) + 1;
                answer++;
            }
        }
    }
