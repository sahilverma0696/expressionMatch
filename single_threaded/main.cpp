#include"expressionMatchSingle.hpp"
#include<iostream>
#include <fstream>

int main(int argc, char** argv)
{

    bool debug = false;
    bool test  = false;
    for(int i = 0; i < argc; i++)
        if(string(argv[i]) == "--debug")
            debug = true;
        else if(string(argv[i]) == "--test")
            test = true;
        

    string variable = "{#*#}";
    string delimeter= " ,.-:()/!\"\'";
    int    varLimit = 50;
    ExpressionMatch* regex = new ExpressionMatch(variable,delimeter,varLimit,debug);

    
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
    //regex->printBFS();

    ifstream bodyFile("../data/bodies.txt");
    if (bodyFile.is_open()) {
        string line;
        while (getline(bodyFile, line))
            bodies.push_back(line);
        bodyFile.close();
    }


    
    
    if(test)
    {
        for(string body : bodies)
        {
            cout<<body<<"~";
            cout<<regex->search(body)<<"~";
            cout<<endl;
        }
    }
    else
    {
        string body = "Dear Customer, we have received your acceptance of the OD Application Form cum T&C, Debit Mandate and SOC. Please complete your online application process for limit setup. T&C apply.";
        cout<<body<<endl;
        cout<<regex->search(body);
    }
    
    



    return 0;

}