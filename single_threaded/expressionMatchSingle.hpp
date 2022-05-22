/*

Tree/Trie backtracked based solution

IDEA:

Make a n Tree of all the REs and traverse the tree based as Trie Traversal.

The deepest traversed node is the best answer to the input string 

Node can be categorized in two ways 
String node and variable node 

When one instance reaches the end of a node 
it pushes the result <depth><str*> to a max heap.
and we return from the maxHeap.

*/


#pragma once 
//#include "/Users/sahil/Personel/stdc++.h"

#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
#include<iostream>
#include<list>



using namespace std;


class Node {
    // Elemental class of the complete strucuture 
    // this is similar to a trie based node
    // just with child nodes recognized by hash, not ascii values

public:
    bool    isEnd;
    bool    isVariable;
    int     varCount;

    string  word;                           // holds the information for the current node word
    string  expression;                     // RE belonging to this path

    unordered_map<string,Node*> children;

    Node()
    {
        isEnd       = false;
        isVariable  = false;
        varCount    = 0;
    }

};



class ExpressionMatch {

private:
    Node*       head;

    string      variable;
    string      delimeters;
    int         dictSize;
    int         varLimit;

    priority_queue< pair<int,string> > resultHeap;

private:
    void    __stringTokenize__      (const string &input, vector<string> &output);
    void    __stringsToMap__        (vector<string> &expressionList, unordered_map< string,vector<string> > &expressionMap);
    void    __varCompress__         (vector<string> &uncompressedToken, vector<string> &compressedToken);

    void    __insert__              (string expression, vector<string> &tokenExpression);

    void    __varParse__            (Node* current, int i, int depth, int size, vector<string> &tokenExpression);
    void    __varParseMin__         (Node* current, int i, int depth, int size, vector<string> &tokenExpression);
    void    __varParseMax__         (Node* current, int i, int depth, int size, vector<string> &tokenExpression);

    void    __wordPrase__         (Node* current, int i, int depth, int size, vector<string> &tokenExpression);


    void    __printNode__           (Node* current);
    void    __printDFS__            (Node* current);
    void    __printBFS__            (Node* current);
    void    __beautyBFS__           (list<Node*> level);
public:

    ExpressionMatch     (string varExpression, string delimeters, int varLimit);

    void    printDFS    ();
    void    printBFS    ();

    void    insert      (vector<string> expressionList);
    string  search      (string body);


};
