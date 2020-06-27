#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <vector>

//---------------------------------------------------------------------
void loading()
{
    std::cout<<"Data loading..";
    for(int i=0;i<3;i++)
    {
        std::cout<<"....";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::cout<<std::endl;
    std::cout<<"DATA LOADING COMPLETE!!!!"<<std::endl;
    std::cout<<"Fetching the results...";
    for(int i=0;i<2;i++)
    {
        std::cout<<"...";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::cout<<std::endl;
}

//--------------------------------------------------------------------

void execute_file_loading(std::vector <double> &temps)
{
    std::ifstream is;
    std::string line;
    is.open("Temps.txt",std::ios::in);
    while(std::getline(is,line))
    {
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;

        double temperature=std::stod(line);
        temps.push_back(temperature);
    }
    is.close();
}

int main()
{
    double lower,upper;
    std::cout<<"#######DATA INSERTION########"<<std::endl;
    std::cout<<"Give lower temp boundary:";
    std::cin>>lower;
    std::cout<<"Give upper temp boundary:";
    std::cin>>upper;
    std::cout<<"#############################"<<std::endl;
    std::vector <double> tms;
    execute_file_loading(tms);
    loading();
    std::cout<<std::endl;
    std::cout<<"#########ELEMENTS LIST#########"<<std::endl;
    int count=std::count_if(tms.begin(),tms.end(),[lower,upper](const double &t) {return t>=lower && t<=upper;});
    for(std::vector <double>::iterator itr=tms.begin();itr!=tms.end();itr++)
    {
        std::cout<<"ELEMENT_"<<(itr-tms.begin())+1<<":"<<*itr<<std::endl;
    }
    std::cout<<"###############################"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"######RESULT###################"<<std::endl;
    std::cout<<"Temperatures between "<<lower<<" and "<<upper<<" are:"<<count<<std::endl;

}