#include "sqlite3.h"
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

void create_database()
{
    sqlite3 *db;
    std::string sql;
    char *errmsg=nullptr;
    int result=sqlite3_open("prointa.db",&db);
    if(result!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    sql="CREATE TABLE IF NOT EXISTS PRODUCT(ID INTEGER PRIMARY KEY AUTOINCREMENT,NAME VARCHAR(30),CATEGORY VARCHAR(30),PRICE DOUBLE);";
    result=sqlite3_exec(db,sql.c_str(),0,0,&errmsg);
    if(result!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    else
    {
        std::cout<<"Hello world from database!!!"<<std::endl;
    }
    sqlite3_close(db);
}

void insert_in_database(std::string n,std::string cat,double pr)
{
    sqlite3 *db=nullptr;
    sqlite3_stmt *qr=nullptr;
    std::string sql="INSERT INTO PRODUCT(NAME,CATEGORY,PRICE) VALUES(?,?,?);";
    int res=sqlite3_open("prointa.db",&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    res=sqlite3_prepare_v2(db,sql.c_str(),-1,&qr,nullptr);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    sqlite3_bind_text(qr,1,n.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(qr,2,cat.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_double(qr,3,pr);
    sqlite3_step(qr);
    std::cout<<"insertion complete"<<std::endl;
    sqlite3_close(db);
}

std::vector <std::tuple <std::string,std::string,double>> getelemnts()
{
    sqlite3 *db;
    sqlite3_stmt *q=nullptr;
    std::string sql;
    std::vector <std::tuple <std::string,std::string,double>> vec;
    int res=sqlite3_open("prointa.db",&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return vec;
    }
    sql="SELECT NAME,CATEGORY,PRICE FROM PRODUCT;";  
    res=sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return vec;
    }
    while(sqlite3_step(q)==SQLITE_ROW)
    {
      std::string name=(const char *)sqlite3_column_text(q,0);
      std::string category=(const char *)sqlite3_column_text(q,1);
      double price=sqlite3_column_double(q,2);
      std::tuple <std::string,std::string,double> nel=std::make_tuple(name,category,price);
      vec.push_back(nel);
    } 
    sqlite3_close(db);
    return vec;
}

void drivercode()
{
    create_database();
    int choice;
    std::string name,cat;
    double price;
    while(1)
    {
        std::cout<<"New element(0/cancel,1/continue):";
        std::cin>>choice;
        if(choice==0)
        {
            break;
        }
        else if(choice==1)
        {
            std::cout<<"Give name:";
            std::cin>>name;
            std::cout<<"Give category:";
            std::cin>>cat;
            std::cout<<"Give price:";
            std::cin>>price;
            insert_in_database(name,cat,price);
            std::cout<<"New product insert in to database!!"<<std::endl;
        }
        else
        {
            std::cout<<"Invalid choice please try again!!"<<std::endl;
        }    
    }
    std::vector <std::tuple<std::string,std::string,double>> data=getelemnts();
    if(data.size()==0)
    {
        std::cout<<"No element has been loaded to database!!"<<std::endl;
        return;
    }
    std::cout<<"PRODUCTS LIST"<<std::endl;
    for(auto &x:data)
    {
        std::cout<<std::get<0>(x)<<"---"<<std::get<1>(x)<<"---"<<std::get<2>(x)<<std::endl;
    }
}

int main()
{
    drivercode();
}