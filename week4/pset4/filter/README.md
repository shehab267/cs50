## Pset 4: [Filter](https://cs50.harvard.edu/x/2021/psets/4/filter/less/)

In filter The task is to take a bitmap image and apply some number of different filters to that image, applying a filter to convert the image into _**Grayscale, Sepia, Reflect, Blur**._

### Background

#### Bitmaps

Perhaps the simplest way to represent an image is with a grid of pixels (i.e., dots), each of which can be of a different color. For black-and-white images, we thus need 1 bit per pixel, as 0 could represent black and 1 could represent white, as in the below.

![Alt text](https://cs50.harvard.edu/x/2021/psets/4/filter/less/bitmap.png)

In this sense, then, is an image just a bitmap (i.e., a map of bits). For more colorful images, you simply need more bits per pixel. A file format (like BMP, JPEG, or PNG) that supports “24-bit color” uses 24 bits per pixel. (BMP actually supports 1-, 4-, 8-, 16-, 24-, and 32-bit color.)

A 24-bit BMP uses 8 bits to signify the amount of red in a pixel’s color, 8 bits to signify the amount of green in a pixel’s color, and 8 bits to signify the amount of blue in a pixel’s color. If you’ve ever heard of RGB color.

If the R, G, and B values of some pixel in a BMP are, say, 0xff, 0x00, and 0x00 in hexadecimal, that pixel is purely red, as 0xff (otherwise known as 255 in decimal) implies “a lot of red,” while 0x00 and 0x00 imply “no green” and “no blue,” respectively.

### Specification

- The function `grayscale` should take an image and turn it into a black-and-white version of the same image.
- The function `sepia` should take an image and turn it into a sepia version of the same image.
- The `reflect` function should take an image and reflect it horizontally.
- Finally, the `blur` function should take an image and turn it into a box-blurred version of the same image.

### Usage

`$ ./filter -g infile.bmp outfile.bmp`
`$ ./filter -s infile.bmp outfile.bmp`
`$ ./filter -r infile.bmp outfile.bmp`
`$ ./filter -b infile.bmp outfile.bmp`
