#include "node.h"
#include "binary_tree.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
Node<T>::Node(T value, Node<T> *left, Node<T> *right)
    : value(value), left(left), right(right) {
  this->left->tree = this->right->tree = tree;
  this->left->parent = this->right->parent = this;
  std::cout << "Created Node [" << value << "] sucessfully" << std::endl;
}

template <typename T> Node<T>::Node(T value) : value(value) {
  this->left = nullptr;
  this->right = nullptr;
  std::cout << "Created Node [" << value << "] sucessfully" << std::endl;
}

template <typename T> Node<T>::~Node() {
  if (this->left)
    delete this->left;
  if (this->right)
    delete this->right;
}

template <typename T> void Node<T>::set_tree(BinaryTree<T> *t) {
  this->tree = t;
  if (this->left) {
    this->left->set_tree(t);
  }
  if (this->right) {
    this->right->set_tree(t);
  }
}

// template initialization
template class Node<string>;
template class Node<int>;
