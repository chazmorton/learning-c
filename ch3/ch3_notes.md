# Ch. 3 Notes: Control Flow

### 3.6 Loops - Do-While

```
do
    statement
while (expression);
```
- The statement is executed, then the expression is evaluated.

### 3.7 Break and Continue

- The break statement provides an early from for, while, do, and switch. Causes the inner most loop or switch to be exited immediately.
- Continue statement is related to break. Causes the next iteration of the enclosing loop to begin. Applies only to loops, not to switch. 
```
for(int i = 0; i < n; i++) {
    if(a[i] < 0) /* skip negative elements */
        continue;
    ... /* do positive elements */
}
```

### 3.8 Goto and labels
- Most common use case is to abandon processing in some deeply nested structure, such as breaking out of two or more loops at once. 
```
    for(...)
        for(...) {
            ...
            if(disaster)
                goto error;
        }
error:
    /* clean up the mess */
```
- A label has the same form as a variable name, and is followed by a colon. It can be attached to any statement in the same function as the goto.
- Code involving goto can always be written without one.
- In general, goto statements are harder to understand and maintain than code without gotos.