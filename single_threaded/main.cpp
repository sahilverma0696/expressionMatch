#include"expressionMatchSingle.hpp"
#include<iostream>
#include <fstream>

int main()
{

    string variable = "{#*#}";
    string delimeter= " ,.-:()";
    int    varLimit = 50;
    ExpressionMatch* regex = new ExpressionMatch(variable,delimeter,varLimit);

    /*
    string input = "is seven-layer cake only had six: layers.";
    vector<string> output;
    regex->__stringTokenize__(input,output);

    for(string s:output)
        cout<<s<<endl;

    */

    /*
    vector<string> re ={ "A quick brown fox jumps {#*#}",
                        "A quick brown fox sleeps.",
                        "A quick brown fox jumps {#*#} a {#*#} dog."};

    string       body = "A quick brown fox jumps bla a lazy dog.";
    
    regex->insert(re);
   //regex->printDFS();
    regex->printBFS();

    string result = regex->search(body);

    cout<<result;

    */

    
    vector<string> re;
    vector<string> bodies;

    ifstream reFile("../data/templates.txt");
    if (reFile.is_open()) {
        string line;
        while (getline(reFile, line))
            re.push_back(line);
        reFile.close();
    }

    regex->insert(re);
    //regex->printDFS();

    ifstream bodyFile("../data/bodies.txt");
    if (bodyFile.is_open()) {
        string line;
        while (getline(bodyFile, line))
            bodies.push_back(line);
        bodyFile.close();
    }


    string body = "Dear Parents Tomorrow (25th Sept,2015), there will be a holiday on account of Id-Ul-Zuha as per Government notification. Thanks. PRINCIPAL, Popular Sammrat School";
    cout<<regex->search(body);
    /*
    for(string body : bodies)
    {
        cout<<body<<"~";
        cout<<regex->search(body)<<"~";
        cout<<endl;
    }
    */



    return 0;

}