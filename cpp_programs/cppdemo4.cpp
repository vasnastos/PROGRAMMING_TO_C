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

void readdata(student *students,std::string filename)
{
    std::string word;
    std::vector <std::string> data;
    std::string line;
    std::ifstream is;
    is.open(filename,std::ios::in);
    while(std::getline(is,line))
    {
        data.clear();
        if(line.at(0)=='#')
        {
            continue;
        }
        if(line.at(0)=='\n')
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
        student st;
        st.id=stoi(data.at(0));
        st.name=data.at(1);
        st.lessonname=data.at(2);
        st.grades[0]=stoi(data.at(3));
        st.grades[1]=stoi(data.at(4));
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