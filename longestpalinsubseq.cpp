/* longest palindrome subseq

Find the longest subseq for a given string that is also a palindrome

logic: consider a string 

                s = a d b c e b a

    reverse of  s = a b e c b d a  

    LCS of above 2 strings = a b c b a

    this is the longest palindrome subseq!!

    DERIVATIVE PROBLEMS:

    1) how many chars to delete to make a string palindrome
    ANS: find the LCS len. s.size() - LCS len is the num of deletions!!

    2) how many chars to insert to make a string palindrome
    ANS: find the LCS len. s.size() - LCS len is the num of insertions!!
    WHY: num of deletions above is always equal to num of insertions.

    consider the same string 

                s = a d b c e b a

    reverse of  s = a b e c b d a 

    LCS between them is a b c b a

    we had to delete e and d from 's' to make it palindrome.

    s = a _d_ b c _e_ b a

    on the other hand, we can also insert letters so that singly occurring chars now have pairs. 
    in this case we need to insert matching chars for d and e i.e. 2 inserts which is also equal to
    num deletes!!

    s = a d b _e_ c e b _d_ a



*/

