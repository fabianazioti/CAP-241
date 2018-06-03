/*!
 *
 * \file include/kdtree.hpp
 *
 * \brief Kd Tree Data Structure
 *
 * \author Fabiana Zioti
 *
 * \date 2018
 *
 */

#ifndef __CAP241_KDTREE_HPP__
#define __CAP241_KDTREE_HPP__

//Bibliotecas C Padrão
#include <cassert>
#include <initializer_list>

//Biblioteca C++
#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
class Kdtree
{
public:
    struct node
    {
      public:
          T x_;
          T y_;
      private:
        node *left;
        node *right;

        node(const T& x,const T& y, node *l = nullptr, node *r = nullptr): x_(x), y_(y), left(l), right(r) {}

      friend class Kdtree;

    };

    /*Construtor da classe */
    Kdtree();

    /* Destrutor da classe */
    ~Kdtree();

    /*Insere um novo no de coordenadas x e y*/
    node *insert(const T& x, const T& y);


    /*Encontra um novo no de coordenadas x e y*/
    node *find(const T& x, const T& y);

    /* Retorna o conjunto de todos os noss cujos pontos
     * estao contidos no retangulo de busca */
    std::vector<node*>search(const T& xmin, const T& xmax, const T& ymin,const T& ymax);

private:

    Kdtree(Kdtree&);
    Kdtree& operator=(Kdtree&);

    /*Retorna se dois pontos sao iguais*/
    bool compare_point(const T& x, const T& y, const T& x1, const T& y1, const int& h);

    /*Encontra um novo no de coordenadas x e y*/
    node *find(const T& x, const T& y, node *n);

    /* Retorna o conjunto de todos os noss cujos pontos
     * estao contidos no retangulo de busca */
    void search(const T& xmin, const T& xmax, const T& ymin,const T& ymax, node *n,
                             std::vector<node*>& is_bbox, size_t h);

    /*Retorna true or false se um valor esta dentro das coordenadas maximas e minimas */
    bool isin_bbox(const T &min, const T &max, const T &v);

    /*Limpa a kdtree*/
    void clear(node *n);

private:
    node *root_;
};

template<class T> Kdtree<T>::Kdtree()
    :root_(nullptr)
{
   /* std::cout << "Construtor \n"; */
}

template<class T> Kdtree<T>::~Kdtree()
{
    /* std::cout << "Destrutor \n"; */
    clear(root_);
}

template<class T> typename Kdtree<T>::node*
Kdtree<T>::insert(const T& x, const T& y)
{
    node *n =  root_;
    node *parent = nullptr;
    int h = 0;

    while (n)
    {
        if(n->x_ == x && n->y_ == y)
            throw std::logic_error("duplicate point key");

        parent = n;

        n = (compare_point(x, y, n->x_, n->y_, h)) ? n->left : n->right;

        if(n)
            h++;
    }

    node *nn = new node(x, y, nullptr, nullptr );

    if(parent == nullptr)
        root_ = nn;
    else if(compare_point(x, y, parent->x_, parent->y_, h))
        parent->left = nn;
    else
        parent->right = nn;

    return nn;

}

template<class T> typename Kdtree<T>::node*
Kdtree<T>::find(const T &x, const T &y)
{
    find(x, y, root_);
}

template<class T> typename Kdtree<T>::node*
Kdtree<T>::find(const T &x, const T &y, node *n)
{
    if(n == nullptr)
        return n;

    int h = 0;

    while (n)
    {
        if(n->x_ == x && n->y_ == y)
            return n;

        n = (compare_point(x, y, n->x_, n->y_, h)) ? n->left : n->right;

        if(n)
            h++;
    }

    if(!n)
      return nullptr;

    return n;

}

template<class T> bool
Kdtree<T>::compare_point(const T& x, const T& y, const T& x1, const T& y1, const int& h)
{
    bool r;

    ((h % 2) == 0) ? (r = (x < x1)) : (r = (y < y1) );

    return r;
}

template<class T> std::vector<typename Kdtree<T>::node*>
Kdtree<T>::search(const T &xmin, const T &xmax, const T &ymin, const T &ymax)
{
  std::vector<node*> is_bbox;
  size_t h = 0;

  search(xmin, xmax, ymin, ymax, root_, is_bbox, h);
  return is_bbox;
}

template<class T> void
Kdtree<T>::search(const T &xmin, const T &xmax, const T &ymin, const T &ymax, node *n,
                  std::vector<node*>& is_bbox, size_t h)
{
  bool aux;

  if(n == nullptr)
    return;

   aux = ((h % 2) == 0) ? isin_bbox(xmin, xmax, n->x_) : isin_bbox(ymin, ymax, n->y_);

   if(aux)
   {
     search(xmin, xmax, ymin, ymax, n->left, is_bbox, h + 1);
     search(xmin, xmax, ymin, ymax, n->right, is_bbox, h + 1);

     aux = (((h + 1) % 2) == 0) ? isin_bbox(xmin, xmax, n->x_) : isin_bbox(ymin, ymax, n->y_);

     if(aux)
       is_bbox.push_back(n);
   }


   else if(compare_point(xmax, ymax, n->x_, n->y_, h))
     search(xmin, xmax, ymin, ymax, n->left, is_bbox,h + 1);

   else if(compare_point(n->x_, n->y_, xmin, ymin, h))
     search(xmin, xmax, ymin, ymax, n->right, is_bbox,h + 1);

   else
   {
     search(xmin, xmax, ymin, ymax, n->left, is_bbox,h + 1);
     search(xmin, xmax, ymin, ymax, n->right, is_bbox,h + 1);

   }

}

template<class T> bool
Kdtree<T>::isin_bbox(const T &min, const T &max, const T &v)
{
    if(v >= min && v <= max)
      return true;

    return false;
}

template<class T> void
Kdtree<T>::clear(node *n)
{
    if(n)
    {
        clear(n->left);
        clear(n->right);
        delete n;
        n = nullptr;
     }
}

#endif // __CAP241_KDTREE_HPP__
