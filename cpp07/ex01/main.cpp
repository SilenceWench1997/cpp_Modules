#include <iostream>
#include "iter.hpp"

class Awesome
{
    public:
        Awesome( void ) : _n( 42 ) { return; }
        int get( void ) const { return this->_n; }
    private:
        int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & ref ) { o << ref.get(); return o; }

int main(void)
{
    int tab[5] = {0, 1, 2, 3, 4};
    Awesome tab2[5];
    iter(tab, 5, print<double>);
    iter(tab2, 5, print);
    return (0);
}
