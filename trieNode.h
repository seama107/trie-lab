#ifndef TrieNode_h
#define TrieNode_h

#include <iostream>
#include <map>

template <typename T>
class TrieNode
{

public:
  std::map<T, TrieNode<T>*> next;

  ~TrieNode();
	TrieNode();
  TrieNode(bool isEnd);

  bool isEndOfWord;


  friend std::ostream& operator<<(std::ostream& out, const TrieNode<T>& t) {
    //Prints all keys(chars) seen from this node
    typedef typename std::map<T, TrieNode<T>*>::const_iterator it_type;
    for(it_type it = t.next.begin(); it != t.next.end(); it++) {
      out << it->first;
    }
    return out;
  }
};

template <typename T>
TrieNode<T>::TrieNode() {
  isEndOfWord = false;
}

template <typename T>
TrieNode<T>::TrieNode(bool isEnd) {
  isEndOfWord = isEnd;
}

template <typename T>
TrieNode<T>::~TrieNode() {
  typedef typename std::map<T, TrieNode<T>*>::iterator it_type;
  for(it_type it = next.begin(); it != next.end(); it++) {
    delete it->second;
    it->second = NULL;
  }
}

#endif
