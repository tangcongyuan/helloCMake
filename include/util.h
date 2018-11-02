#ifndef __UTIL_H__
#define __UTIL_H__
#include <iomanip>
#include <iostream>

namespace util {

    template<typename Container>
    inline void print(Container& c, const char* title = "") {
        using namespace std;
        std::cout << title << ":" << std::endl;
        if(c.empty()) {
            std::cout << "(empty)" << std::endl;
            return;
        }
        typename Container::iterator it;
        for(it = c.begin(); it != c.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << std::left << std::setw(12) << "size() " << c.size() << std::endl
                  << std::left << std::setw(12) << "max_size() " << c.max_size() << std::endl
                  << std::left << std::setw(12) << "front() " << c.front() << std::endl
                  << std::left << std::setw(12) << "back() " << c.back() << std::endl
                  << std::endl;
    }

}
#endif // __UTIL_H__
