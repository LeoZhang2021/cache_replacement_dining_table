# They're Taking the Hobb... Dwarves... to Isenga... Bag End!


In Bag End, the home of Bilbo Baggins, an unexpected party is occurring. You see, Gandalf the Grey, wizard, wants Bilbo to go on an adventure. Something about stealing treasure from Benedict Cumberbatch. Anyway, Gandalf has  brought a group of very hungry dwarves. The table is not exactly designed for this many people (Bilbo lives alone) so things are packed a little bit tightly. There is a huge amount of food in the many pantries, but on the table, there is only a limited amount of space for dishes. When a dwarf wants a food item that's on the table, he can just have it. When a dwarf wants something that isn't on the table, Bilbo has to fetch it from one of the many pantries and serve it. If the table is full, he'll have to make room for it, by removing something that's already there. 

Bilbo will use the "least frequently used" replacement algorithm, taking away dishes that are unpopular and replacing them with ones that have been  requested. This means keeping track of what dishes are on the table and how often they have been requested. Because Gandalf is in attendance, he will use his magic so that no matter how many times the same dish is requested, it never runs out.

### Primary Objective 
The primary objective of this exercise is to practice using caching and cache replacement.

### Secondary Objective(s)
You will also get some more experience with C programming. You may also improve your ability to work with version control (git) and gitlab.

### Description of Behaviour
 The goal is to implement the program so that the following behaviour occurs:


 - The code takes the dish requests as standard input. If you invoke the program `./bagend` the program waits for your input -- you can enter dishes by typing numbers in and pressing enter, as many as you like. If you are finished with input then enter `-1` as that signals the end.
 - There are some test cases provided as `orderX.txt` where X is between 1 and 5. To use one of them (or your own test cases), invoke the program as `./bagend < order1.txt` . The `<` angle bracket redirects the content of the specified file to the program's standard input.
 - You should allocate, in `main` `TABLE_SIZE` platters and initialize them. The number of uses for the dish should start as -1 so the print routine works correctly. This means the table starts out empty.
 - The `serve_dishes()` function should run: it takes whatever the next dish number is with `get_next_dish_order()`. If the dish is found on the table, increment the number of uses. If not, replace the least frequently used dish on the table with the new one (and we start counting uses at 0 - so when a dish is requested for the first time it's put on the table and has a uses count of 0).
 - If there are multiple dishes tied for the lowest count, choose the dish furthest to the left (lowest index, closest to the kitchen!) to replace. 
 - After each dish request has been handled, the `print_state()` function must be called to show the current state. It prints in the format `( DISH [USES], DISH [USES]... )`. The number of the dish comes first, followed by the number of uses in square brackets afterwards -- so if you see 99 [5] it indicates dish 99 is on that platter and the uses count is 5. A dash and empty square brackets indicates that platter is unoccupied.
 - If a dish is taken off the table and brought back, its usage counter resets to 0.
 - If the next dish number is -1, that indicates the end -- there are no more orders and all the dwarves are full (finally!). 
 - Finally, print out the total number of times that the poor Hobbit had to go fetch a dish.


`
### Sample Output
 For the file `order1.txt`, here's a sample invocation of the program showing what the output will look like:

```
~ ./feast < order1.txt
(4 [0], - [], - [], - [], - [])
(4 [0], 5 [0], - [], - [], - [])
(4 [0], 5 [0], 1 [0], - [], - [])
(4 [0], 5 [0], 1 [0], 3 [0], - [])
(4 [0], 5 [1], 1 [0], 3 [0], - [])
(4 [0], 5 [2], 1 [0], 3 [0], - [])
(4 [0], 5 [2], 1 [0], 3 [1], - [])
(4 [1], 5 [2], 1 [0], 3 [1], - [])
(4 [2], 5 [2], 1 [0], 3 [1], - [])
(4 [2], 5 [2], 1 [0], 3 [1], 2 [0])
Bilbo had to fetch dishes 5 times using LFU.
```

### Test Cases 
For the provided 5 test cases, here are the expected LFU fetch counts.

| Input File | Fetch Count  |
|---|---|
| order1.txt | 5 |
|order2.txt | 19 |
|order3.txt | 42 |
|order4.txt | 67 |
|order5.txt | 144 |

