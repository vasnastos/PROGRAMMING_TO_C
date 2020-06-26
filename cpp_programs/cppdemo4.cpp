#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

struct student
{
    int id;
    std::string name;
    std::string lessonname;
    double grades[2];
};

int getsize(std::string filename)
{
    std::string line;
    int counter=0;
    std::ifstream is;
    is.open(filename,std::ios::in);
    while(std::getline(is,line))
    {
        if(line.size()==0) continue;
        if(line.at(0)=='#')
        {
            continue;
        }
        counter++;
    }
    is.close();
    return counter;
}

void readdata(student *students,std::string filename)
{
    std::string word;
    std::vector <std::string> data;
    std::string line;
    std::ifstream is;
    int i=0;
    is.open(filename,std::ios::in);
    while(std::getline(is,line))
    {
        data.clear();
        if(line.size()==0) continue;
        if(line.at(0)=='#')
        {
            continue;
        }
        std::stringstream ss(line);
        while(std::getline(ss,word,';'))
        {
            data.push_back(word);
        }
        if(data.size()!=5)
        {
            continue;
        }
        students[i].id=stoi(data[0]);
        students[i].name=data[1];
        students[i].lessonname=data[2];
        students[i].grades[0]=stof(data[3]);
        students[i].grades[1]=stof(data[4]);
        i++;
    }
    is.close();
}

int cntpassed(student *students,int size)
{
    int counter=0;
    for(int i=0;i<size;i++)
    {
        if(students[i].grades[0]>=5.0 && students[i].grades[1]>=5.0)
        {
            std::cout<<"ID:"<<students[i].id<<"\t"<<students[i].name<<"\t"<<students[i].lessonname<<std::endl;
            counter++;
        }
    }
    return counter;
}

int main()
{
    std::string fn;
    std::cout<<"Give name:";
    std::cin>>fn;
    int size=getsize(fn);
    if(size==0)
    {
        std::cout<<"ERROR"<<std::endl;
        exit(EXIT_FAILURE);
    }
    student *students=new student[size];
    readdata(students,fn);
    std::cout<<"PASSED DETAILS:::"<<std::endl;
    int cnt=cntpassed(students,size);
    std::cout<<cnt<<" passed details"<<std::endl;
    delete[] students;   
}