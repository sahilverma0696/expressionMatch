# expressionMatch

There are times when one RE can abosrb another RE.
For e.g.,
```
RE1: A quick brown fox jumps {#*#}
RE2: A quick brown fox jumps {#*#} a {#*#} dog.
```

Now since there is functional requirement for both of the RE, one cannot be deleted.
But beacuse of RE1 RE2 can be absorbed.


So, try to find out an optmized way to get the best RE match for a given sentence.

- v1  string and variable matching 
- v2  variable class diff
- v3  single vs multichar variable difference 
- v4  multithreaded

```
{#*#} consider as * -> multiple chars 
{#?#} consider as ? -> one chars
```

Input 
1. List of REs 
2. Input String 

Output
Best RE match or Empty str


```
cd Single_threaded
make 
```
Currently output will go in `log.txt`

