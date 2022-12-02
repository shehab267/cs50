## Pset 2: [Readability](https://cs50.harvard.edu/x/2021/psets/2/readability/)

Implement a program that computes the approximate grade level needed to comprehend some text, per the below.

### Reading Levels

According to [Scholastic](https://www.scholastic.com/teachers/teaching-tools/collections/guided-reading-book-lists-for-every-level.html), E.B. White’s “Charlotte’s Web” is between a second and fourth grade reading level, and Lois Lowry’s “The Giver” is between an eighth grade reading level and a twelfth grade reading level. What does it mean, though, for a book to be at a “fourth grade reading level”?

So what sorts of traits are characteristic of higher reading levels? **_Well, longer words probably correlate with higher reading levels_**. Likewise, longer sentences probably correlate with higher reading levels, too. A number of “readability tests” have been developed over the years, to give a formulaic process for computing the reading level of a text.

One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output what (U.S.) grade level is needed to understand the text. The formula is: `index = 0.0588 * L - 0.296 * S - 15.8`
Here, `L` is the average number of letters per `100` words in the text, and `S` is the average number of sentences per `100 words in the text`.

```
$ ./readability
Text: When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.
295 letter(s)
70 word(s)
3 sentence(s)
```

### Specification

Design and implement a program, `readability`, that computes the Coleman-Liau index of the text.

- Program prompt the user for a `string` of text (using `get_string`).
- Program count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.

- Program should print as output "`Grade X`" where `X` is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
- If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "`Grade 16+`" instead of giving the exact index number. If the index number is less than 1, your program should output "`Before Grade 1`".

#### How to Test Your Code

- One fish. Two fish. Red fish. Blue fish. `(Before Grade 1)`
- `Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.` (Grade 5)
- `It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.` (Grade 10)
- `A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.` (Grade 16+)
