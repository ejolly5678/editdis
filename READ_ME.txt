Elizabeth Jolly
This was created for a class. Because of that all references to the class have been removed
Spring 2020
Objective:  Use a dynamic programming algorithm to efficiently calculate the edit distance between pairs of words. 
A word is defined to be a maximal sequence of letters from upper and lower case 'a' to 'z'. 

To Run: 
compile: 
make
Run:
./editdis < input.txt

The recurrence equation for the solution that you are implementing, including initial conditions:
base case if theyre equal would be n(1) because it just has to comare the two words
if theyre not equal it would be O(n) because when they get compared they go through a loop
in the function process_word once. 

Known bugs:
extra spaces when it prints