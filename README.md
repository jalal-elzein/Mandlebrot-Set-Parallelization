# Mandelbrot Set Parallelization
This is a project that I made as part of my CSC447- Parallel Computing course at [LAU](https://www.lau.edu.lb). <br>
It follows a very simple method described in the .docx file section I-2-a, to parallelize the generation of an image of the [Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set).

# What technologies were used?
The code is entirely written in C++.<br>
The serial implementation is standard, while the parallelized implementation uses [MPICH](https://www.mpich.org/) for parallelization.<br>
The setup was ran on Ubuntu Server Virtual Machines (find more information on that in the [report](https://github.com/jalal-elzein/Mandlebrot-Set-Parallelization/blob/main/Report.docx) file!)

# What did I learn
- I learned how to create networks/clusters of virtual machines
- I learned how to use said networks to run code in parallel
- I learned how to generate images and use .ppm and .pgm images
