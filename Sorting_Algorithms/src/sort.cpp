#include "sort.hpp"

//BibliotecaS C++
#include <iostream>


void selection_sort(std::vector<double> &a)
{
    size_t min_pos;

    for(size_t i = 0; i < a.size() - 1; ++i)
    {
        min_pos = i;

        for(size_t j = i+1; j < a.size(); ++j)
        {
            
            if(a[j] < a[min_pos])
               min_pos = j;
        }

        std::swap(a[i], a[min_pos]);
    }
}


void insertion_sort(std::vector<double> &a)
{

    double v;
    size_t i;

    for(size_t j = 1; j < a.size(); ++j)
    {
        
        v = a[j];
        i = j-1;

        while (i >= 0 && a[i] > v )
        {
          a[i+1] = a[i];
          i = i - 1;
        }
        a[i+1] = v;

    }
    
}

void fix_down_heap(std::vector<double> &A, int n, int pos)
{
    double v = A[pos];
    int j = (2 * pos) + 1;

    while(j <= n)
    {
        if((j < n) && (A[j] < A[j + 1]))
            ++j;

        if(v > A[j])
            break;

        A[(j -1)/ 2] = A[j];
        j = (j * 2) + 1;
    }

    A[(j -1)/ 2] = v;
}

void heapsort(std::vector<double> &A, int n)
{

    for(int k = (n-1)/ 2; k >= 0; --k)
       fix_down_heap(A, n, k);

    for(int i = n; i > 0; --i)
    {
      std::swap(A[0], A[i]);
      fix_down_heap(A, i - 1, 0);
    }
}


void merge(std::vector<double> &a, int l, int p , int r)
{
    std::vector<double> L(a.begin() + l, a.begin() + (p + 1));
    std::vector<double> R(a.begin() + (p +1) , a.begin() + r + 1);

    int i = 0, j = 0;

    L.push_back(std::numeric_limits<double>::max());
    R.push_back(std::numeric_limits<double>::max());

    for (int k = l; k <= r; k++)
    {
        if(L[i] <= R[j])
        {
          a[k] = L[i];
          i++;
         }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}
void merge_sort(std::vector<double> &a, int l, int r)
{
    int p;

    if(l < r)
    {
        p = (l + r)/2;
        merge_sort(a, l, p);
        merge_sort(a, p + 1, r);
        merge(a, l, p, r);
    }
}

int partition(std::vector<double> &a, const int &l, const int &r)
{
    double pivo = a[r];

    int i = l - 1;

    for (int j = l; j < r; ++j)
    {
         if(a[j] <= pivo)
         {
             i++;
             std::swap(a[i], a[j]);
         }
     }

     std::swap(a[i + 1], a[r]);

     return i;
}
void quick_sort(std::vector<double> &a, int l, int r)
{
    int p = 0;

    if(l < r)
    {
      p = partition(a, l, r);
      quick_sort(a, l, p);
      quick_sort(a, p + 1 , r);
    }
}
