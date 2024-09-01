## Problem Statement
Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by different enemies. Abhimanyu is located in the innermost circle and has to cross all the 11 circles to reach Pandavas army back. 

* Each Circle Is Guarded By Different Enemy Where Enemy is Equipped With `k1, k2, k3, ... , k11` Powers.
* Abhmanyu start from the innermost circle with `p` power Abhimanyu has a boon to skip fighting enemy `a` times.
* Abhmanyu can recharge himself with power `b` times 
* Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. 
* If Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle.
* k3 and k7 enemies are endured with power to regenerate themselves once with half of their initial power and can attack Abhimanyu from behind if he is battling in iteratively next circle.

Return True If Abhimanyu Can Cross The Chakravyuh otherwise return False.

```
1) 1 <= Circle[i] <= 2000
2) 1 <= p <= 1000
3) 0 <= a, b <= 5
```

## TestCases
```
p = 150
a = 2
b = 2
Circle = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110];

Output - NO
```

```
p = 150
a = 1
b = 0
Circle = [110, 10, 20, 10, 10, 10, 10, 10, 20, 10, 10]

Output - YES
```

```
p = 100
a = 3
b = 4
Circle = [20, 10, 90, 20, 10, 50, 80, 30, 20, 50, 100]

Output - YES
```
