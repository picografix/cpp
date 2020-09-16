#include <iostream>
using namespace std;
int main()
{
    int my_int = 10;
    int* my_int_ptr = &my_int;// pointer to my_int
    int* new_ptr = 0; // null pointer
    cout<<"Testing "<<my_int<<" ptr is "<<my_int_ptr<< endl;
    cout<<"This is null pointer "<<new_ptr<<endl;
}