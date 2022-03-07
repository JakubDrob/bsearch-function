# bsearch-function in C

The function searches an array of num objects, the initial member of which is pointed to by b a se,
for a member that matches the object pointed to by key. The size of each member of the array is
specified by s i z e . The contents of the array should be in ascending sorted order according to the
comparison function referenced by compar. The compar routine is expected to have two arguments
which point to the key object and to an array member, in that order, and should return an integer
less than, equal to, or greater than zero if the key object is found, respectively, to be less than, to
match, or be greater than the array member. The b s e a r c h function returns a pointer to a matching
member of the array, or NULL if no match is found. If there are multiple elements that match the
key, the element returned is unspecified.

