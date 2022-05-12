#include "expressionMatchSingle.hpp"


ExpressionMatch::ExpressionMatch    (string varExpression, string delimeters)
{
    head                = new Node();
    this->variable      = varExpression;
    this->delimeters    = delimeters;
    dictSize            = 256;

}

void    ExpressionMatch::__stringTokenize__     (const string &input, vector<string> &output)
{
    vector<bool>    dict(dictSize,false);
    string          token("");

    for(int i = 0;i<delimeters.size();++i)
    {
        dict[delimeters[i]] = true;
    }

    for(char i:input)
    {
        if(dict[i]) {
            if(!token.empty()) {
                output.push_back(token);
                token.clear();
            }
        }
        else {
            token +=i;
        }
    }
    if(!token.empty()) {
        output.push_back(token);
    }
}

void    ExpressionMatch::__stringsToMap__       (vector<string> &expressionList, unordered_map< string,vector<string> > &expressionMap)
{
    for(string s:expressionList)
    {
        vector<string> tokens;
        __stringTokenize__(s,tokens);
        expressionMap[s] = tokens;
    }

}

void    ExpressionMatch::__insert__             (string expression, vector<string> &tokenExpression)
{

}

void    ExpressionMatch::__varParse__           (Node* current, int i, int depth, int size, vector<string> &tokenExpression)
{

}

void    ExpressionMatch::__varPraseMin__        (Node* current, int i, int depth, int size, vector<string> &tokenExpression)
{

}

void    ExpressionMatch::__varPraseMax__        (Node* current, int i, int depth, int size, vector<string> &tokenExpression)
{

}

void    ExpressionMatch::__printNode__          (Node* current)
{   
    if(current) {
        cout<<"\tWord:\t"<<current->word<<endl;
        cout<<"\tisVariable:\t"<<current->isVariable<<endl;
        cout<<"\tisLeaf:\t"<<current->isLeaf<<endl;
        cout<<"\tExpression:\t"<<current->expression<<endl;
        cout<<"\tChildren:\n\t{"<<endl;
        for(auto itr:current->children)
        {
            cout<<"\t\t"<<itr.first<<endl;
        }
        cout<<"\t}"<<endl;

    }

}

void    ExpressionMatch::printDFS               ()
{

}

void    ExpressionMatch::printBFS               ()
{

}

void    ExpressionMatch::insert                 (vector<string> expressionList)
{
    unordered_map< string,vector<string> > expressionMap;

    __stringsToMap__(expressionList,expressionMap);

    for(auto itr:expressionMap)
    {
        __insert__(itr.first,itr.second);
    }

}

string    ExpressionMatch::search               (string body)
{
    return "";
}

