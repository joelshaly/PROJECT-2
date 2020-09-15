#include<iostream>

class Admin
{
    public:
            void set_name( std::string name)
            {
                this-> name = name;
            }
            void set_password( std::string password)
            {
                this-> password = password;
            }
            

    protected:
            std::string name;
            std::string password;
};







