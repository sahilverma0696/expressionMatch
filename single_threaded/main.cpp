#include"expressionMatchSingle.hpp"
#include<iostream>

int main()
{
    string variable = "{#*#}";
    string delimeter= " ,.-:";
    int    varLimit = 30;
    ExpressionMatch* regex = new ExpressionMatch(variable,delimeter,varLimit);

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

    string       body = "A quick brown fox jumps bla a lazy dog.";

   regex->insert(re);
   //regex->printDFS();
   //regex->printBFS();

   string result = regex->search(body);

   cout<<result;

    //regex->printDFS();


    return 0;

}