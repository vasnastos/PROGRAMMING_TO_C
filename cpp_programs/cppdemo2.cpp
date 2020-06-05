//Δείκτες στην c++
#include <iostream>
#include <string>
int main()
{
    int x=2;
    double y=4;
    std::string key="vasilis";
    int *a=&x;
    double *key1=&y;
    (*a)++;
    y++;
    std::string *key2=new std::string(key);
    std::cout<<*key2<<"--"<<*key1<<"--"<<*a<<std::endl;
    std::cout<<key<<"--"<<y<<"--"<<x<<std::endl;
    delete a;
    delete key1;
    delete key2;
}