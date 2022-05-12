# expressionMatchThere are times when one RE can abosrb another RE.
For e.g.,
1. A quick brown fox jumps {#*#}
2. A quick brown fox jumps {#*#} a {#*#} dog.

now since there is functional requirement for both of the RE, one cannot be deleted.
But beacuse of RE1 RE2 can be absorbed.
So, try to find out an optmized way to get the best RE match for a given sentence.

v1: assume {#*#} limit to be 30 chars
v2: {#var#} can have unlimited lenght 

{#*#} consider as * -> multiple chars 
{#?#} consider as ? -> one chars


Input 
1. List of REs 
2. Input String 

Output
Best RE match or Empty str


v1  string and variable matching 
v2  variable class diff
v3  single vs multichar variable difference 
v4  multithreaded
