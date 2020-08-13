#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;
void print_path(vector<int> path){
    for (int vertex : path){
        cout << vertex << " ";
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;

    vector <int> numbers(n);
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    auto t1 = chrono::high_resolution_clock::now();
    do {
        print_path(numbers);
    }  while (next_permutation(numbers.begin(), numbers.end()));

    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    cout << "Time is " << duration << endl; // 218540999 nanosecs for 7 numbers
    /*
        7 - 218540999 nanosecs
        8 - 2855669712 nanosecs
    */
}