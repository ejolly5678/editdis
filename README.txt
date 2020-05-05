Elizabeth Jolly
This was created for a class. Because of that all references to the class have been removed. 

Spring 2020
Objective:   efficiently calculate the edit distance between pairs of words. 
A word is defined to be a maximal sequence of letters from upper and lower case 'a' to 'z'. 

To Run: 
compile: 
make
Run:
./editdis < lovely.txt
./editdis < computer.txt

Sample Input: 
lovely
2
0 1 1 1
You have always been
my love my love, for the
love I love is lovely
as love itself.  Love? 
did you hang up?

How many "loves" in this text?

Sample output:
lovely
2
0 1 1 1
You have always been
my (love) my (love), for the
(love) I (love) is (lovely)
as (love) itself.  (Love)? 
did you hang up?

How many "(loves)" in this text?

Known bugs:
extra spaces when it prints
