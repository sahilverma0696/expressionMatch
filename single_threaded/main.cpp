#include"expressionMatchSingle.hpp"
#include<iostream>
#include <fstream>

int main(int argc, char** argv)
{

    bool debug = false;
    bool test  = false;

    if(string(argv[1]) == "--debug")
        debug = true;
    else if(string(argv[1]) == "--test")
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

    


    
    
    if(test)
    {
        string fileHandle = string(argv[2]);
        ifstream bodyFile(fileHandle);
        if (bodyFile.is_open()) {
            string line;
            while (getline(bodyFile, line))
                bodies.push_back(line);
            bodyFile.close();
        }
        for(string body : bodies)
        {
            cout<<body<<"~";
            cout<<regex->search(body)<<"~";
            cout<<endl;
        }
    }
    else
    {
        string body = "";
        cout<<body<<endl;
        cout<<regex->search(body);
    }
    
    



    return 0;

}