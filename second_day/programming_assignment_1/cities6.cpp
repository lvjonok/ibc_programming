#include <iostream>
#include <vector>
#include <map>
using namespace std;

int get_path_cost(vector<int> vertices, vector<vector<int>> paths, int n){
    int path_cost = 0;
    for (int i = 0; i < n; i++){
        path_cost += paths[vertices[i]][vertices[(i + 1) % n]];
    }
    return path_cost;
}

bool is__path_valid(vector<int> vertices, int n){
    map<int, bool> contains;
    for (int i = 0; i < n; i++){
        if (contains[vertices[i]]) return false;
        contains[vertices[i]] = true;
    }
    return true;
}

int main(){
    // programming assignment 1 on second day
    // solution for six cities
    int n = 6;
    vector <vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    int min_path = 32000;
    for (int v2 = 0; v2 < n; v2++){
        for (int v3 = 0; v3 < n; v3++){
            for (int v4 = 0; v4 < n; v4++){
                for (int v5 = 0; v5 < n; v5 ++){
                    for (int v6 = 0; v6 < n; v6 ++){
                        vector<int> path;
                        path = {0, v2, v3, v4, v5, v6};
                        if (is__path_valid(path, n)){
                            min_path = min(min_path, get_path_cost(path, matrix, n));
                        }
                    }
                }
            }
        }
    }

    cout << min_path << endl;
}