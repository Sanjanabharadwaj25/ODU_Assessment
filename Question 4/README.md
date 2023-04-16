Problem Statement : <br>
Given a string, find the length of the longest repeating subsequence, such that the two subsequences don’t have the same string character at the same position, i.e. any ith character in the two subsequences shouldn’t have the same index in the original string.
<br>

Example : aabbccdeff<br>
OUTPUT : 4<br>
* A subsequence has the same sequential ordering as the original string but it does not have to be substring of the string.
<br> In the above example, there are 16 possibilites of the longest repeating subsequence.<br>
* We can choose among the two a's,b's c's and f's.<br>
* 'e' and 'd' cannot be included as they appear only once and hence will have the same index in the original string.
