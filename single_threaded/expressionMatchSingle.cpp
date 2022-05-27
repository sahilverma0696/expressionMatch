#include "expressionMatchSingle.hpp"


ExpressionMatch::ExpressionMatch    (string varExpression, string delimeters,int varLimit = 100)
{
    head                = new Node();
    this->variable      = varExpression;
    this->delimeters    = delimeters;
    dictSize            = 256;
    this->varLimit      = varLimit;      

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
    if(current)
    {
        __varParseMin__(current,i,depth,size,tokenExpression);
        __varParseMax__(current,i,depth,size,tokenExpression);
    }

}

void    ExpressionMatch::__varParseMin__        (Node* current, int i, int depth, int size, vector<string> &tokenExpression)
{
    if(!current)
        return;

    if(current->isEnd)
    {
        pair<int,string> p;
        p = make_pair(depth,current->expression);
        resultHeap.push(p);
        return;
    }

    int     varCounter = 0;

    if(current->children[variable])
    {
        current = current->children[variable];
    }
    else
    {
        // no valid path
        return;
    }

   // __printNode__(current);
    while(current && current->children.count(tokenExpression[i])==0 && i < size && varCounter <varLimit)
    {
        // multiple var continiously
        if(current->children[variable])
            break;
        
        varCounter +=tokenExpression[i].size();
        i++;
        
    }
    depth++;

    if(current && current->isEnd)
    {
        pair<int,string> p;
        p = make_pair(depth,current->expression);
        resultHeap.push(p);
        if(i==size-1)
            return;
    }

    if(current && current->children[variable])
    {
        __varParse__(current,i,depth,size,tokenExpression);
    }

    if(current && ((current->children.count(tokenExpression[i])>0 && i>size) || !current->children.count(tokenExpression[i])))
    {
        // no path
        return;
    }

    if(current && current->children.count(tokenExpression[i])>0)
    {
        __wordPrase__(current,i,depth,size,tokenExpression);
    }

}

void    ExpressionMatch::__varParseMax__        (Node* current, int i, int depth, int size, vector<string> &tokenExpression)
{
    if(!current)
        return;

    if(current->isEnd)
    {
        pair<int,string> p;
        p = make_pair(depth,current->expression);
        resultHeap.push(p);
        return;
    }
    else
    {
        // No path
        return;
    }

    int     varCounter = 0;


    if(current->children[variable])
    {
        current = current->children[variable];
    }

    while(i < size && varCounter <varLimit)
    {
        // multiple var continiously
        if(current->children[variable])
            break;
        
        varCounter +=tokenExpression[i].size();
        i++;
        
    }
    depth++;

    if(current && current->isEnd)
    {
        pair<int,string> p;
        p = make_pair(depth,current->expression);
        resultHeap.push(p);
        if(i==size-1)
            return;
    }

    if(current && current->children[variable])
    {
        __varParse__(current,i,depth,size,tokenExpression);
    }

    if(current && ((current->children.count(tokenExpression[i])>0 && i>size) || !current->children.count(tokenExpression[i])))
    {
        // no path
        return;

    }

    if(current && current->children.count(tokenExpression[i])>0)
    {
        __wordPrase__(current,i,depth,size,tokenExpression);
    }

}

void    ExpressionMatch::__wordPrase__        (Node* current, int i, int depth, int size, vector<string> &tokenExpression)
{
    if(!current)
        return;
    if(current->isEnd)
    {
        pair<int,string> p;
        p = make_pair(depth,current->expression);
        resultHeap.push(p);
        if(i==size-1)
            return;
    }

    while(current->children[tokenExpression[i]])
    {
        current = current->children[tokenExpression[i]];
        depth++;
        i++;
    }

    if(current->isEnd)
    {
        pair<int,string> p;
        p = make_pair(depth,current->expression);
        resultHeap.push(p);
        if(i==size-1)
            return;
    }

    __varParse__(current,i,depth,size,tokenExpression);

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
            cout<<"\t\t"<<itr.first<<"\t";
            bool flag = itr.second?true:false;
            cout<<flag<<endl;
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
    Node*           current         = head;
    vector<string>  bodyToken;

    __stringTokenize__(body,bodyToken);


    int             bodyTokenSize   = bodyToken.size();
    int             i               = 0;
    int             depth           = 0;

    if(current->isEnd)
    {
        pair<int,string> p;
        p = make_pair(depth,current->expression);
        resultHeap.push(p);    
    }  

    if(current->isVariable)
    {
        __varParse__(current,i,depth,bodyTokenSize,bodyToken);
    }
    else
    {
        __wordPrase__(current,i,depth,bodyTokenSize,bodyToken);
    }

    string resultStr = resultHeap.empty() ? "NIL":resultHeap.top().second;

    while(!resultHeap.empty())
    {
        resultHeap.pop();
    }
    return resultStr;
}

