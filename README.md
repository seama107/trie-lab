# Search the entire English language

**Author:** Michael Seaman

**Due date:** 2017/04/20

The Trie data structure makes storing sequences of characters that share the same prefix very easy.
Sequences form a directed graph that moves away from their start character. You can play with this
data structure by exploring the english language with this demo.

## Setup

Get the english dictionary text file by executing the following command:
```
curl https://raw.githubusercontent.com/dwyl/english-words/master/words.txt >> words.txt
```

Then compile and execute the demo by calling:
```
g++ *.cpp
./a.out
```

If you want to specify a seperate filename instead of the english dictionary, you can do so by running a.out as so:
```
./a.out <YOUR_FILENAME>
```


![Trie Image](/trie.png)


## Assignment Specification: Trie Lab
Watch this intro to Tries: https://www.youtube.com/watch?v=AXjmTQ8LEoI

Implement a Trie data structure in C++ from scratch.

Write a program that does the following:

1) Build a trie containing all the words in the English dictionary:

https://github.com/dwyl/english-words/blob/master/words.txt

2) Write a program that prompts the user for the first k letters of a word (choose k at random) and then displays all words in the English language that start with that prexif.

You may work in pairs.
