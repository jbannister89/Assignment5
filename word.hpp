#pragma once
#include <string>

class word : public std::string {
  public:
  word();
  int count; // number of occurrences
  // "before" points to the subtree of words that come
  // before this word in alphabetical order
  word *before;
  // "after" points to the subtree of words that come
  // after this word in alphabetical order, duh.
  word *after;
};
