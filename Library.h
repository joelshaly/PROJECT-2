#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<limits>
#include "Book.h"
#include "Borrow.h"
#include "Librarian.h"

class Library
{
    private:        
            std::vector< Book > book_vector;
            std::vector< User > user_vector;
            std::vector< Borrow > borrow_vector;
            std::vector< Librarian > librarian_vector;
            std::map< std::string, std::string > user;
            std::map< std::string, std::string > librarian;
    public:
           
            void write_to_map_user()
            {
                for(int i = 0; i < user_vector.size(); i++)
                {
                    user.insert(std::make_pair (user_vector[i].get_name(),user_vector[i].get_password()));        
                }
            }

            void write_to_map_librarian()
            {
                for(int i = 0; i < librarian_vector.size(); i++)
                {
                    librarian.insert(std::make_pair (librarian_vector[i].get_name(),librarian_vector[i].get_password()));        
                }
            }
           
            int user_check(std::string name , std::string password)
            {   
                int flag = 0;
                std::map< std::string, std::string>::iterator it;
                for(it = user.begin(); it != user.end(); it++)
                {
                    if( it == user.find(name) )
                    {
                        if( it->second == password)
                        {
                            flag++;
                            break;
                        }
                    }
                }
                return flag;   
            }

            int librarian_check(std::string name , std::string password)
            {   
                int flag = 0;
                std::map< std::string, std::string>::iterator it;
                for(it = librarian.begin(); it != librarian.end(); it++)
                {
                    if( it == librarian.find(name) )
                    {
                        if( it->second == password)
                        {
                            flag++;
                            break;
                        }
                    }
                }
                return flag;   
            }
            
            bool add_book()
            {
               Book book;
               book.read();
               book_vector.push_back(book);
               return true;
            }

            bool create_user()
            {
                User user;
                user.read();
                user_vector.push_back(user);
                return true;
            }

            bool create_librarian()
            {
                Librarian librarian;
                librarian.read();
                librarian_vector.push_back(librarian);
                return true;
            }

            int availability( std::string book_slno)
            {
                int flag = 3;
                for( int i = 0; i < borrow_vector.size() ; i++)
                {
                    if( borrow_vector[i].get_book_slno() == book_slno)
                    {
                        flag = 3;
                        break;
                    }
                    else
                    {
                        flag ++;
                    }                    
                }
                return flag;
            }

            void print_available_books()
            {
                int index = 0;
                std::string slno;
                for(int i = 0; i < book_vector.size(); ++i)
                { 
                    slno = book_vector[i].get_slno();
                    if(availability(slno) == 3)
                    {
                        index++;
                    }
                    else
                    {                                    
                        book_vector[i].print();
                    }
                }
                if(index == book_vector.size())
                {
                    std::cout<<"No books are available" <<std::endl;
                }
            }
            bool borrow_book()
            {
                Library library;
                Borrow borrow;
                std::string book_name;
                std::string user_name;
                std::cout <<"**************************************************************************" << std::endl;
                std::cout<<"Enter username" <<std::endl;
                std::getline(std::cin,user_name);
                std::string book_slno;
                int index , a;
                print_available_books();
                std::cout <<"Enter serial number of the required book." << std::endl;
                std::getline(std::cin , book_slno);
                for( int i = 0; i < book_vector.size(); i++)
                {
                    if(book_vector[i].get_slno() == book_slno)
                    {
                        a++;
                        book_name = book_vector[i].get_book();
                        if( availability( book_slno) != 3)
                        {
                            std::cout<<"The book is borrowed" << std::endl;
                            borrow.read( book_name , book_slno , user_name);
                            borrow_vector.push_back(borrow);
                            index = 0;
                            break;
                        }
                        else
                        {
                            std::cout << "The book is not available" << std::endl; 
                            index++;
                            break;
                        }
                    }
                }
                if( a == 0)
                {
                    std::cout<< "Given serial number is wrong" << std::endl;
                }
                if( index == 0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
                
            }
            bool borrower_details()
            {
                int index = 0;
                std::string user_name;
                std::cout <<"**************************************************************************" << std::endl;
                std::cout<<"Enter username" << std::endl;
                std::getline(std::cin,user_name);
                if(borrow_vector.size() > 0)
                {
                    for(int i=0; i < borrow_vector.size(); i++)
                    {
                        if(borrow_vector[i].get_borrower_name() == user_name)
                        {
                            borrow_vector[i].print();
                            index++;
                        }
                    }
                }    
                if(index == 0)
                {
                    std::cout << "No book has been borrowed" << std::endl;
                    return false;
                }
                else
                {
                    return true;
                }
            }

            void return_book()
            {
                std::string user_name, sl_no;
                std::cout <<"**************************************************************************" << std::endl;
                std::cout<< "Enter user name" << std::endl;
                std::getline( std::cin ,user_name);               
                std::cout<< "Enter serial no of book"<< std::endl;
                std::getline(std::cin , sl_no);
                for(auto it  = borrow_vector.begin() ; it != borrow_vector.end(); ++it)
                {
                    if(it->get_borrower_name() == user_name && it->get_book_slno() == sl_no)
                    {
                        borrow_vector.erase(it);
                        std::cout <<"The book has been returned" << std::endl;
                        break;
                    }
                    else
                    {
                        continue;
                    }     
                }
            }

            bool change_due_date()
            {
                std::string user_name ,slno;
                int index = 0;
                double new_date;
                std::cout <<"**************************************************************************" << std::endl;
                std::cout<<"Enter user "<<std::endl;
                std::getline(std::cin , user_name);
                std::cout << "Enter sl no. of book" <<std::endl;
                std::getline(std::cin, slno);

                for(int i = 0; i < borrow_vector.size(); i++)
                {
                    if(borrow_vector[i].get_borrower_name() == user_name)
                    {
                        for( int j = 0; j < borrow_vector.size(); j++)
                        {
                            if(borrow_vector[j].get_book_slno() == slno)
                            {
                                new_date = borrow_vector[i].get_due_date() + 604800; 
                                borrow_vector[i].set_due_date(new_date);
                                index++;
                            }
                        }
                    }
                }
                if( index == 0)
                {
                    std::cout<< "No book of given slno as been borrowed"<< std::endl;
                    return false;
                }
                else
                {
                    std::cout << "The due date has been extended " << std::endl;
                    return true;
                }
                
            }
            
            void read_from_user_file(std::ifstream& is)
            {
                User user;
                while(is >> user)
                {
                    user_vector.push_back(user);
                }
            }

            void write_to_user_file(std::ofstream& os)
            {
                int index = 0;
                while(index < user_vector.size())
                    {
                        os << user_vector[index];
                        index++ ;
                    }
            }

            void read_from_librarian_file(std::ifstream& is)
            {
                Librarian librarian;
                while(is >> librarian)
                {
                    librarian_vector.push_back(librarian);
                }
            }

            void write_to_librarian_file(std::ofstream& os)
            {
                int index = 0;
                while(index < librarian_vector.size())
                    {
                        os << librarian_vector[index];
                        index++ ;
                    }
            }

            void read_from_borrowed_file(std::ifstream& is)
            {
                Borrow borrow;
                while(is >> borrow)
                {
                    borrow_vector.push_back(borrow);
                }

            }

            void write_to_borrow_file(std::ofstream& os)
            {
                int index = 0;
                while(index < borrow_vector.size())
                    {
                        os << borrow_vector[index];
                        index++ ;
                    }
            }

            void read_from_book_file(std::ifstream& is)
            {
                Book book;
                while(is >> book)
                {
                    book_vector.push_back(book);
                }

            }

            void write_to_book_file(std::ofstream& os)
            {
                int index = 0;
                while(index < book_vector.size())
                    {
                        os << book_vector[index];
                        index++ ;
                    }
            }
            
            void read_all_files()
            {
                std::ifstream book_in_file("Book.txt", std::ios::in);
                read_from_book_file(book_in_file);
                book_in_file.close();

                std::ifstream borrow_in_file("Borrow.txt", std::ios::in);
                read_from_borrowed_file(borrow_in_file);
                borrow_in_file.close();

                std::ifstream librarian_in_file("Librarian.txt", std::ios::in);
                read_from_librarian_file(librarian_in_file);
                librarian_in_file.close();

                std::ifstream user_in_file("User.txt", std::ios::in);
                read_from_user_file(user_in_file);
                user_in_file.close();

                write_to_map_user();
                write_to_map_librarian();
            }

            void write_all_files()
            {
                std::ofstream user_out_file("User.txt", std::ios::out);
                write_to_user_file(user_out_file); 
                user_out_file.close();

                std::ofstream librarian_out_file("Librarian.txt", std::ios::out);
                write_to_librarian_file(librarian_out_file); 
                librarian_out_file.close();

                std::ofstream borrow_out_file("Borrow.txt", std::ios::out);
                write_to_borrow_file(borrow_out_file); 
                borrow_out_file.close();

                std::ofstream book_out_file("Book.txt", std::ios::out);
                write_to_book_file(book_out_file); 
                book_out_file.close();
            }
            void task_user( std::string user_name)
            {
                Library library;
                int choice;
                do
                {
                    std::cout <<"**************************************************************************" << std::endl;
                    std::cout << "Enter required task :\n1.See available book \n2.Borrowed Book details\n3.Logout" << std::endl;
                    std::cin >> choice;
                    std::cin.clear();
                    std::cin.ignore( std::numeric_limits < std::streamsize > ::max(),'\n'); 
                    switch(choice)
                    {
                        case 1:
                        {
                            print_available_books();
                            break;
                        }
                        case 2:
                        {
                            int index = 0;
                            for(int i = 0; i < borrow_vector.size(); ++i)
                                {
                                    if( borrow_vector[i].get_borrower_name() == user_name)
                                    {
                                        borrow_vector[i].print();
                                        index++;
                                    }
                                }
                            if(index == 0)
                            {
                                std::cout <<"No book has been borrowed by this user"<< std::endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            break;
                        }
                        default:
                        {
                            std::cout << " Enter valid input " << std::endl;
                            break;
                        }
                    }
                
                } while ( choice != 3);

            }

            void task_librarian()
            {
                Library library;
                int choice;
                do
                {
                    std::cout <<"**************************************************************************" << std::endl;
                    std::cout << "Enter required task : \n1.Add Book\n2.Create user\n3.Return Book\n4.Borrow Book\n5.Book details\n6.Extend due date\n7.Logout" << std::endl;
                    std::cin >> choice;
                    std::cin.clear();
                    std::cin.ignore( std::numeric_limits < std::streamsize > ::max(),'\n'); 
                    switch(choice)
                    {
                        case 1:
                        {
                            add_book();
                            break;
                        }
                        case 2:
                        {
                            create_user();
                            break;
                        }
                        case 3:
                        {
                            return_book();
                            break;
                        }
                        case 4:
                        {
                            borrow_book();
                            break;
                        }
                        case 5:
                        {
                            borrower_details();
                            break;
                        }
                        case 6:
                        {
                            change_due_date();
                            break;
                        }
                        case 7:
                        {
                            break;
                        }
                        default:
                        {
                            std::cout << " Enter valid input " << std::endl;
                            break;
                        }
                    }
                
                } while ( choice != 7);

            }

};
