#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int N, A, B;
 
int main(int argc, const char * argv[]) {
    cin >> N >> A >> B;
    vector<int> leftPart, rightPart;
    for (int i = 0; i < N; i ++) {
        int value;
        cin >> value;
        if (i <= (N >> 1)) leftPart.push_back(value);
        else rightPart.push_back(value);
    }
    auto buildSubsetSums = [=](vector<int> data) -> vector<int>{
        int size = (int)data.size();
        vector<int> subsetSums(1 << size);
        for (int i = 0; i < (1 << size); i ++) {
            int maskSum = 0;
            for (int j = 0; j < size; j ++) {
                if (i & (1 << j)) maskSum += data[j];
            }
            subsetSums[i] = maskSum;
        }
        sort(subsetSums.begin(), subsetSums.end());
        return subsetSums;
    };
    leftPart = buildSubsetSums(leftPart);
    rightPart = buildSubsetSums(rightPart);
    
    long long result = 0;
    for (auto value: leftPart) {
        auto lowIndex = lower_bound(rightPart.begin(), rightPart.end(), A - value);
        auto highIndex = lower_bound(rightPart.begin(), rightPart.end(), B - value + 1);
        result += int(highIndex - lowIndex);
    }
    cout << result << '\n';
    
    return 0;
} 
