#include <iostream>
#include <vector>
using namespace  std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<char> nums(n);
    for (int i = 0; i < n; i++){
        nums[i] = 'I';
    }

    for (int i = 0; i < k; i++){
        int f, s;
        cin >> f >> s;
        for (int i = f - 1; i <= s - 1; i++){
            nums[i] = '.';
        }
    }
    
    for (int i = 0; i < n; i++){
        cout << nums[i];
    }
}