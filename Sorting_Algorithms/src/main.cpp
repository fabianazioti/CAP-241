#include "sort.hpp"
/* Bibliotecas C++*/
#include<iostream>
#include <chrono>
#include <random>
#include fstream>


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
void teste_random()
{

    const int tam = 10000;

    std::vector<double> values(tam);

    std::fstream myfile;

    myfile.open("/home/fabiana/Documentos/INPE/devel/github/CAP-241/Sorting_Algorithms/build/tempo.txt", std::ios::in | std::ios::out | std::ios::app);

    generate_random(values);

    auto start = std::chrono::steady_clock::now();

    /* execução do seu algoritmo */
//    insert_sort(values);
//    select_sort(values);
//    merge_sort(values, 0, values.size() - 1);
    quick_sort(values, 0, values.size() - 1);
//    heapsort(values, values.size() - 1);

    auto end = std::chrono::steady_clock::now();

    auto elapsed1 = end - start;
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << elapsed1.count() << '\n';
    std::cout << elapsed.count() << '\n';


    if (myfile.is_open())
    {

      myfile.seekp(myfile.tellp());
      myfile << tam << "\t";
      myfile << (elapsed1).count() << "\t";
      myfile << (elapsed).count() << "\n";
    }


    myfile.close();

}

void order_cres()
{
    const size_t tam = 10;
    double aux = 1;
    std::vector<double> values;
    std::fstream myfile;

    myfile.open("/home/fabiana/Documentos/INPE/devel/github/CAP-241/Sorting_Algorithms/build/insert_sort.txt", std::ios::in | std::ios::out | std::ios::app);

    for(size_t i = 0; i < tam; i++)
    {
        values.push_back(aux);
        ++aux;
    }


    auto start = std::chrono::steady_clock::now();

    /* execução do seu algoritmo */
    insert_sort(values);
//    select_sort(values);
//    merge_sort(values, 0, values.size() - 1);
//    quick_sort(values, 0, values.size() - 1);
//    heapsort(values, values.size() - 1);

    auto end = std::chrono::steady_clock::now();

    auto elapsed1 = end - start;
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << elapsed1.count() << '\n';
    std::cout << elapsed.count() << '\n';


    if (myfile.is_open())
    {

      myfile.seekp(myfile.tellp());
      myfile << tam << "\t";
      myfile << (elapsed1).count() << "\t";
      myfile << (elapsed).count() << "\n";
    }


    myfile.close();

}
void order_des()
{
  const size_t tam = 1000;
  double aux = 10;
  std::vector<double> values;
  std::fstream myfile;

  myfile.open("/home/fabiana/Documentos/INPE/devel/github/CAP-241/Sorting_Algorithms/build/tempo.txt", std::ios::in | std::ios::out | std::ios::app);

  for(size_t i = 0; i < tam; i++)
  {
      values.push_back(aux);
      --aux;
  }


  auto start = std::chrono::steady_clock::now();

  /* execução do seu algoritmo */
//  insert_sort(values);
//    select_sort(values);
//    merge_sort(values, 0, values.size() - 1);
//    quick_sort(values, 0, values.size() - 1);
//    heapsort(values, values.size() - 1);

  auto end = std::chrono::steady_clock::now();

  auto elapsed1 = end - start;
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << elapsed1.count() << '\n';
  std::cout << elapsed.count() << '\n';


  if (myfile.is_open())
  {

    myfile.seekp(myfile.tellp());
    myfile << tam << "\t";
    myfile << (elapsed1).count() << "\t";
    myfile << (elapsed).count() << "\n";
  }


  myfile.close();

}
int main()
{
//    order_cres();
//    order_des();
      teste_random();

//    print_vector(values);
//    insert_sort(values);
//    select_sort(values);
//    merge_sort(values, 0, values.size() - 1);
//    quick_sort(values, 0, values.size() - 1);
//    heapsort(values, values.size() - 1);
//    heapsort(values, values.size() - 1);
//    print_vector(values);

  return 0;
}

