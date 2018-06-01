#ifndef __CAP241_MULTTREE_HPP__
#define __CAP241_MULTTREE_HPP__


//Bibliotecas C Padrão
#include <initializer_list>
#include <cassert>

//Biblioteca C++
#include <algorithm>
#include <iostream>
#include <vector>

template <class T> class Multtree
{
public:
    Multtree();
    Multtree(Multtree *m, T data);
    ~Multtree();
    void push_back(Multtree *child);
    T get_data() const;
    void set_data(const T &data);
    Multtree* get_parent() const;
    void set_parent( Multtree* parent);

private:
    Multtree *parent_;
    std::vector<Multtree*> children_;
    T data_;

};

template<class T>
Multtree<T>::Multtree()
:parent_(nullptr)
{
    std::cout << "Construtor Multtree" << std::endl;
}

template<class T>
Multtree<T>::Multtree(Multtree *m, T data)
:parent_(m), data_(data)
{
//    parent_->push_back(this);
    m->push_back(this);
}

template<class T>
Multtree<T>::~Multtree()
{
  std::cout << "Destrutor" << std::endl;
}


template<class T> void
Multtree<T>::push_back(Multtree *child)
{
    children_.push_back(child);
    child->set_parent(this);
}

template<class T> void
Multtree<T>::set_parent(Multtree *parent)
{
    parent_ = parent;
}

template<class T> T
Multtree<T>::get_data() const
{
    return data_;
}

template<class T> void
Multtree<T>::set_data(const T &data)
{
    data_ = data;
}

template<class T> Multtree<T>*
Multtree<T>::get_parent() const
{
    return parent_;
}


#endif //__CAP241_MULTTREE_HPP__
