#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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

    vector <int> path(n);
    vector <int> min_path;
    for (int i = 0; i < n; i++){path[i] = i;}

    int min_path_cost = 32000;

    do {
        int calc_cost = get_path_cost(path, matrix, n);
        if (calc_cost < min_path_cost){
            min_path_cost = calc_cost;
            min_path = path;
        }
    } while (next_permutation(path.begin(), path.end()));

    cout << min_path_cost << endl;
    print_path(min_path);
}