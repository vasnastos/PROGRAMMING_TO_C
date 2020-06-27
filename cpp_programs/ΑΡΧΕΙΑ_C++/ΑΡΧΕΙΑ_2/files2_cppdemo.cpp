#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

int execute_file_function()
{
    std::cout<<"############################"<<std::endl;
    std::cout<<"Numbers List::"<<std::endl;
    std::string line,word;
    std::ifstream is;
    int i=0;
    int counter=0;
    double number;
    is.open("number.txt",std::ios::in);
    while(std::getline(is,line))
    {
        if(line.size()==0) continue;
        if(line.at(i)=='#') continue;

        number=std::stof(line);
        std::cout<<"Number_"<<i+1<<":"<<number<<std::endl;
        if(number>1200.0)
        {
            counter++;
        }
    }
    std::cout<<"############################"<<std::endl;
    is.close();
    return counter;
}

void loading()
{
    std::cout<<"Data loading...";
    for(int i=0;i<3;i++)
    {
        std::cout<<"...";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::cout<<std::endl;
    std::cout<<"Data loading complete!!!!"<<std::endl;
}

int main()
{
    std::cout<<"FILE WITH SALARIES WITH RANDOM SIZE"<<std::endl;
    loading();
    int counter=execute_file_function();
    std::cout<<std::endl;
    std::cout<<"######RESULT###############"<<std::endl;
    std::cout<<counter<<" salaries are over 1200.00$"<<std::endl;
    std::cout<<"###########################"<<std::endl;
}