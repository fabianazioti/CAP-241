#ifndef __CAP241_SORT_HPP__
#define __CAP241_SORT_HPP__

//#include "cutf8"

//Biblioteca C++
#include <algorithm>
#include <vector>

void selection_sort(std::vector<double> &);
void insertion_sort(std::vector<double> &);
void fix_down_heap(std::vector<double> &, int, int);
void heapsort(std::vector<double> &, int);
void merge(std::vector<double> &, int , int , int );
void merge_sort(std::vector<double> &, int, int);
int partition(std::vector<double> &, const int &, const int&);
void quick_sort(std::vector<double> &, int, int);




#endif //__CAP241_SORT_HPP__
