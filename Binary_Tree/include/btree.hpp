/*!
 *
 * \file include/btree.hpp
 *
 * \brief Binary Tree Data Structure
 *
 * \author Fabiana Zioti
 *
 * \date 2018
 *
 */

#ifndef __CAP241_BTREE_HPP__
#define __CAP241_BTREE_HPP__

//Bibliotecas C Padrão
#include <cassert>
#include <initializer_list>

//Biblioteca C++
#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
class Btree
{
public:

    struct node
    {
    public:
        T data;
    private:
        node *left;
        node *right;

    node(const T &v, node *l = nullptr,node *r = nullptr) : data(v), left(l), right(r) { }

    friend class Btree;
    };

    /* Construtor da Classe.
     * Nao recebe nenhum parametro e inicialmente a raiz e nula
     */
    Btree();

    /* Destrutor da Classe */
    ~Btree();

    /* Insere os valores da lista na arvore binaria */
    explicit Btree(std::initializer_list<T> init);

    /* Insere um novo valor na arvore binaria */
    node *insert(const T& v);

    /* Procura um valor na arvore */
    node *find(const T& v) const;

    /* Procura um valor na arvore */
    node *find(const T& v, node* n) const;

    /* Retorna a raiz da arvore */
    node *get_root() const;

    /* Retorna o pai de um no */
    node *get_parent(const T& v) const;



    /*
     *  Algoritmos de travessia
     * Aplica uma determinada função nos elementos da árvore
    */
    template <typename Functor> void pre_order(Functor f) const;
    template <typename Functor> void in_order(Functor f) const;
    template <typename Functor> void pos_order(Functor f) const;

   /* Algoritmos de travessia */
   template<typename Functor> void pre_order(const node *n, Functor f) const;
   template<typename Functor> void in_order(const node *n, Functor f) const;
   template<typename Functor> void pos_order(const node *n, Functor f) const;

    /* Retorna a altura da arvore a partir da raiz */
    int height() const;

    void erase(const T& v, node *r);
    bool empty();

private:

    Btree(Btree&);
    Btree& operator=(Btree&);

    /* Retorna a altura da arvore dado um no */
    int height(const node* n) const;

    /* Retorna o no com o menor valor*/
    node *min_value(node *n) const;

    /* Retorna o pai de um no */
    node *get_parent(const T& v, node *r) const;

    /* Deleta a arvore binaria */
    void clear(node *n);

private:
    node *root_;
};

template <class T>
Btree<T>::Btree()
    :root_(nullptr)
{
    /* std::cout << "Constructor" << std::endl; */
}

template<class T>
Btree<T>::~Btree()
{
    /* std::cout << "Destrutor" << std::endl; */
    clear(root_);
}

template<class T>
Btree<T>::Btree(std::initializer_list<T> init)
{
  for(const T& v : init)
    insert(v);
}

template<class T> typename Btree<T>::node*
Btree<T>::insert(const T &v)
{
    node *n =  root_;
    node *parent = nullptr;

    while (n)
    {
        if(n->data == v)
            throw std::logic_error("duplicate key");
        parent = n;
        n = (v < n->data) ? n->left : n->right;
    }

    node *nn = new node(v, nullptr, nullptr );

    if(parent == nullptr)
        root_ = nn;
    else if(v < parent->data)
        parent->left = nn;
    else
        parent->right = nn;

    return nn;
}

template<class T> typename Btree<T>::node*
Btree<T>::find(const T &v) const
{
    return find(v, root_);
}

template<class T> typename Btree<T>::node*
Btree<T>::find(const T &v, node *n) const
{
    if(n == nullptr)
        return nullptr;

    if(n->data == v)
        return n;

    return (v < n->data) ? find(v, n->left) : find(v, n->right);
}


template<class T> typename Btree<T>::node*
Btree<T>::get_root() const
{
    return root_;
}

template<class T> typename Btree<T>::node*
Btree<T>::get_parent(const T &v) const
{
    return get_parent(v, root_);
}


template <class T> typename Btree<T>::node *
Btree<T>::get_parent(const T& v, node *r) const
{
  node *n =  r;
  node *parent = nullptr;

  while (n->data != v)
  {
      parent = n;
      n = (v < n->data) ? n->left : n->right;
  }

  return parent;

}


template<class T> template<class Functor> void
Btree<T>::pre_order(Functor f) const
{
    pre_order(root_, f);
}

template<class T> template<class Functor> void
Btree<T>::pre_order(const node * n, Functor f) const
{
    if(n == nullptr)
      return;

    f(n->data);
    pre_order(n->left, f);
    pre_order(n->right, f);
}

template<class T> template<class Functor> void
Btree<T>::in_order(Functor f) const
{
    in_order(root_, f);
}

template<class T> template<class Functor> void
Btree<T>::in_order(const node * n, Functor f) const
{
    if(n == nullptr)
      return;

    in_order(n->left, f);
    f(n->data);
    in_order(n->right, f);
}

template<class T> template<class Functor> void
Btree<T>::pos_order(Functor f) const
{
    pos_order(root_, f);
}

template<class T> template<class Functor> void
Btree<T>::pos_order(const node * n, Functor f) const
{
    if(n == nullptr)
      return;

    pos_order(n->left, f);
    pos_order(n->right, f);
    f(n->data);
}

template<class T> int
Btree<T>::height() const
{
    height(root_);
}

template<class T> int
Btree<T>::height(const node *n) const
{
    if(n == nullptr)
        return 0;

     int Ae = height(n->left);
     int Ad = height(n->right);

      return (Ae < Ad) ? (Ad + 1) : (Ae + 1);
}

template<class T> void
Btree<T>::clear(node *n)
{
    if(n)
    {
        clear(n->left);
        clear(n->right);

        delete n;
        n = nullptr;
    }
}

template<class T> typename Btree<T>::node*
Btree<T>::min_value(node *n) const
{
    node *aux = n;

    while(aux->left != nullptr)
        aux = aux->left;

    return aux;
}

template<class T> void
Btree<T>::erase(const T &v, node *r)
{
    if(r == nullptr)
    {
        std::cout << "The Btree is empty" << std::endl;
        return;
    }

    node *n = find(v, r);
    node *parent = get_parent(n->data, r);
    node *aux = nullptr;

    if(n->left != nullptr && n->right != nullptr)
    {
         aux = min_value(n->right);
         node *tmp = new node(n->data, aux->left, aux->right);
         node *parent_aux = get_parent(aux->data);
         aux->left = n->left;
         aux->right = n->right;

        if(parent != nullptr)
        {
          if(parent->left->data == v)
            parent->left = aux;
          else
            parent->right = aux;
        }

        if(parent_aux->left->data == aux->data)
          parent_aux->left = tmp;
        else
          parent_aux->right = tmp;

        erase(tmp->data, parent_aux);

    }
    else
    {
      if(n->right == nullptr && n->left != nullptr )
      {
        aux = n->left;
      }
      else if(n->left == nullptr && n->right != nullptr)
      {
        aux = n->right;
      }

      /*Arruma o ponteiro do pai*/
      // no caso do no deletado ser a raiz. parent esta como null
      if(parent != nullptr)
      {
        if(parent->left->data == v)
          parent->left = aux;
        else
          parent->right = aux;
      }
      else
        r = aux;

    }

    delete (n);
    n = nullptr;

}


#endif //__CAP241_BTREE_HPP__
