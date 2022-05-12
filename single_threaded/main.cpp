#include"expressionMatchSingle.hpp"

int main()
{
    string variable = "{#*#}";
    string delimeter= " ,.-:";
    ExpressionMatch* regex = new ExpressionMatch(variable,delimeter);

}