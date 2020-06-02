#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>

enum class account_type
{
    SAVINGS,
    MONEY_MARKET,
    COMPANY_ACCOUNT
};

std::map<account_type,double> interest;
interest[account_type::SAVINGS]=2.5;
intrest.insert(std::make_pair(account_type::MONEY_MARKET,3.0))
std::pair <account_type,double> p1=std::make_pair(account_type::COMPANY_ACCOUNT,3.7);
interest.insert(p1);

std::string getaccounttype(const account_type &acc)
{
    switch(acc)
    {
        case 0:
         return "savings";
        case 1:
        return "money_market";
        case 2:
         return "company account";
        default:
         break;
    }
    return "";
}

account_type str_to_acc(const std::string &k)
{
    if(k=="savings")
    {
        return account_type::SAVINGS;
    }
    else if(k=="money_market")
    {
        return account_type::MONEY_MARKET;
    }
    else if(k=="company account")
    {
        return account_type::COMPANY_ACCOUNT;
    }
}

class account
{
    std::string accountid;
    std::string name;
    account_type type;
    double balance;
    public:
        account(std::string acc_id,std::string n,account_type t,double b):accountid(acc_id),name(n),type(t),balance(b) {}
        ~account() {}
        bool operator<(const account &acc)const {return this->balance<acc.balance;}
        std::string getname()const {return this->name;}
        std::string getaccountid()const {return this->accountid;}
        account getacctype()const {return this->type;}
        double getbalance()const {return this->balance;}
        void addinterest(double b)
        {
            this->balance+=((this->balance*b)/100.0);
        }
        friend std::ostream &operator<<(std::ostream &os,const account &acc);
};

std::ostream &operator<<(std::ostream &os,const account &acc)
{
    os<<acc.name<<","<<acc.accountid<<","<<getaccounttype(acc.type)<<","<<acc.balance;
    return os;
}

void show_by_type(std::vector <account> &acc)
{
    for(int i=0;i<acc.size();i++)
    {
        acc.at(i).addinterest(interest[acc.at(i).getacctype()]);
    }
    for(int k=0;k<2;k++)
    {
        for(int i=0;i<acc.size();i++)
        {
            if(acc.at(i).getacctype()==k)
            {
                std::cout<<acc.at(i)<<std::endl;
            }
        }
    }
}

void save_to_file(std::vector <account> &accs)
{
    sort(accs.begin(),accs.end());
    std::string fn;
    std::cout<<"Give filename:";
    std::cin>>fn;
    std::ofstream out;
    out.open(fn,std::ios::out);
    out<<"##########SORT ACCOUNTS BY BALANCE#######\n";
    for(auto &x:accs)
    {
        out<<x<<std::endl;
    }
    out.close();
}

int main()
{
    std::vector <account> accounts;
    std::ifstream fp;
    std::string filename;
    std::cout<<"Give filename:";
    std::cin>>filename;
    fp.open(filename,std::ios::in);
    std::string line,word;
    std::vector <std::string> data;
    while(line>>fp)
    {
        data.clear();
        std::stringstream ss(line);
        while(std::getline(ss,word,'-'))
        {
            data.push_back(word);
        }
        if(data.size()!=4) continue;
        if(line.at(0)=='#') continue;
        if(line.at(0)=='\n') continue;
        account_type gettype=str_to_acc(data[2]);
        account newaccount(data[0],data[1],gettype,stof(data[3]));
        accounts.push_back(newaccount);
    }

}