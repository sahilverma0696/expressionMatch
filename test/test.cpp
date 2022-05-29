#include "../single_threaded/expressionMatchSingle.hpp"
#include<iostream>
#include <fstream>
#include <chrono>

using namespace std::chrono;

int main(int argc, char** argv)
{

    bool debug      = false;
    bool test       = false;
    bool benchmark  = false;

    if(string(argv[1]) == "--debug")
        debug = true;
    else if(string(argv[1]) == "--test")
        test = true;
    else if(string(argv[1]) == "--benchmark")
        benchmark = true;

        


    string variable = "{#*#}";
    string delimeter= " ,.-:()/!\"\'";
    int    varLimit = 50;
    ExpressionMatch* regex = new ExpressionMatch(variable,delimeter,varLimit,debug);

    
    vector<string> re;
    vector<string> bodies;


    string reFileHandle = string(argv[2]);
    ifstream reFile(reFileHandle);
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
        string fileHandle = string(argv[3]);
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
    else if(benchmark)
    {
        string fileHandle = string(argv[3]);
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
            string result;
            auto start = high_resolution_clock::now();
            result = regex->search(body);
            auto stop = high_resolution_clock::now();
            cout<<result<<"~";
            auto duration = duration_cast<microseconds>(stop - start);
            cout << duration.count() << endl;
        }
    }
    else
    {
        string body = "Dear Parent of Ritesh, Bank Manager - Axis Bank Chandni Chowk has advised parents to pay school fee of their wards by new currency notes only at their branch OR by cheque of any bank. Ignore if already paid. Inconvenience is regretted. Regards Popular Sammrat School";
        cout<<body<<endl;
        cout<<regex->search(body);
    }
    
    



    return 0;

}