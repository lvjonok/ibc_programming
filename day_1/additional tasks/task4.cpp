#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

struct point
{
    int x;
    int y;
} mp, mp1;


float getK(point p1, point p2){
    if (p1.x == p2.x) return 0;
    return (p1.y - p2.y) / (p1.x - p2.x);
}

float getB(point p1, point p2){
    return p1.y - getK(p1, p2) * p1.x;
}

bool is_intersects(point p1, point p2, point p3, point p4){
    float k1 = getK(p1, p2);
    float k2 = getK(p3, p4);
    float b1 = getB(p1, p2);
    float b2 = getB(p3, p4);

    float x_i = (b1 - b2) / (k2 - k1);
    float y_i = k1 * x_i + b1;
    if (x_i < p1.x) return false;
    if (y_i != p1.y || (y_i > max(p3.y, p4.y) || y_i < min(p3.y, p4.y))) return false;

    return true;
}

int main(){
    struct point raw_points[4];
    struct point points[4]; // 0 - bottom left, 1 - up left, 2 - right up, 3 - right bottom
    vector <int> line_sums(4);


    for (int i = 0; i < 4; i++){
        cin >> raw_points[i].x >> raw_points[i].y;
        line_sums[i] = raw_points[i].x + raw_points[i].y;
    }
    cin >> mp.x >> mp.y;
    mp1.x = mp.x;
    mp1.y = 32000;

    sort(line_sums.begin(), line_sums.end());

    int m = 1;
    int min_x = raw_points[0].x;
    int max_x = raw_points[0].x;

    for (int i = 0; i < 4; i++){
        if (line_sums[0] == raw_points[i].x + raw_points[i].y){
            points[0] = raw_points[i];
        } else if (line_sums[3] == raw_points[i].x + raw_points[i].y){
            points[2] = raw_points[i];
        } else {
            points[m] = raw_points[i];
            m+=2;
        }
        min_x = min(min_x, raw_points[i].x);
        max_x = max(max_x, raw_points[i].x);
    }

    int answer = 0;
    for (int i = 0; i < 4; i++){
        answer += is_intersects(mp, mp1, points[i], points[(i + 1) % 4]);
    }
    
    if (answer % 2 == 1) cout << "inside";
    else cout << "outside";

    return 0;
}