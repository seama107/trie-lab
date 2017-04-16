#ifndef Trie_h
#define Trie_h

#include <iostream>
#include <string>
#include "trieNode.h"

using namespace std;

template <typename T>
class Trie
{
private:
  TrieNode<T> *root;
  int size;

public:
  Trie();
  ~Trie();

  int getSize();
  void insert(const T* word, int arrayLength);
  void insert(string word);

  TrieNode<T>* findNode(const T* word, int arrayLength);
  TrieNode<T>* findNode(string word);

  void printFromPrefix(const T* word, int arrayLength, ostream& out);
  void printFromPrefix(string word, ostream& out);
  void printFromPrefix(string word);

  void streamRecursive(TrieNode<T>* current, string strSoFar, ostream& out);
  friend ostream& operator<<(ostream& out, Trie<T>& t) {
    //Prints all keys(chars) seen from this node
    t.streamRecursive(t.root, "", out);
    return out;
  }

};

template <typename T>
Trie<T>::Trie() {
  size = 0;
  root = new TrieNode<T>;
}

template <typename T>
Trie<T>::~Trie() {
  delete root;
}

template <typename T>
int Trie<T>::getSize() {
  return size;
}

template <typename T>
void Trie<T>::insert(string word) {
  insert(word.data(), word.length());
}

template <typename T>
void Trie<T>::insert(const T* word, int arrayLength) {
  TrieNode<T>* current = root;
  for (int i = 0; i < arrayLength; i++) {
    bool newChar;
    bool nodeIsEmpty = (current->next.size() == 0);

    if(nodeIsEmpty) {
      newChar = true;
    }
    else {
      typename map<T, TrieNode<T>*>::iterator it = current->next.find(word[i]);
      newChar = (it == current->next.end());
    }

    if(newChar) {
      current->next[word[i]] = new TrieNode<T>();

    }
    if(i + 1 == arrayLength) {
      //Last char
      current->next[word[i]]->isEndOfWord = true;
    }
    current = current->next[word[i]];
  }

  size++;
}

template <typename T>
TrieNode<T>* Trie<T>::findNode(string word) {
  return findNode(word.data(), word.length());
}

template <typename T>
TrieNode<T>* Trie<T>::findNode(const T* word, int arrayLength) {
  TrieNode<T>* current = root;
  for (int i = 0; i < arrayLength; i++) {

    typename map<T, TrieNode<T>*>::iterator it = current->next.find(word[i]);
    bool hasChar = (it != current->next.end());

    if(hasChar) {
      current = current->next[word[i]];
    }
    else {
      return nullptr;
    }
  }
  return current;
}

template <typename T>
void Trie<T>::printFromPrefix(const T* word, int arrayLength, ostream& out) {
  TrieNode<T>* current = findNode(word, arrayLength);
  if(current) {
    //node was found
    streamRecursive(current, string(word), out);
  }
  else {
    out << "No Results found." << endl;
  }
}

template <typename T>
void Trie<T>::printFromPrefix(string word, ostream& out) {
  printFromPrefix(word.data(), word.length(), out);
}

template <typename T>
void Trie<T>::printFromPrefix(string word) {
  printFromPrefix(word.data(), word.length(), cout);
}

template <typename T>
void Trie<T>::streamRecursive(TrieNode<T>* current, string strSoFar, ostream& out) {
  if(current->isEndOfWord) {
    cout << strSoFar << endl;
  }
  typedef typename map<T, TrieNode<T>*>::const_iterator it_type;
  for(it_type it = current->next.begin(); it != current->next.end(); it++) {
    //meaning the iterator is pointing to a pointer whose node has more entries
    string nextString = strSoFar + it->first;
    streamRecursive(it->second, nextString, out);
  }


}


#endif
