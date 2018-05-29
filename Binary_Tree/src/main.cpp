/*Btree*/
#include"btree.hpp"

/*Biblioteca C*/
#include <cmath>

/*Biblioteca C++*/
#include <fstream>
#include <iostream>
#include <random>
#include <vector>


template <class Functor> void print(Functor data){
    std::cout << data << "\t " ;
}

/*
 * Exercicio 2 deve fornecer a implementacao da arvore binaria
 * e as funcoes para insercao busca e remocao
*/
void exercicio_2()
{

    Btree<int> binary_tree;

    /* Operação de Inserção */
    binary_tree.insert(10);
    binary_tree.insert(8);
    binary_tree.insert(15);
    binary_tree.insert(13);
    binary_tree.insert(18);
    binary_tree.insert(17);
//    binary_tree.insert(20);
//    binary_tree.insert(17);
//    binary_tree.insert(18);

    /* Busca */
    Btree<int>::node *n = binary_tree.find(10);

    std::cout << "Valor procurado " << n->data << std::endl;

    std::cout << "Pre order: ";
    binary_tree.pre_order(print<int>);
    std::cout << "\n";

    /*Remoção*/
    binary_tree.erase(15, binary_tree.get_root());

    std::cout << "Pre order: ";
    binary_tree.pre_order(print<int>);
    std::cout << "\n";
}

/* Operacoes de travessia na arvore */
void exercicio_3()
{
    Btree<int> binary_tree;

    binary_tree.insert(10);
    binary_tree.insert(8);
    binary_tree.insert(15);
    binary_tree.insert(7);
    binary_tree.insert(20);

    std::cout << "\n Exercicio 3 Operacoes de travessia na arvore.. " << std::endl;

    std::cout << " Pre order: ";
    binary_tree.pre_order(print<int>);

    std::cout << "\n In order: ";
    binary_tree.in_order(print<int>);

    std::cout << "\n Pos order: ";
    binary_tree.pos_order(print<int>);

    std::cout << "\n";

//    Btree<double> binary_tree_d;

//    binary_tree_d.insert(10.0);
//    binary_tree_d.insert(8.5);
//    binary_tree_d.insert(15.2);
//    binary_tree_d.insert(7.8);
//    binary_tree_d.insert(20.2);

//    std::cout << " Pre order: ";
//    binary_tree_d.pre_order(print<double>);

//    std::cout << "\n In order: ";
//    binary_tree_d.in_order(print<double>);

//    std::cout << "\n Pos order: ";
//    binary_tree_d.pos_order(print<double>);

//    std::cout << "\n";

}

/* Calcula a altura da arvore binaria */
void exercicio_4()
{
    Btree<int> binary_tree;

    binary_tree.insert(10);
    binary_tree.insert(8);
    binary_tree.insert(15);
    binary_tree.insert(13);
    binary_tree.insert(20);
    binary_tree.insert(16);
//    binary_tree.insert(4);
//    binary_tree.insert(9);

    std::cout << "\n Exercicio 4 Altura " << std::endl;
    std::cout << "\nIn order: ";
    binary_tree.in_order(print<int>);
    std::cout << "\nAltura: " << binary_tree.height() << std::endl;
}
void exercicio_5()
{
    std::vector<int> n {10, 100, 1000, 10000, 100000,1000000, 10000000};

    std::random_device rd;
    std::mt19937 gen(rd());

    std::ofstream x;
    std::ofstream h;

    x.open ("x.txt");
    h.open("h.txt");

    for(auto nn : n)
    {
        Btree<double> binary_tree;

        for (int tam_max = 0; tam_max < nn; tam_max++)
        {
            std::uniform_real_distribution<> dis(0, 2);
            binary_tree.insert(dis(gen));
        }

        x << nn << "\n";
        h <<  binary_tree.height() << "\n";

//        std::cout << "N: " << nn << " " << "Altura "<< binary_tree.height() << " "
//                  << "altura/log2(n): " << binary_tree.height()/log2(nn) << std::endl;
    }

    x.close();
    h.close();

}
int main()
{
    exercicio_2();
    exercicio_3();
    exercicio_4();

// O exercicio 5 esta no pdf
//    exercicio_5();

    return 0;
}
