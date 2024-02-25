#include "binary_tree.h"
#include "node.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
BinaryTree<T>::BinaryTree(Node<T> *root) : root(root), pre_order(*this) {
  root->set_tree(this);
  std::cout << "Binary Tree Rooted at [" << root->value
            << "] created successfully!" << std::endl;
}

template <typename T> BinaryTree<T>::~BinaryTree() {
  if (root)
    delete root;
}

template <typename T>
template <typename U>
BinaryTree<T>::PreorderIterator<U>::PreorderIterator(Node<U> *current)
    : current(current) {}

template <typename T>
template <typename U>
bool BinaryTree<T>::PreorderIterator<U>::operator!=(
    const PreorderIterator<U> &other) {
  return current != other.current;
}

template <typename T>
template <typename U>
typename BinaryTree<T>::template PreorderIterator<U> &
BinaryTree<T>::PreorderIterator<U>::operator++() {
  if (current->right) {
    current = current->right;
    while (current->left) {
      current = current->left;
    }
  } else {
    Node<T> *p = current->parent;
    while (p && current == p->right) {
      current = p;
      p = p->parent;
    }
    current = p;
  }
  return *this;
}

template <typename T>
template <typename U>
Node<U> &BinaryTree<T>::PreorderIterator<U>::operator*() {
  return *current;
}

template <typename T> typename BinaryTree<T>::iterator BinaryTree<T>::begin() {
  Node<T> *n = root;
  if (n) {
    while (n->left) {
      n = n->left;
    }
  }
  return iterator{n};
}

template <typename T> typename BinaryTree<T>::iterator BinaryTree<T>::end() {
  return iterator{nullptr};
}

template <typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::next(iterator &it) {
  auto temp_it = it;
  return ++temp_it;
}

template <typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::PreorderTraversal::begin() {
  return tree.begin();
}

template <typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::PreorderTraversal::end() {
  return tree.end();
}

// template initialization

template class BinaryTree<string>;
template class BinaryTree<string>::PreorderIterator<string>;
template class BinaryTree<int>;
template class BinaryTree<int>::PreorderIterator<int>;
