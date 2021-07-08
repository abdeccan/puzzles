/*
Length of shortest common supersequence

logic: 

s1: a g g t a b
s2: g x t x a y b

Find the LCS length between above strings and then 
    
    (s1.size() + s2.size() - LCS) 

will give the Length of shortest common supersequence!!
*/