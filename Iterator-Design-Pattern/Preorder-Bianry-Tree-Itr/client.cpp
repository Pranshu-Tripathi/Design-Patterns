#include "binary_tree.h"
#include "node.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T> void preorder(BinaryTree<T> &tree, string name) {
  std::cout << "Preorder Traversal on " << name << ": [";
  for (auto it = tree.begin(); it != tree.end(); ++it) {
    std::cout << (*it).value;
    if (tree.next(it) != tree.end()) {
      std::cout << ",";
    }
  }
  std::cout << "]" << std::endl;
}

int main() {
  /*
             me
        /          \
     son         daughter
 /       \
grand-son   grand-daughter
  */
  BinaryTree<string> family{
      new Node<string>{"me",
                       new Node<string>{"son", new Node<string>{"grand-son"},
                                        new Node<string>{"grand-daughter"}},
                       new Node<string>{"daughter"}}};
  preorder(family, "Family");

  BinaryTree<int> tree{
      new Node<int>{4, new Node<int>{2, new Node<int>{1}, new Node<int>{3}},
                    new Node<int>{5}}};

  preorder(tree, "Number Tree");
  return 0;
}
