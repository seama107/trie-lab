#include "Trie.h"
#include "getTime.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

  string filename = "words.txt";
  if(argc == 2) {
    filename = argv[1];
  }
  else {
    cout << "No filename specified. ";
  }
  cout << "Using " << filename << " as dictionary." << endl;

  //File Reading
  ifstream in(filename);

  if(!in) {
    cout << "Couldn't open input file " << filename << ". Try again with a different file." << endl;
    return 1;
  }

  Trie<char> words = Trie<char>();
  string line;
  int i = 0;

  cout << "Reading File.";
  uint64 begin = GetTimeMs64();
  while (getline(in, line)) {
    if(i++ % 100000 == 0) {
      cout << ".";
    }
    words.insert(line);
  }
  uint64 end = GetTimeMs64();
  cout << endl << "Done!" << endl;
  cout << "Time elapsed: " << (end - begin) << "ms" << endl;

  //Getting user input
  while(true) {

    cout << "Enter a prefix to search for:\t";
    string userInput;
    if (!getline(cin, userInput)) {
      //IO Error
      return -1;
    }

    cout << endl << "Printing all words beggining with " << userInput << ":" << endl;
    begin = GetTimeMs64();
    words.printFromPrefix(userInput);
    end = GetTimeMs64();
    cout << endl << "Time elapsed: " << (end - begin) << "ms" << endl << "(^C to exit)" << endl;
  }

  return 0;
}
