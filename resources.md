# FDF

## MLX42 Library

- [MLX Docs](https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md)
- [MLX Tutorial (small game example)](https://pulgamecanica.herokuapp.com/posts/mlx42-intro)

## Something about Isometric Projection -- Placing the dots from the map

[Isometric Projection in Game Development](https://pikuma.com/blog/isometric-projection-in-games)

[How Isometric Coordinates Work in 2D Games (video)](https://www.youtube.com/watch?v=04oQ2jOUjkU)


## Connecting the dots

Must use an algorithm. Some options are:

- DDA (Digital Differential Analyzer) Algorithm 
	- [Geeks for geeks article](https://www.geeksforgeeks.org/dda-line-generation-algorithm-computer-graphics/)
- Linear Interpolation
- Bresenham's line algorithm
	- [Article pages 11-13](https://zingl.github.io/Bresenham.pdf)

Use DDA if I want to use floating point arithmetics. Might be slow. !!! It doesn't handle vertical lines !!!
Use Bresenham's if using integer arithmetics. Fast. But I have my points as doubles. Can I have the points with only integer coordiates?

## Extra Resources, maybe useful

[Fundamental Math for Game Developers](https://pikuma.com/blog/math-for-game-developers)


## Calculators

[Wolfram alpha. Calculate the isometric transformation of a point](https://www.wolframalpha.com/input?i2d=true&i=%7B%7Bcos+%5C%2840%2930%5C%2841%29%2Ccos%5C%2840%2932%5C%2841%29%2Ccos%5C%2840%2928%5C%2841%29%7D%2C%7Bsin%5C%2840%2930%5C%2841%29%2Csin%5C%2840%2932%5C%2841%29%2Csin%5C%2840%2928%5C%2841%29%7D%7D%7B%7B4%7D%2C%7B2%7D%2C%7B0%7D%7D)

# Next Steps Checklist 

- [ ] Implement the line drawing algorithm. Figure out which one is better, and if it is even possible to do Bresenham.
- [ ] Decide how to find the pairs of points that need to be linked together.