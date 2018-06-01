
#include"multitree.hpp"

#include <iostream>

int main()
{
    Multtree<int> t1;
    Multtree<int> t2;

    t1.set_data(4);
    t2.set_data(2);
    Multtree<int> t3(&t1, 3);

    t1.push_back(&t2);

    std::cout << t1.get_parent() << '\n';
    std::cout << t3.get_parent()->get_data() << '\n';

    return 0;
}
