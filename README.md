# Knight's Tour Problem Solver<br />
This repository contains implementations of the Knight's Tour problem solver in both Java and C++. The Knight's Tour is a classic problem in chess theory where the goal is to find a sequence of moves by a knight on a chessboard such that the knight visits every square exactly once.<br />

## Java Implementation<br />
### Overview<br />
The Java implementation uses a backtracking algorithm to explore all possible paths on the chessboard until a solution is found or all paths have been exhausted.<br />

## C++ Implementation<br />
### Overview<br />
The C++ implementation also uses a backtracking approach to solve the Knight's Tour problem. It employs recursive functions and checks for all possible moves of the knight.<br />

### How to Run<br />
Simply select a starting point. Corners are usually the best option. Then compile `g++ maain.cpp` (C++) `javac Main.java` (Java) and execute! `./a.out` (C++) `java Main` (Java)<br />

## Sample Output<br />
Below is a sample output. Each number represents the move number that it took to get to that spot. In this sample we started at spot [0,0] (Top left corner.) <br />

&ensp;0 37 54 33  2 35 18 21<br />
53 46 &ensp;1 36 19 22  3 16<br />
38 55 32 45 34 17 20  9<br />
47 52 39 56 23 10 15  4<br />
58 31 44 51 40 25  8 11<br />
43 48 57 24 61 14  5 26<br />
30 59 50 41 28  7 12 63<br />
49 42 29 60 13 62 27  6<br />
