#include<iostream>
#include<sstream>

class Book
{
    private:

        int book_sl_no;
        std::string book_name;
        std::string author_name;
    
    public:

        void set_book( std::string book_name)
        {            
            this -> book_name = book_name;
        }

        void set_slno( int book_sl_no )
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

        int get_slno() const
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
            std::string serial_string;
            std::getline( std::cin , serial_string);
            std::stringstream linestream (serial_string);
            linestream >> book_sl_no;
  
            std::cout<<"Enter book name " << std::endl;
            std::getline ( std::cin,book_name);

            std::cout <<"Enter Author Name " << std::endl;
            std::getline (std::cin ,author_name);        
        }

        void print ()
        {
            std::cout << book_sl_no <<" " << book_name <<" " << author_name << std::endl;
        }
};

std::ostream& operator<<(std::ostream& os,const Book& b)
{
    os << b.get_slno() << "\n" << b.get_book() << "\n" << b.get_author() <<"\n";
    return os ;
}

std::istream& operator>>(std::istream& is, Book& b)
{
    std::string slnoString;
    std::getline(is, slnoString);
    std::stringstream  linestream ( slnoString );
    int book_slno;
    linestream >> book_slno;
    b.set_slno(book_slno);

    std::string book_name;
    std::getline(is, book_name);
    b.set_book( book_name );

    std::string author_name;
    std::getline(is, author_name);
    b.set_author( author_name);
    return is;
}

