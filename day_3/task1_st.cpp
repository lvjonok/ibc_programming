#include <iostream>
#include <vector>
using namespace  std;

struct Figure{
    int x;
    int y;
};

bool is_intersects(Figure f1, Figure f2){
    if (f1.x == f2.x || f1.y == f2.y) return true;
    if (abs(f1.x - f2.x) == abs(f1.y - f2.y)) return true;
    return false;
}

int main(){
    struct Figure table[8];
    for (int i = 0; i < 8; i++){
        cin >> table[i].x >> table[i].y;
    }
    for (int f = 0; f < 8; f++){
        for (int s = f+1; s < 8; s++){
            if (is_intersects(table[f], table[s])){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}