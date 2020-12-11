#include <iostream>
#include <string>
#include <fstream>
#include "node.hpp"

using namespace std;

// forward declarations
void print_tree(node *tree);
bool process_node(string new_node, node*& tree);
void find_node(node *tree, string w);

int main() {
  node* root = nullptr; // start with an empty tree

  int nodecount = 0; // optional
  int individual_node_count = 0; // optional
  
  //Initial file entry
  bool filexists = false;
  string filename, checkword;
  string t_node;
  ifstream bookfile; 

  while (!filexists){
    cout << "Please enter the name of the book file:" << endl;
    cin >> filename;
    bookfile.open(filename);
    if(bookfile.is_open()){
      filexists = true;
    } else {
      cout << "An error occurred attempting to open the file \"" << filename << "\"." << endl;
    }
  }
  
  while (bookfile >> t_node) {
      nodecount++;
      if (process_node(t_node, root)) {
      	individual_node_count++;
      }
  }
  bookfile.close();
  
	cout << "The file \"" << filename << "\" contains " << nodecount << " words of which " << individual_node_count << " are distinct." << endl;
	//print_tree(root);
  while (cin.eof() == false){
    cout << "Please enter the word you wish to check:" << endl;
    cin >> checkword;
    find_node(root, checkword);  
  }

  cout << "Goodbye" << endl;
  return 0; // tell the OS everything is peachy
}

// returns true if the node is new, false otherwise
bool process_node(string new_node, node*& tree) {
	bool response;
	if (tree == nullptr) {
    tree = new node();
    tree->assign(new_node);
		response = true; // it is a new node
	} else {
		if (new_node == *tree) {
			tree->count++;
			response = false; // it is not a new node
		} else {
			if (new_node < *tree) {
				response = process_node(new_node, tree->before);
			} else {
				response = process_node(new_node, tree->after);
			}
		}
	}
	return response;
}

void print_tree(node *tree) {
  if (tree != nullptr) {
    print_tree(tree->before);
    cout << "\"" << *tree <<"\" " << tree->count << endl;
    print_tree(tree->after);
  }
}

//Prints the word count if found
void find_node(node *tree, string w) {
    if(*tree == w){
      if (tree->count==1){
        cout << "The word \"" << w << "\" was found once." << endl << endl;
      } else if (tree->count==2){
        cout << "The word \"" << w << "\" was found twice." << endl << endl;
      } else {
        cout << "The word \"" << w << "\" was found " << tree->count << " times." << endl << endl;
        }
      } else if ((*tree > w) && (tree->before != nullptr)){
          find_node(tree->before, w);
      } else if ((*tree < w) && (tree->after != nullptr)){
          find_node(tree->after, w);
      } else {
        cout << "The word \"" << w << "\" was not found." << endl;
      }
    
  }

