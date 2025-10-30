#ifndef SET_HPP
#define SET_HPP
#include "searchable_bag.hpp"

class set 
{
    private:
        searchable_bag * bag;
    public:
        set( void ) ;
        ~set( void ) ;        
        set( searchable_bag  & other ) ;                
        set & operator=( searchable_bag & other ) ;   
        void insert (int);
	    void insert (int *, int) ;
	    void print() const ;
	    void clear() ; 
        
        bool has( int  ) const ;
        searchable_bag & get_bag( void ) const; 


};



#endif
