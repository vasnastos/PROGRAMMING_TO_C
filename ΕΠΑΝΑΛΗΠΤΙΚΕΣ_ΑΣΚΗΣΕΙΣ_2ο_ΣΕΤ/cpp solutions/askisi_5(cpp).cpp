#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

class employee
{
    std::string name;
    std::string lastname;
    int age;
    double sales[3];
    public:
    employee() {}
     employee(std::string n,std::string ln,int a,double s1,double s2,double s3):name(n),lastname(ln),age(a)
     {
         sales[0]=s1;
         sales[1]=s2;
         sales[2]=s3; 
     }
     ~employee() {}
     double find_average()
     {
         double avg=0.0;
         for(int i=0;i<sizeof(this->sales)/sizeof(double);i++)
         {
             avg+=sales[i];
         }
         avg/=3;
         return avg;
     }
     double getsale(int j)
     {
         return this->sales[j];
     }
     friend std::ostream &operator<<(std::ostream &os,const employee &e)
     {
         os<<e.name<<"-"<<e.lastname<<"-"<<e.age;
         return os;
     }
     void printaverage()
     {
         std::cout<<"Average:"<<this->find_average()<<std::endl;
     }    
};

void readfromfile(std::vector <employee> &emps)
{
    std::vector <std::string> data;
    std::string word,line;
    std::ifstream is;
    is.open("employees.txt",std::ios::in);
    while(is>>line)
    {
        data.clear();
        if(line.at(line.size()-1)=='\n') line.at(line.size()-1)='\0';
        std::string split;
        std::stringstream ss(line);
        while(std::getline(ss,split,'-'))
        data.push_back(split);
        if(data.size()!=6)
        {
            continue;
        }
        employee emp(data[0],data[1],stoi(data[2]),stof(data[3]),stof(data[4]),stof(data[5]));
        emps.push_back(emp);
    }
    is.close();
}

int main()
{
    std::vector <employee> employees;
    employee maxperyear;
    readfromfile(employees);
    for(auto x=employees.begin();x!=employees.end();x++)
    {
        x->printaverage();
    }
    int i;
    for(i=0;i<3;i++)
    {
      maxperyear=*std::max_element(employees.begin(),employees.end(),[=](employee &s1,employee &s2) {return s1.getsale(i)>s2.getsale(i);});
      std::cout<<"year_"<<i<<":"<<maxperyear<<std::endl;
    }
}