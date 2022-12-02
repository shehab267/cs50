## Pset 2: [Caesar](https://cs50.harvard.edu/x/2021/psets/2/caesar/)

Implement a program that encrypts messages using Caesar’s cipher, per the below.

```
$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB
```
### Background
Supposedly, Caesar (yes, that Caesar) used to “encrypt” (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places.

More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by k positions. More formally, if p is some plaintext (i.e., an unencrypted message), pi is the ith character in p, and k is a secret key (i.e., a non-negative integer), then each letter, ci, in the ciphertext, c, is computed as

`ci = (pi + k) % 26`

###### write a program called `caesar` that enables you to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer.

### Specification
- program accept a single command-line argument, a non-negative integer. Let’s call it k for the sake of discussion.
- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
- If any of the characters of the command-line argument is not a decimal digit, your program should print the message Usage: ./caesar key and return from main a value of 1.
- Do not assume that k will be less than or equal to 26. Your program should work for all non-negative integral values of k less than 2^31 - 26. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for k that’s too big or almost too big to fit in an int. (Recall that an int can overflow.) But, even if k is greater than 26, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if k is 27, A should not become [ even though [ is 27 positions away from A in [ASCII](http://www.asciichart.com/), A should become B, since B is 27 positions away from A, provided you wrap around from Z to A.
- program output plaintext:

- program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext “rotated” by k positions; non-alphabetical characters should be outputted unchanged.
- program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.
- After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.

#### Testing Code 
```
$ ./caesar 13
plaintext:  be sure to drink your Ovaltine
ciphertext: or fher gb qevax lbhe Binygvar
```
