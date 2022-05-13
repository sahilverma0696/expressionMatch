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
    Node* current = head;
    
    int     tokenSize = tokenExpression.size();
    for(int i = 0;i<tokenSize;i++)
    {
        string s = tokenExpression[i];
        if(current->children.count(s)>0)
        {
            current = current->children[s];
        }
        else
        {
            current->children[s] = new Node();
            current = current->children[s];

            current->word = s;
            if(s == variable)
            {
                current->isVariable = true;
            }
        }
    }
    current->isEnd = true;
    current->expression = expression;

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
        cout<<"\tisEnd:\t"<<current->isEnd<<endl;
        cout<<"\tExpression:\t"<<current->expression<<endl;
        cout<<"\tChildren:\n\t{"<<endl;
        for(auto itr:current->children)
        {
            cout<<"\t\t"<<itr.first<<endl;
        }
        cout<<"\t}"<<endl;

    }

}

void    ExpressionMatch::__printDFS__           (Node* current)
{
    if(current)
    {
        __printNode__(current);
        for(auto itr:current->children)
        {
            __printDFS__(itr.second);
        }
    }

}

void    ExpressionMatch::__printBFS__           (Node* current)
{
    list<Node*> q;

    q.push_back(current);

    while(!q.empty())
    {
        int size = q.size();
        list<Node*> level = q;
        __beautyBFS__(level);
        while(size--)
        {
            Node* curr = q.front();q.pop_front();
           // __printNode__(curr);
            for(auto itr:curr->children)
            {
                q.push_back(itr.second);
            }
        }
        //cout<<"\n\n\n";
    }

}


void    ExpressionMatch::__beautyBFS__(list<Node*> level)
{
    // Trust me not my best work, can be better made

    for(Node* current:level)
    {
        cout<<"\tWord:\t"<<current->word<<"\t\t";
    }
    cout<<"\n";

    for(Node* current:level)
    {
        cout<<"\tisVariable:\t"<<current->isVariable<<"\t\t";
    }
    cout<<"\n";

    for(Node* current:level)
    {
        cout<<"\tisEnd:\t"<<current->isEnd<<"\t\t";
    }
    cout<<"\n";

    for(Node* current:level)
    {
        cout<<"\tExpression:\t"<<current->expression<<"\t\t";
    }
    cout<<"\n\n\n";


}


void    ExpressionMatch::printDFS               ()
{
    Node* current = head;
    __printDFS__(current);

}

void    ExpressionMatch::printBFS               ()
{
    // needs work 
    // make internal func to print beautifully 
    Node* current = head;
    __printBFS__(current);
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

