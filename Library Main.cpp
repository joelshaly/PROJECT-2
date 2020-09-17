#include<iostream>
#include<fstream>
#include<limits>
#include"Library.h"

int main()
{
    int choice;    
    Library library; 
    std::cout <<"**************************************************************************" << std::endl;
    std::cout<< "!!!!!!!!!!!!!!!!!!!!!!!Welcome to the library!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<std::endl;
    library.read_all_files();
    do
    {
        
        std::cout <<"**************************************************************************" << std::endl;
        std::cout<<"Enter\n1.User\n2.Librarian\n3.Create librarian\n4.Exit"<<std::endl;
        std::cin >> choice; 
        std::cin.clear();
        std::cin.ignore( std::numeric_limits < std::streamsize > ::max(),'\n'); 
        switch(choice)
        {
            case 1:
            {
                int index;
                User user;
                std::string user_name;
                std::string user_password;
                std::cout <<"**************************************************************************" << std::endl;
                std::cout <<"Enter Username"<<std::endl;
                std::getline(std::cin, user_name);
                std::cout <<"Enter Password" <<std::endl;
                std::getline(std::cin, user_password);
                index = library.user_check(user_name , user_password);
                if(index != 0)
                {
                    library.task_user(user_name);
                }
                else
                {
                    std::cout <<"The entered username or password is wrong."<< std::endl;
                }
                break;
                
            }
            case 2:
            {
                int index;
                User user;
                std::string librarian_name;
                std::string librarian_password;
                std::cout <<"**************************************************************************" << std::endl;
                std::cout <<"Enter Username"<<std::endl;
                std::getline(std::cin, librarian_name);
                std::cout <<"Enter Password" <<std::endl;
                std::getline(std::cin, librarian_password);
                index = library.librarian_check(librarian_name , librarian_password);
                if(index != 0)
                {
                    library.task_librarian();
                }
                else
                {
                    std::cout <<"The entered username or password is wrong."<< std::endl;
                }
                break;
            }
            case 3:
            {
                library.create_librarian();
                break;
            }
            case 4:
            {
                break;
            }
            default:
            {
                std::cout << " Enter valid input " << std::endl;
                break;
            }
        }
    } while ( choice != 4);

    library.write_all_files();
    return 0;
}