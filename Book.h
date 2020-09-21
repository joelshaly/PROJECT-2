#include<iostream>
#include<sstream>

class Book
{
    private:

        std::string book_sl_no;
        std::string book_name;
        std::string author_name;
    
    public:

        void set_book( std::string book_name)
        {            
            this -> book_name = book_name;
        }

        void set_slno( std::string book_sl_no )
        {
            this -> book_sl_no = book_sl_no;
        }

        void set_author( std::string author_name)
        {
            this -> author_name = author_name;
        }

        std::string get_book() const
        {
            return( book_name);
        }

        std::string get_slno() const
        {
            return ( book_sl_no);
        }

        std::string get_author() const
        {
            return( author_name);
        }
        
        void read()
        {
            std::cout<<"Book Details" << std::endl;
            std::cout <<"Enter Serial Number " << std::endl;
            std::getline( std::cin , book_sl_no);
        
  
            std::cout<<"Enter book name " << std::endl;
            std::getline ( std::cin,book_name);

            std::cout <<"Enter Author Name " << std::endl;
            std::getline (std::cin ,author_name);        
        }

        void print()
        {
            std::cout <<"Sl. No : " << book_sl_no <<" Book name : " << book_name <<" Author name : " << author_name << std::endl;
        }
};

std::ostream& operator<<(std::ostream& os,const Book& b)
{
    os << b.get_slno() << "\n" << b.get_book() << "\n" << b.get_author() <<"\n";
    return os ;
}

std::istream& operator>>(std::istream& is, Book& b)
{
    std::string book_slno;
    std::getline(is, book_slno);
    b.set_slno(book_slno);

    std::string book_name;
    std::getline(is, book_name);
    b.set_book( book_name );

    std::string author_name;
    std::getline(is, author_name);
    b.set_author( author_name);
    return is;
}
