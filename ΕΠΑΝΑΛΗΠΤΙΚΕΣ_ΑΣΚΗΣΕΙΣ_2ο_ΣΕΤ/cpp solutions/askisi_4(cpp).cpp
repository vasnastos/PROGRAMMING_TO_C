#include <iostream>
#include <string>
#include <fstream>

int getsumofintegers(const std::string &key)
{
    std::string num="";
    int accumulate=0;
    for(int i=0;i<key.size();i++)
    {
      if(key.at(i)>='0' && key.at(i)<='9')
      {
          num+=key.at(i);
      }
      else
      {
         continue;
      }
      if(key[i+1]>='0' && key[i+1]<='9' && i<key.size()-1)
      {
          continue;
      }
      else
      {
          accumulate+=stoi(num);
          num="";
      }
    }
    return accumulate;
}

void savesumtofile(std::string word,int s)
{
    std::ofstream out;
    out.open("Numbers_sum.txt",std::ios::app);
    out<<word<<"\t"<<s<<std::endl;
    out.close();
}

int main()
{
    std::string word;
    std::ofstream out;
    int sum;
    while(true)
    {
        std::cout<<"Give word:";
        std::cin>>word;
        if(word=="quit")
        {
            break;
        }
       sum=getsumofintegers(word);
       savesumtofile(word,sum);
    }
}