#include <iostream>
using namespace std;

int main() 
{
    int N;
    cin >> N; 
    for(int i =0;i<N;i++){
    long long int a,b,x,y,n;
    cin >> a >> b >> y >> x >> n;
    while(n!=0){
    //     if(a>b && b>x){
    //         if (n+x >= b){
    //             b=x;
    //             n=n+x-b;
    //         }
    //         else{
    //             b=b-n ;
    //             n=0;
    //         }
    //     }
    //     else if(a<b && a>y){
    //         if(n+y >= a){
    //             a=y;
    //             n=n+y-a;

    //         }
    //         else{
    //             a=a-n;
    //             n=0;
    //         }
    //     }
    //     else if(b>x){
    //         if(n+y >= a){
    //             a=y;
    //             n=n+y-a;

    //         }
    //         else{
    //             a=a-n;
    //             n=0;
    //         }
    //     }
    //     else if(a>y){
    //         if(n+y >= a){
    //             a=y;
    //             n=n+y-a;

    //         }
    //         else{
    //             a=a-n;
    //             n=0;
    //         }
    //     }
    //     else {
    //         if(x>y){
    //          if(n+y >= a){
    //             a=y;
    //             n=n+y-a;

    //         }
    //         else{
    //             a=a-n;
    //             n=0;
    //         }   
    //         }
    //         else
    //         {
    //             if (n+x >= b){
    //             b=x;
    //             n=n+x-b;
    //         }
    //         else{
    //             b=b-n ;
    //             n=0;
    //         }   
    //         }
            
    //     }
    // }
    cout<<a*b<<"\n";
    }
    
    return 0;
}