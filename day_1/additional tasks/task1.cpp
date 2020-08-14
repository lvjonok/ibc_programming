#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    float a1, a2, a3;
    a1 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    a2 = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
    a3 = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));

    if (a1 + a2 > a3 && a2 + a3 > a1 && a1 + a3 > a2){
        cout << "it exists";
    }
    else {
        cout << "nope";
    }
}