// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>

class Tree {
 private:
  struct Node { // ...
    char value;
    std::vector<Node*> chd;
  };
  Node* root;
  std::vector<std::string> numbers;

  void createTree(Node* root, std::vector<char> _numbers) {
    if (_numbers.size() == 0)
      return;
    if (root->value != '-') {
      for (auto  n = _numbers.begin(); n != _numbers.end(); ++n) {
        if (*n == root->value) {
          _numbers.erase(n);
          break;
        }
      }
    }
    for (size_t n = 0; n < _numbers.size(); ++n) {
      root->chd.push_back(new Node);
    }
    for (size_t n = 0; n < root->chd.size(); ++n) {
      root->chd[n]->value = _numbers[n];
    }
    for (size_t n = 0; n < root->chd.size(); ++n) {
      createTree(root->chd[n], _numbers);
    }
  }
  void perem(Node* root, std::string number = "") {
    if (root->value != '-') {
      number += root->value;
    }
    if (!root->chd.size()) {
      number += root->value;
      numbers.push_back(number);
      return;
    }
    for (size_t n = 0; n < root->chd.size(); ++n) {
      perem(root->chd[n], number);
    }
  }

 public:
  std::string operator[](int n) const {
  return numbers[n];
  }
  explicit Tree(std::vector<char> value) {
    root = new Node;
    root->value = '-';
    createTree(root, value);
    perem(root);
  }
};
#endif  // INCLUDE_TREE_H_
