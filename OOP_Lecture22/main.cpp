#include <iostream>

#include <algorithm>
#include <set>
#include <vector>

#include <iterator>





int main() {

    std::vector<int> collection(10);

    for (auto& i : collection) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    std::for_each(collection.begin(), \
        collection.end(), \
        [](int& a)->void {
            static int i{ 1 };
            a = i++; });

  
    for (auto& i : collection) {
        std::cout << i << " ";
    }

    std::cout << "\n\n";

    //std::vector<int> collection2(10);
    std::vector<int> collection2(collection.rbegin(), collection.rend());

    for (auto& i : collection2) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    if (std::equal(collection2.begin(), collection2.end(), \
        collection.begin(), collection.end())) {
        std::cout << "equal collection\n";
    }
    else {
        std::cout << "not equal collection\n";
    }



    /* auto b_ins = std::back_inserter(collection);

   b_ins.operator=(5);
   b_ins.operator=(6);*/

    

    std::vector<int> evens;

    std::copy_if(collection.begin(), collection.end(),
        std::back_inserter(evens), // функтор который при обращение к себе размещает данные в конце колекции
        [](const int& a)->bool { return a % 2 == 0; });


    for (auto& i : evens) {
        std::cout << i << " ";
    }

    std::cout << std::endl;







	return 0;
}