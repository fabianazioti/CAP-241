/*Sort*/
#include "sort.hpp"

/* Bibliotecas C++*/
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <random>


void print_vector(const std::vector<double>& values)
{
  for(auto v : values)
  {
       std::cout << v << '\t';
  }

  std::cout << "\n";

}

void generate_random(std::vector<double> &vet)
{
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_real_distribution<> dis(0, 2.0);

    for (size_t n = 0; n < vet.size() ; ++n)
    {
         vet[n] = dis(gen);
    }

}

void teste_random(std::vector<double>& values, std::string path)
{
    std::fstream myfile;

    myfile.open(path, std::ios::in | std::ios::out | std::ios::app);


    generate_random(values);

    auto start = std::chrono::steady_clock::now();

    /* execução do seu algoritmo */
    // insertion_sort(values);
    // selection_sort(values);
    // merge_sort(values, 0, values.size() - 1);
    quick_sort(values, 0, values.size() - 1);
    // heapsort(values, values.size() - 1);

    // stl algorithm
    // std::sort(values.begin(),values.end());
    // std::stable_sort(values.begin(),values.end());

    // std::make_heap(values.begin(),values.end());
    // std::sort_heap(values.begin(),values.end());

    auto end = std::chrono::steady_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // std::cout << elapsed.count() << '\n';

    if (myfile.is_open())
    {

        myfile.seekp(myfile.tellp());
        myfile << (elapsed).count() << "\n";
    }


    myfile.close();

}

void order(std::vector<double>& values, std::string path)
{
    std::fstream myfile;

    myfile.open(path, std::ios::in | std::ios::out | std::ios::app);

    auto start = std::chrono::steady_clock::now();

    /* execução do seu algoritmo */
    // insertion_sort(values);
    // selection_sort(values);
    // merge_sort(values, 0, values.size() - 1);
    quick_sort(values, 0, values.size() - 1);
    // heapsort(values, values.size() - 1);

    // // stl algorithm
    // std::sort(values.begin(),values.end());
    // std::stable_sort(values.begin(),values.end());

    // std::make_heap(values.begin(),values.end());
    // std::sort_heap(values.begin(),values.end());

    auto end = std::chrono::steady_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // std::cout << elapsed.count() << '\n';

    if (myfile.is_open())
    {

      myfile.seekp(myfile.tellp());
      myfile << (elapsed).count() << "\n";
    }
    else
        std::cout << "Error open file" << '\n';


    myfile.close();

}

int main()
{
    std::vector<size_t> tam_vec = {19200, 38400, 76800, 153600, 307200, 614400};
    // std::vector<size_t> tam_vec = {19};

    // std::string random = "insertion_sort_rand.txt";
    // std::string des = "insertion_sort_de.txt";
    // std::string cres = "insertion_sort_cre.txt";

    // std::string random = "selection_sort_rand.txt";
    // std::string des = "selection_sort_de.txt";
    // std::string cres = "selection_sort_cre.txt";

    // std::string random = "merge_sort_rand.txt";
    // std::string des = "merge_sort_de.txt";
    // std::string cres = "merge_sort_cre.txt";

    std::string random = "quick_sort_rand.txt";
    std::string des = "quick_sort_de.txt";
    std::string cres = "quick_sort_cre.txt";

    // std::string random = "heapsort_rand.txt";
    // std::string des = "heapsort_de.txt";
    // std::string cres = "heapsort_cre.txt";


    // std::string random = "stlsort_rand.txt";
    // std::string des = "stlsort_de.txt";
    // std::string cres = "stlsort_cre.txt";

    // std::string random = "stlstable_sort_rand.txt";
    // std::string des = "stlstable_sort_de.txt";
    // std::string cres = "stlstable_sort_cre.txt";

    // std::string random = "stlsort_heap_sort_rand.txt";
    // std::string des = "stlsort_heap_sort_de.txt";
    // std::string cres = "stlsort_heap_sort_cre.txt";




    for(int i = 0; i < tam_vec.size(); i++)
    {
        std::cout << "i " << i << std::endl;
        std::vector<double> values(tam_vec[i]);
        teste_random(values, random);
        order(values, cres);
        std::reverse(std::begin(values), std::end(values));
        order(values, des);

    }


  return 0;
}
