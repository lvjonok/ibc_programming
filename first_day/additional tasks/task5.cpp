#include<iostream>
#include<string>
using namespace std;

string getTens(int ten){
    switch (ten)
    {
        case 0:
            return "";
        break;
        case 1:
            return "X";
        break;
        case 2:
            return "XX";
        break;
        case 3:
            return "XXX";
        break;
        case 4:
            return "XL";
        break;
        case 5:
            return "L";
        break;
        case 6:
            return "LX";
        break;
        case 7:
            return "LXX";
        break;
        case 8:
            return "LXXX";
        break;
        case 9:
            return "XC";
        break;
    }
}

string getOnes(int ones){
    switch (ones)
    {
        case 0:
            return "";
        break;
        case 1:
            return "I";
        break;
        case 2:
            return "II";
        break;
        case 3:
            return "III";
        break;
        case 4:
            return "IV";
        break;
        case 5:
            return "V";
        break;
        case 6:
            return "VI";
        break;
        case 7:
            return "VII";
        break;
        case 8:
            return "VIII";
        break;
        case 9:
            return "IX";
        break;
    }
}

int main(){
    int num;
    cin >> num;
    if (num == 100){
        cout << "C";
    } else {
        cout << num << "-" << getTens(num/10) << getOnes(num % 10) << endl;
    }
    return 0;
}