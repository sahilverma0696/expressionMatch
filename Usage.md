## Rules 

Sample string : A quick brown fox jumps over a lazy dog

## 1. Keep one variable atomic 

Since it can absorb multiple tokens, for bigger segments use ```varLimit```.
```
    Valid   : A quick {#*#} jumps ...
    Invalid : A quick {#*#} {#*#} jumps ...
```

## 2. Normalize the REs

The parser does not matches a fallback search option when a variable is present 
```
    Invalid : 
        RE :
            {#*#} fox jumps over a lazy dog
            A quick {#*#} dog jumps over a lazy dog
        Body :
            A quick 'brown' fox jumps over a lazy dog    
    'brown' being variable
```

```
    Valid : 
        RE :
            A quick {#*#} fox jumps over a lazy dog
            {#*#} fox jumps over a lazy dog
            A quick {#*#} dog jumps over a lazy dog
        Body :
            A quick 'brown' fox jumps over a lazy dog    
    'brown' being variable
```

## 3. Enter clean variables 

```
    Invalid:
        RE:
            A quick {#*#}fox jumps over a lazy dog
            A quick {#*#}, fox jumps over a lazy dog
```

```
    Valid:
        RE:
            A quick {#*#} fox jumps over a lazy dog
            A quick {#*#}, fox jumps over a lazy dog (use , as delimiter)
            A quick {#*#} , fox jumps over a lazy dog
```

## 4. Delimiter

It is safe to use more delimiters since they make more tokens to parse and better parsing,
But it's a tradeoff, since more tokens means more depth and more parsing.

## 5. Valid and Invalid variables

```
    Invalid:    
        A quick {#*#}, {#*#} jumps ....
        {#*#} delimiter {#*#}
```

```
    Valid:    
        A quick {#*#}, jumps ....
        {#*#} string {#*#}
```