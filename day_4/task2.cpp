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
vector<int> get_permutations(vector<int> array, vector<int> left_values){
    vector<vector<int>> answer;
    if (left_values.size() != 0){
        for (auto value: left_values){
            vector<int> new_array = array;
            new_array.push_back(value);
            vector<int> new_values;
            for (auto left_value: left_values){
                if (left_value != value) new_values.push_back(left_value);
            }
            vector<int> local_ans = get_permutations(new_array, new_values);
            answer.push_back(local_ans);
        }
        return array;
    } else {
        print_path(array);
        return array;
    }
}



int main(){
    int n;
    cin >> n;

    vector <int> numbers(n);
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    auto t1 = chrono::high_resolution_clock::now();
    // do {
    //     print_path(numbers);
    // }  while (next_permutation(numbers.begin(), numbers.end()));
    get_permutations(vector<int>(), numbers);
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    cout << "Time is " << duration << endl; // 218540999 nanosecs for 7 numbers
    /*
        7 - 218540999 nanosecs
        8 - 2855669712 nanosecs
    */
}