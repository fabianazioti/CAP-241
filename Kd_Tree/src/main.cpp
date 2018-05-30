/*Kdtree*/
#include"kdtree.hpp"

/*Biblioteca C++*/
#include<iostream>

int main(int argc, char *argv[])
{
    Kdtree<int> kd_tree;

    kd_tree.insert(3,6);
    kd_tree.insert(2, 7);
    kd_tree.insert(17, 15);
    kd_tree.insert(6, 12);
    kd_tree.insert(13, 15);
    kd_tree.insert(9, 1);
    kd_tree.insert(10, 19);

    Kdtree<int>::node *n =  kd_tree.find(6,12);

    if(n)
    {
      std::cout << "\nRetorna o no com as coordenadas procuradas " << std::endl;
      std::cout << "X " << n->x_ << " Y " << n->y_ << std::endl;
    }
    else
      std::cout << "Coordenada nao encontrada " << std::endl;


    std::cout << "\nRetorna os pontos dentro do retangulo " << std::endl;
    std::vector<Kdtree<int>::node *> isb = kd_tree.search(2,6,6,7);

    for(Kdtree<int>::node * values : isb)
    {
      std::cout << values->x_ << " - " << values->y_ << std::endl;
    }

//    Kdtree<double> kd_tree_d;

//    kd_tree_d.insert(3.7,6.5);
//    kd_tree_d.insert(2.2, 7.2);
//    kd_tree_d.insert(17.4, 15.1);
//    kd_tree_d.insert(6.1, 12.1);
//    kd_tree_d.insert(13.1, 15.1);
//    kd_tree_d.insert(9.5, 1.2);
//    kd_tree_d.insert(10.3, 19.4);

//    Kdtree<double>::node *nd =  kd_tree_d.find(6.0,12.0);

//    if(nd)
//    {
//      std::cout << "\nRetorna o no com as coordenadas procuradas " << std::endl;
//      std::cout << "X " << nd->x_ << " Y " << nd->y_ << std::endl;
//    }
//    else
//      std::cout << "Coordenada nao encontrada " << std::endl;

//    std::cout << "\nRetorna os pontos dentro do retangulo " << std::endl;
//    std::vector<Kdtree<double>::node *> isbd = kd_tree_d.search(2.0,6.0,6.0,7.0);

//    for(Kdtree<double>::node * values : isbd)
//    {
//      std::cout << values->x_ << " - " << values->y_ << std::endl;
//    }

    return 0;
}
