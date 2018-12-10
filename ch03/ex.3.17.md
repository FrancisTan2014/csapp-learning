# Practice Problem 3.17 (solution page 331)
An alternate rule for translating if statements into goto code is as follows:
```c
  t = test-expr;
  if (t)
  	goto true;
  else-statement
  goto done;
true:
  then-statement
done:
```

- A. Rewrite the goto version of absdiff_se based on this alternate rule.
- B. Can you think of any reasons for choosing one rule over the other?

## My answer
- A. 
```c
long gotodiff_se(long x, long y)
{
    long result;
    if (x < y) 
        goto True;
    ge_cnt++;
    result = x - y;
    goto Done;
True:
    lt_cnt++;
    result = y - x;
Done:
    return result
}
```

## Solution from the book
- A. Converting to this alternate form involves only switching around a few lines of the code:
```c
long gotodiff_se_alt(long x, long y) {
	long result;
	if (x < y)
	  goto x_lt_y;
	ge_cnt++;
	result = x - y;
	return result;
x_lt_y:
	lt_cnt++;
	result = y - x;
	return result;
}
```

- B. In most respects, the choice is arbitrary. But the original rule works better for the common case where there is no else statement. For this case, we can simply modify the translation rule to be as follows:
```c
	t = test-expr;
	if (!t)
	  goto done;
then-statement
done:
```
  A translation based on the alternate rule is more cumbersome.