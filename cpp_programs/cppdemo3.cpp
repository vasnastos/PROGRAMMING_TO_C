//Άνοιγμα αρχείων με την χρήση της ροής αρχείων της c++
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int getsize(std::string filename)
{
    std::string line;
    std::ifstream is;
    is.open(filename,std::ios::in);
    int counter=0;
    while(std::getline(is,line))
    {
      if(line.at(0)=='#')
      {
          continue;
      }
      if(line.at(0)=='\n')
      {
          continue;
      }
       counter++;      
    }
    is.close();
    return counter;
}

void getdata(int *data,std::string fn)
{
    int i=0;
   std::string line;
   std::ifstream is;
   is.open(fn,std::ios::in);
   while(std::getline(is,line))
   {
      if(line.at(0)=='#')
      {
          continue;
      }
      if(line.at(0)=='\n')
      {
          continue;
      }
      data[i]=stoi(line);
      i++;
   }
   is.close();
}

void function(int *data,int size,int &max,int &min,double &avg)
{
    max=data[0];
    min=data[0];
    int sum=data[0];
    for(int i=1;i<size;i++)
    {
        if(data[i]>max) max=data[i];
        if(data[i]<min) min=data[i];
        sum+=data[i];
    }
    avg=(double)sum/size;
}

int main()
{
    std::string filename;
    std::cout<<"give filename:";
    std::cin>>filename;
    int size=getsize(filename);
    std::cout<<size<<std::endl;
    if(size==0)
    {
        std::cout<<"ERROR"<<std::endl;
        exit(EXIT_FAILURE);
    }
    int *data=new int[size];
    getdata(data,filename);
    int max;
    int min;
    double avg;
    function(data,size,max,min,avg);
    std::cout<<"Max:"<<max<<std::endl;
    std::cout<<"Min:"<<min<<std::endl;
    std::cout<<"Average:"<<avg<<std::endl;
    delete[] data;
}