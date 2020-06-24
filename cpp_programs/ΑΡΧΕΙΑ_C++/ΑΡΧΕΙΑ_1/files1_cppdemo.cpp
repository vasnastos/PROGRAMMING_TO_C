//|\ | T ||  /\ |   DATE:2019-2020          AUTHOR:NASTOS VASILEIOS
//|/ | | \/  \/ |   PROGRAM:files demo_1       
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <string>
#include <chrono>
#include <sstream>

std::pair <int,int> execute_file_function()
{
    std::cout<<"###############################"<<std::endl;
    std::cout<<"Number list::"<<std::endl;
    std::ifstream is;
    std::string line,word;
    int pos,number;
    std::vector <std::string> data;
    int i=0;
    int max;
    is.open("numbers.txt",std::ios::in);
    while(std::getline(is,line))
    {
        if(line.size()==0)
        {
            continue;
        }
        if(line.at(0)=='#')
        {
            continue;
        }
        std::stringstream ss(line);
        data.clear();
        while(std::getline(ss,word,':'))
        {
            data.push_back(word);
        }
        if(data.size()!=2) continue;
        if(i==0)
        {
            max=std::stoi(data[1]);
            pos=0;
        }
        else
        {
            number=std::stoi(data[1]);
            if(number>max)
            {
                max=number;
                pos=i;
            }
        }
        std::cout<<"Element_"<<i<<":"<<number<<std::endl;
        i++;       
    }
    is.close();
    std::cout<<"###############################"<<std::endl;
    std::pair <int,int> p1=std::make_pair(max,pos);
    return p1;
}

void loading()
{
    std::cout<<"Data loading..";
    for(int i=0;i<6;i++)
    {
      std::cout<<"...";
      std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    std::cout<<std::endl;
    std::cout<<"Data loading complete!!!!"<<std::endl;
}

int main()
{
    std::cout<<"numbers.txt file use in order to find the max element from a file with unknown size"<<std::endl;
    loading();
    std::pair <int,int> max=execute_file_function();
    std::cout<<std::endl;
    std::cout<<"#######RESULT##############"<<std::endl;
    std::cout<<"Max element is "<<max.first<<" and found in position "<<max.second<<std::endl;
    std::cout<<"###########################"<<std::endl;
}