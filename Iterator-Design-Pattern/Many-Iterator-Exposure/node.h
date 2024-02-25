#pragma once

template <typename T> class BinaryTree;

template <typename T> class Node {
public:
  T value = T();
  Node<T> *left{nullptr}, *right{nullptr}, *parent{nullptr};
  BinaryTree<T> *tree{nullptr};

  Node(T value);

  Node(T value, Node<T> *left, Node<T> *right);

  ~Node();

  void set_tree(BinaryTree<T> *t);
};
