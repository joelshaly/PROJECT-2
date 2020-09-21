#include<iostream>
#include<sstream>
#include<ctime>

class Borrow
{
    private:
            std::string borrow_book_name;
            std::string borrow_book_slno;
            std::string borrower_name;
            time_t due_date;
    public:
            void set_book_name( std::string  borrow_book_name)
            {
                this-> borrow_book_name = borrow_book_name;
            }

            void set_book_slno( std::string borrow_book_slno)
            {
                this-> borrow_book_slno = borrow_book_slno;
            }   

            void set_borrower_name( std::string borrower_name)
            {
                this-> borrower_name= borrower_name;
            }

            void set_due_date(int due_date)
            {
                this -> due_date = due_date;
            }

            std::string get_book_slno() const
            {
                return borrow_book_slno;
            }

            std::string get_book_name() const
            {
                return borrow_book_name;
            }

            std::string get_borrower_name() 
            {
                return borrower_name;
            }

            int get_due_date() const
            {
                return due_date;
            }

            void read(std::string borrow_book_name, std::string borrow_book_slno , std::string borrower_name)
            {
                int due;
                this -> borrow_book_name = borrow_book_name;
                this -> borrow_book_slno = borrow_book_slno;
                this -> borrower_name = borrower_name;

                due = time(&due_date) + 604800;
                due_date = due;
            }

            void print ()
            {
                    std::cout <<"BOOK DETAILS OF " << borrower_name << std::endl;
                    std::cout <<"Book Sl No.: " <<borrow_book_slno <<"\nBook Name : " << borrow_book_name <<"\nDue by : " << ctime (&due_date) << std::endl;
            }
};

std::ostream& operator<<(std::ostream& os, Borrow& b)
{
    os << b.get_book_slno() << "\n" << b.get_book_name() << "\n" << b.get_borrower_name() <<"\n" << b.get_due_date() << std::endl ;
    return os ;
}


std::istream& operator>>(std::istream& is, Borrow& b)
{
    std::string borrow_book_slno;
    std::getline(is, borrow_book_slno);
    b.set_book_slno(borrow_book_slno);
    
    std::string borrow_book_name;
    std::getline(is, borrow_book_name);
    b.set_book_name( borrow_book_name );

    std::string borrower_name;
    std::getline(is, borrower_name);
    b.set_borrower_name( borrower_name );
    
    std::string due_date_string;
    std::getline(is, due_date_string);
    std::stringstream  linestream2 ( due_date_string );
    int due_date;
    linestream2 >> due_date;
    b.set_due_date(due_date);
    return is;
}


