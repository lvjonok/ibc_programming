#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
using namespace std;

int get_path_cost(vector<int> vertices, vector<vector<int>> paths, int n){
    int path_cost = 0;
    for (int i = 0; i < n; i++){
        path_cost += paths[vertices[i]][vertices[(i + 1) % n]];
    }
    return path_cost;
}

void print_path(vector<int> path){
    cout << "Path is ";
    for (int vertex : path){
        cout << vertex << " ";
    }
    cout << "0" << endl;
}

vector<vector<int>> permutations;

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
        permutations.push_back(array);
        return array;
    }
}

int main(){
    // programming assignment 3 on second day
    int n;
    cin >> n;

    vector <vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    auto t1 = chrono::high_resolution_clock::now();

    vector <int> path(n);
    vector <int> min_path;
    for (int i = 0; i < n; i++){path[i] = i;}

    int min_path_cost = 32000;

    get_permutations(vector<int>(), path);

    for (auto local_path : permutations){
        if (local_path[0] != 0) continue;
        int calc_cost = get_path_cost(local_path, matrix, n);
        if (calc_cost < min_path_cost){
            min_path_cost = calc_cost;
            min_path = local_path;
        }
    }

    // do {
    //     int calc_cost = get_path_cost(path, matrix, n);
    //     if (calc_cost < min_path_cost){
    //         min_path_cost = calc_cost;
    //         min_path = path;
    //     }
    // } while (next_permutation(path.begin(), path.end()));

    cout << min_path_cost << endl;
    print_path(min_path);

    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    cout << "Time is " << duration << endl; // 3318197 nanosecs
}