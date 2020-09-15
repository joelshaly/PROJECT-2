#include<iostream>
#include<vector>
#include"Admin.h"

class Librarian:public Admin
{
    private:
            
    public:
            
            std::string get_name() const
            {
                return name;
            }
            std::string get_password() const
            {
                return password;
            }

            void read()
            {
                std::cout<<"Enter librarian name " << std::endl;
                std::getline ( std::cin,name);

                std::cout <<"Enter password" << std::endl;
                std::getline (std::cin ,password);    
            }
            
};

class User: public Admin
{            
    public:
            
            std::string get_name() const
            {
                return name;
            }
            std::string get_password() const 
            {
                return password;
            }

            void read()
            {
                std::cout<<"Enter user name" << std::endl;
                std::getline (std::cin,name);

                std::cout <<"Enter password" << std::endl;
                std::getline (std::cin,password);    
            }
};

std::ostream& operator<<(std::ostream& os,const User& u)
{
    os << u.get_name() << "\n" << u.get_password() << std::endl ;
    return os ;
}

std::istream& operator>>(std::istream& is, User& u)
{
    std::string user_name;
    std::getline(is, user_name);
    u.set_name( user_name );
    
    std::string user_password;
    std::getline(is, user_password);
    u.set_password( user_password);
    return is;
}



std::ostream& operator<<(std::ostream& os,const Librarian& l)
{
    os << l.get_name() << "\n" << l.get_password() << std::endl ;
    return os ;
}

std::istream& operator>>(std::istream& is, Librarian& l)
{
    std::string librarian_name;
    std::getline(is, librarian_name);
    l.set_name( librarian_name );
    
    std::string librarian_password;
    std::getline(is, librarian_password);
    l.set_password( librarian_password);
    return is;
}

