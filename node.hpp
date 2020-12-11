#pragma once
#include <string>

class node : public std::string {
  public:
  node();
  int count; // number of occurrences
  // "before" points to the subtree of nodes that come
  // before this node in alphabetical order
  node *before;
  // "after" points to the subtree of nodes that come
  // after this node in alphabetical order, duh.
  node *after;
};
