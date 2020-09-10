#include <iostream>
using namespace std;

int main() 
{
    int N;
    cin >> N; 
    for(int i =0;i<N;i++){
    long long int a,b,x,y,n;
    cin >> a >> b >> x >> y >> n;
    while(n!=0){
        if(a>b){
            if(b>y){
                b--;
                n--;
            }
            else if (a>x){
                a--;
                n--;
            }
            else {
                break;
            }

        }
        else if(a<b){
            if(a>x){
                a--;
                n--;
            }
            else if (b>y){
                b--;
                n--;
            }
            else {
                break;
            }

        }
        else if(a==x && b==y){
            break;
        }
    }
    cout <<a*b<<"\n";
    }
    return 0;
}