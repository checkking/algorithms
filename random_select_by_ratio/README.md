### random selection algorithm by ratio
#### Algorigthm:
if one configuration is as below:
```bash
A: 1
B: 2
C: 3
```
the sum of these three is 1 + 2 + 3 = 6, then we can generate a number [1, 6] randomly.

if a ~ [1, 2) then A <br/>
or if a ~ [2, 4) then B <br/>
or a ~ [4, 7) then C
