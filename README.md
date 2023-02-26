# Mandelbrot Set Parallelization
This is a project that I made as part of my CSC447- Parallel Computing course at [LAU](https://www.lau.edu.lb). <br>
It follows a very simple method described in the .docx file section I-2-a, to parallelize the generation of an image of the [Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set).

# What's in this repo?
| File Name | Description |
| --------- | ----------- |
| README.md | you're reading it :p |
| Report.docx | The document I submitted to my professor. It contains almost everything you need to know about this project |
| mandelbrot8.ppm | The output image of a parallelized generation of the Mandelbrot Set |
| serialMandelbrot.cpp | Source code for running the serial implementation of the Mandelbrot Set generator |
| serial_mandelbrot.ppm | The output image of a serial generation of the Mandelbrot Set |
| staticmandelbrot.cpp | The parallelized implementation of generating an image of the Mandelbrot Set with Static Task Assignment |

# What technologies were used?
The code is entirely written in C++.<br>
The serial implementation is standard, while the parallelized implementation uses [MPICH](https://www.mpich.org/) for parallelization.<br>
The setup was ran on Ubuntu Server Virtual Machines (find more information on that in the [report](https://github.com/jalal-elzein/Mandlebrot-Set-Parallelization/blob/main/Report.docx) file!)

# What did I learn
- I learned how to create networks/clusters of virtual machines
- I learned how to use said networks to run code in parallel
- I learned how to generate images and use .ppm and .pgm images
