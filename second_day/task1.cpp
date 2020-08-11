#include <iostream>
#include <map>
using namespace std;

int get_path_cost(int vertices[4], int paths[4][4]){
    int path_cost = 0;
    for (int i = 0; i < 4; i++){
        path_cost += paths[vertices[i]][vertices[(i + 1) % 4]];
    }
    return path_cost;
}

bool is__path_valid(int vertices[4]){
    map<int, bool> contains;
    for (int i = 0; i < 4; i++){
        if (contains[vertices[i]]) return false;
        contains[vertices[i]] = true;
    }
    return true;
}

int main(){
    int matrix[4][4] = {
        {0, 10, 8, 6},
        {10, 0, 3, 7},
        {8, 3, 0, 1},
        {6, 7, 1, 0}
    };

    int min_path = 32000;
    for (int v2 = 0; v2 < 4; v2++){
        for (int v3 = 0; v3 < 4; v3++){
            for (int v4 = 0; v4 < 4; v4++){
                int path[4] = {0, v2, v3, v4};
                if (is__path_valid(path)){
                    min_path = min(min_path, get_path_cost(path, matrix));
                }
            }
        }
    }

    cout << min_path << endl;

    return 0;
}