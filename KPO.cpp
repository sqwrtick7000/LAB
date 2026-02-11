#include <iostream>
#include <cmath>
using namespace std;

int main(){
float m,n,a;
cin>>n>>m>>a;
float answer = ceil(m/a)*ceil(n/a);
cout << answer<<endl;
return 0;
}