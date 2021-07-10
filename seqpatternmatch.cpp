// Sequence pattern matching
//
// Given two strings 'pattern' and 's', check if s matches pattern.
//
// logic: find if the LCS length is equal to string size of pattern.
// since LCS length is always guaranteed to be less than or equal to
// shorter of 2 strings (in this case pattern is shorter string), we 
// can decide pattern match based on lcs len == string len (pattern)
// 