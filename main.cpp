#include "../Headers/BinaryTree.h"
#include "../Headers/Iterator.h"

int main() {
    BinaryTree_Declaration<int> tree(1);
    tree.add(3);
    std::cout << tree.count() << "\n";
    tree.add(-6);
    if (tree.find(-6)) std::cout << tree.count() << "\n";
    tree.erase(tree.root, 3);
    std::cout << tree.count() << "\n";
    tree.add(10);
    std::cout << tree.max(tree.root) << "\n";
    std::cout << tree.min(tree.root) << "\n";
    std::list<int> list;
    list = tree.toList(tree.root, &list);
    for (auto& it: list) std::cout << it << " ";
    std::cout << "\n";
    for (auto el : tree) std::cout << el << " ";
    std::cout << "\n";
    BinaryTree_Declaration<double> tree2{1.16, 5.48, 10.56, -47.32};
    tree2.add(59.36);
    tree2.add(5.32);
    for (auto el: tree2) std::cout << el << " ";
    return 0;
}
