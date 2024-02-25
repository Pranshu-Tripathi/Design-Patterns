#pragma once
#include "node.h"

template <typename T> class BinaryTree {
  Node<T> *root{nullptr};

public:
  BinaryTree(Node<T> *root);
  ~BinaryTree();

  template <typename U> class PreorderIterator {
    Node<U> *current;

  public:
    PreorderIterator(Node<U> *current);
    bool operator!=(const PreorderIterator<U> &other);
    PreorderIterator<U> &operator++();
    Node<U> &operator*();
  };

  typedef PreorderIterator<T> iterator;

  iterator begin();

  iterator end();

  iterator next(iterator &it);
};
