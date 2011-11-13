

/*
Boost distribution
boost_1_47_0/ .................The “boost root directory”
   index.htm .........A copy of www.boost.org starts here
   boost/ .........................All Boost Header files
    
   libs/ ............Tests, .cpps, docs, etc., by library
     index.html ........Library documentation starts here
     algorithm/
     any/
     array/
                     …more libraries…
   status/ .........................Boost-wide test suite
   tools/ ...........Utilities, e.g. Boost.Build, quickbook, bcp
   more/ ..........................Policy documents, etc.
   doc/ ...............A subset of all Boost library docs

 1) get boost
 2) no need to build anything just: tar --bzip2 -xf /path/to/boost_1_47_0.tar.bz2
 3) compile:  c++ -I path/to/boost_1_47_0 example.cpp -o example
 4) run: echo 1 2 3 | ./example
*/

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main() {
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );
}
