#include "searchable_tree_bag.hpp"
#include <cstddef>

bool searchable_tree_bag::has(int a) const
{
	if (this->tree == NULL) {
		// std::cout << "tree is null - adding" << std::endl;
		return false;
	} 
    else 
    {
		node *current = this->tree;
		while (true) 
        {
            if ( a == current->value)
            { 
                return true ;
            } 
            else 
            {
			    if (a < current->value) 
                {
				    if (current->l == NULL)
                    {
					    return false;
				    } 
                    else 
                    {
					    current = current->l;
				    }
			    } 
                else if (a > current->value) 
                {
				    if (current->r == NULL)
                    {
					    return false ;
				    }
                    else
                    {
					    current = current->r;
				    }
			    }
		    }
	    }
    }
}
