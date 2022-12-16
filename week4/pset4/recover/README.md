## Pset 4: [Recover](https://cs50.harvard.edu/x/2021/psets/4/recover/)

in recover pset, Write a program to recover deleted images in a memory card from a camera, generating a new JPEG files for each.

### TODO

- open memory card.
- Look for beginning of a JPEG
- open a new JPEG file
- write 512 bytes until JPEG is found
- end the old one and start a new one

### Background


Even though JPEGs are more complicated than BMPs, JPEGs have “signatures,” patterns of bytes that can distinguish them from other file formats. Specifically, the first three bytes of JPEGs are

from first byte to third byte, left to right. The fourth byte, meanwhile, is either `0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, or 0xef.` Put another way, the fourth byte’s first four bits are 1110.

### Usage

```
$ ./recover
Usage: ./recover image
```
 `$ ./recover card.raw`