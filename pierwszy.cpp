#include <iostream>

using namespace std;

int dodaj(int a,int b);

int main()
{
    cout << dodaj(-2,2) << endl;

}

int dodaj(int a,int b){
    return a+b;
}