#ifndef __CAP241_SORT_HPP__
#define __CAP241_SORT_HPP__

//#include "cutf8"

//Biblioteca C++
#include <algorithm>
#include <vector>

void select_sort(std::vector<double> &);
void insert_sort(std::vector<double> &);
void fix_down_heap(std::vector<double> &, int, int);
void heapsort(std::vector<double> &, int);
void merge(std::vector<double> &, size_t , size_t , size_t );
void merge_sort(std::vector<double> &, size_t, size_t);
int partition(std::vector<double> &, const int &, const int&);
void quick_sort(std::vector<double> &, int, int);




#endif //__CAP241_SORT_HPP__
