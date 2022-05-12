#include"expressionMatchSingle.hpp"
#include<iostream>

int main()
{
    string variable = "{#*#}";
    string delimeter= " ,.-:";
    ExpressionMatch* regex = new ExpressionMatch(variable,delimeter);

    /*
    string input = "is seven-layer cake only had six: layers.";
    vector<string> output;
    regex->__stringTokenize__(input,output);

    for(string s:output)
        cout<<s<<endl;

    */

   regex->__printNode__();

    return 0;

}