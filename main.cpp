#include <iostream>
#include <string>
#include "word.hpp"

using namespace std;

// forward declarations
void print_tree(word *tree);
bool process_word(string new_word, word*& tree);

int main() {
  word* root = nullptr; // start with an empty tree

  int wordcount = 0; // optional
  int individual_word_count = 0; // optional

  while (cin.eof() == false) {
    string t_word;
    cin >> t_word;
    if (cin.fail() == false) {
			wordcount++;
      if (process_word(t_word, root)) {
      	individual_word_count++;
      }
    }
  }

	cout << wordcount << " words, of which " << individual_word_count << " are distinct." << endl;
	//print_tree(root);

  return 0; // tell the OS everything is peachy
}

// returns true if the word is new, false otherwise
bool process_word(string new_word, word*& tree) {
	bool response;
	if (tree == nullptr) {
		tree = new word();
    tree->assign(new_word);
		response = true; // it is a new word
	} else {
		if (new_word == *tree) {
			tree->count++;
			response = false; // it is not a new word
		} else {
			if (new_word < *tree) {
				response = process_word(new_word, tree->before);
			} else {
				response = process_word(new_word, tree->after);
			}
		}
	}
	return response;
}

void print_tree(word *tree) {
  if (tree != nullptr) {
    print_tree(tree->before);
    cout << "\"" << *tree <<"\" " << tree->count << endl;
    print_tree(tree->after);
  }
}
