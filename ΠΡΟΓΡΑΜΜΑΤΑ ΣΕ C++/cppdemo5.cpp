#include <iostream>
class product 
{
    private:
     std::string name;
     std::string id;
     double price;
    public:
      product(std::string n,std::string id,double pr):name(n),id(id),price(pr) {}
      ~product() {}

      void set_name(std::string n) {this->name=n;}
      std::string get_name()const {return this->name;}
      void set_id(std::string i) {this->id=i;}
      std::string get_id()const {return this->id;}
      void set_price(double pr) {this->price=pr;}
      double get_price()const {return this->price;}
      product &operator=(const product &p)
      {
          this->name=p.name;
          this->id=p.id;
          this->price=p.price;
          return *this;
      } 
      bool operator<(const product &p)const {return this->price<p.price;}
      bool is_fragile()
      {
          if(this->id.at(0)=='#' && this->id.at(1)=='#')
          {
              this->price+=10.0;
              return true;
          }
          return false;
      }
      friend std::ostream &operator<<(std::ostream &os,const product &p)
      {
          os<<p.id<<"---"<<p.name<<"---"<<p.price;
          return os;
      }
};

int main()
{
    product p1("TV","##uit7896",450.34);
    product *p2=new product("Phone","347hgd#",321.00);
    product p3=p1;
    p3.set_name("Headphone");
    p3.set_price(120.56);
    std::cout<<p1.get_id()<<"--fragile:"<<p1.is_fragile()<<std::endl;
    std::cout<<p2->get_id()<<"is fragile:"<<p2->is_fragile()<<std::endl;
    std::cout<<p3.get_id()<<"is fragice:"<<p3.is_fragile()<<std::endl;
    delete p2;
}