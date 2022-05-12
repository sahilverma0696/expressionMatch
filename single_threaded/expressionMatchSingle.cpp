#include "expressionMatchSingle.hpp"


ExpressionMatch::ExpressionMatch    (string varExpression, string delimeters)
{
    head                = new Node();
    this->variable      = varExpression;
    this->delimeters    = delimeters;
    dictSize            = 256;

}

