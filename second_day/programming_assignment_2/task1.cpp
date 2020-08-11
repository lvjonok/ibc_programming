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

void print_path(vector<int> path){
    cout << "Path is ";
    for (int vertex : path){
        cout << vertex << " ";
    }
    cout << "0" << endl;
}

int solve_for_4(vector<vector<int>> matrix){
    int min_path_cost = 32000;
    vector <int> min_path({0, 0, 0, 0});
    for (int v2 = 0; v2 < 4; v2++){
        for (int v3 = 0; v3 < 4; v3++){
            for (int v4 = 0; v4 < 4; v4++){
                vector<int> path;
                path = {0, v2, v3, v4};
                if (is__path_valid(path, 4)){
                    int calc_path = get_path_cost(path, matrix, 4);
                    if (calc_path < min_path_cost){
                        min_path_cost = calc_path;
                        min_path = path;
                    }
                }
            }
        }
    }
    print_path(min_path);
    return min_path_cost;
}

int solve_for_5(vector<vector<int>> matrix){
    int n = 5;
    int min_path_cost = 32000;
    vector <int> min_path({0, 0, 0, 0, 0});
    for (int v2 = 0; v2 < n; v2++){
        for (int v3 = 0; v3 < n; v3++){
            for (int v4 = 0; v4 < n; v4++){
                for (int v5 = 0; v5 < n; v5 ++){
                    vector<int> path;
                    path = {0, v2, v3, v4, v5};
                    if (is__path_valid(path, n)){
                        int calc_path = get_path_cost(path, matrix, n);
                        if (calc_path < min_path_cost){
                            min_path_cost = calc_path;
                            min_path = path;
                        }
                    }
                }
            }
        }
    }
    print_path(min_path);
    return min_path_cost;
}

int solve_for_6(vector<vector<int>> matrix){
    int n = 6;
    int min_path_cost = 32000;
    vector <int> min_path({0, 0, 0, 0, 0, 0});
    for (int v2 = 0; v2 < n; v2++){
        for (int v3 = 0; v3 < n; v3++){
            for (int v4 = 0; v4 < n; v4++){
                for (int v5 = 0; v5 < n; v5 ++){
                    for (int v6 = 0; v6 < n; v6 ++){
                        vector<int> path;
                        path = {0, v2, v3, v4, v5, v6};
                        if (is__path_valid(path, n)){
                            int calc_path = get_path_cost(path, matrix, n);
                            if (calc_path < min_path_cost){
                                min_path_cost = calc_path;
                                min_path = path;
                            }
                        }
                    }
                }
            }
        }
    }
    print_path(min_path);
    return min_path_cost;
}

int main(){
    // programming assignment 2 on second day
    int n;
    cin >> n;

    if (n != 4 && n != 5 && n != 6){
        cout << "Inappropriate n" << endl;
        return 1;
    }

    vector <vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    switch (n)
    {
        case 4:
            cout << solve_for_4(matrix) << endl;
        break;
        case 5:
            cout << solve_for_5(matrix) << endl;
        break;
        case 6:
            cout << solve_for_6(matrix) << endl;
        break;
    }

    /*
        6
        0 9 14 2 6 11
        9 0 4 1 7 6
        14 4 0 2 10 9
        2 1 2 0 5 12
        6 7 10 5 0 3
        11 6 9 12 3 0
    */
}