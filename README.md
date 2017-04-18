# Search the entire English language

**Author:** Michael Seaman

**Due date:** 2017/04/20

The Trie data structure makes storing sequences of characters that share the same prefix very easy.
Sequences form a directed graph that moves away from their start character. You can play with this
data structure by exploring the english language with this demo.
Inputting the words.txt dictionary usually takes around 1s - and queries vary between 1-100ms.

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

## Outside code
The 'getTime.h' file is a code snippet written by Andreas Bonini on Stack Overflow. I used this instead of <chrono> just because I wanted support for machines without c++11.
http://stackoverflow.com/questions/1861294/how-to-calculate-execution-time-of-a-code-snippet-in-c

All other code was written by me.
- Michael Seaman

