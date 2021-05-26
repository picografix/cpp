#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main(){
    bitset<6> set1(32);
    // cout<< set1.set() << "\n";
    cout<< set1.set(5,0) <<"\n"; // set a particular value to specified value
    cout<< set1.set(5)<<"\n"; // set a particular value to 1
    cout<< set1.reset()<<"\n"; // set all val to 0 
    cout<< set1.flip() <<"\n"; // same as negation
    cout<< set1.set(5,0) <<"\n"; // set a particular value to specified value
    cout<< set1.count() << "\n"; // count the no of ones
    cout<< set1.size()<<"\n"; // returns the size
    //checking a bit
    for(size_t i=0; i < set1.size();++i){
        cout<<set1.test(i)<<' ';
    }
    cout<< set1.any() <<"\n"; // checks if any bit is 1
    cout<< set1.none() << "\n"; //check if no bit is 1
    cout<< set1.all() <<"\n"; //check of all the bits are 1
    return 0;
}