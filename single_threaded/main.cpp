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

   vector<string> re ={ "A quick brown fox jumps {#*#}",
                        "A quick brown fox sleeps.",
                        "A quick brown fox jumps {#*#} a {#*#} dog."};

   regex->insert(re);
   regex->printDFS();
   //regex->printBFS();

    return 0;

}