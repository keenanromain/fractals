# fractals

This project creates colorful fractals designed with interactive components based on different keyboard and mouse events. Like 3d_wireframe, it uses the minilibx library to plot images onto the screen. 

Mandelbrot:
<img width="1019" alt="screen shot 2017-08-11 at 6 22 18 pm" src="https://user-images.githubusercontent.com/13093517/29236636-0e8678dc-7ec2-11e7-968e-b9bb5dd52035.png">

Julia:
<img width="1022" alt="screen shot 2017-08-11 at 6 25 29 pm" src="https://user-images.githubusercontent.com/13093517/29236667-92f76234-7ec2-11e7-8fd0-84bb5b47e725.png">

Mandelbrot Cube:
<img width="1016" alt="screen shot 2017-08-11 at 6 27 32 pm" src="https://user-images.githubusercontent.com/13093517/29236682-f6deac30-7ec2-11e7-8814-657c0d9d3a3e.png">

Julia Cube:
<img width="1023" alt="screen shot 2017-08-11 at 6 31 16 pm" src="https://user-images.githubusercontent.com/13093517/29236698-4ba7b2ac-7ec3-11e7-8186-0cf07c2d0f6d.png">

## Key Details

The project was a great learning experience on child processes and multithreading as they are necessary to maintain the fluidity of the program. On line 112 in *main*, a child procress is created with a successful fork. From there, the child process runs the rest of the program while the parent process completes the execution of *main*. Depending on whether the user wants to open more than one fractal at a time, the forking for a new process sits inside a while loop so multiple processes can be created for each respective fractal. 

<img width="439" alt="screen shot 2017-08-09 at 5 14 21 pm" src="https://user-images.githubusercontent.com/13093517/29236782-88f7b2d6-7ec5-11e7-8b1d-a9fe489ab7e8.png">

The next interesting function is the environment initialization function. The environment struct pointer is the main struct pointer in the program and it holds the data needed for connecting to the mlx server in minilibx. From lines 74 to 83 in *init_env*, various pointers are set to function calls within this project and the minilibx library. For example, the pointers in lines 75 and 81 connect to the mlx functions required for creating both the window itself and the graphical image which spawns onto that window. Line 82 holds an integer array that stores data needed for later calculations. Lines 78 to 80 initiliaze the other struct pointers in this project for modification with the key and mouse hooks.

<img width="516" alt="screen shot 2017-08-09 at 5 15 24 pm" src="https://user-images.githubusercontent.com/13093517/29236943-8ca5bdda-7ec8-11e7-860e-de1a39a5e335.png">

In line 78 above, the called function *handle_colors* will be examined next. The format in this function serves as a template for the other handlers and demonstrates how the fractals are colored.

<img width="453" alt="screen shot 2017-08-09 at 5 16 08 pm" src="https://user-images.githubusercontent.com/13093517/29237034-8b121336-7eca-11e7-9226-fa7116cc1e33.png">

After memory is allocated and set for the t_color struct pointer, it is passed through 10 coloring functions. Each coloring functions holds an integer array of 24 hard-coded hex values that are based on pleasing color palettes found online. Through a loop, this array of hex values is then transfered into the rgb member at an indexed position (9 in the example below) of the t_color struct pointer. The format of the function below is replicated for all 10 coloring functions.

<img width="474" alt="screen shot 2017-08-09 at 5 16 23 pm" src="https://user-images.githubusercontent.com/13093517/29237091-a55233ce-7ecb-11e7-8685-78f29478822b.png">

Two other important members of the environment struct pointer are the function pointers to *reset_func* and *redraw_func*. These two members contain the project's multithreading aspect and many of it's calculations. The *redraw_func* function in particular is worth exploring in depth.

<img width="482" alt="screen shot 2017-08-09 at 5 15 38 pm" src="https://user-images.githubusercontent.com/13093517/29237171-5b045aca-7ecd-11e7-82d3-0b578b7a97cf.png">

An array of type pthread_t is created on line 32 of *redraw_func* which stores the threads that calculate the coordinates to be drawn. The array is filled in the running of the while loop on line 35 before being terminated in the following while loop on line 38. The rest of the function then outputs the determined values and resets them after the output has been accomplished. On line 36, *handle_threads* passes back each newly created pthread_t which holds the function ultimately responsible for the coloring and placement of each coordinate. These coordinates are found by running through all of the x and y values of the window and, depending on the type of fractal, computing the math needed to determine each coordinate. The placement of each coordinate follows a simple format inspired from this wonderful resource below:

http://lodev.org/cgtutor/juliamandelbrot.html 

An example of the math needed to create the Mandelbrot set (shortened to simply *mand* in the function below) can be found in this snippet:

<img width="548" alt="screen shot 2017-08-09 at 5 17 15 pm" src="https://user-images.githubusercontent.com/13093517/29237304-6d17e4f4-7ed0-11e7-84bb-e156507e85ef.png">

Doubles are used for more precise values and the real and imaginary doubles are based on the midpoints and the sizes of the window and image. Note: for the julia types the real and imaginary doubles are based on the position of the horizontal and vertical values of the mouse rather than the midpoints. From here, a loop is run which is broken if the max number of iterations is exceeded or if the x and y values combined exceed 4. This loop ideally breaks from the later condition as it would prove that we have valid coordinates worth placing. If the loop breaks from the second condition and we have valid coordinates, the calling function of the fractal calculation (*mand* in this instance) passes the index, environment struct pointer, and coordinates to *calculate_coordinate*. 

<img width="577" alt="screen shot 2017-08-11 at 8 55 48 pm" src="https://user-images.githubusercontent.com/13093517/29237654-833352f8-7ed7-11e7-9102-ce153c8aad1b.png">

Finally, with valid coordinates and a number of colors to choose from, *calculate_coordinate* determines the specific color for the given coordinates via modulus division on line 21. It may look complicated at first glance, but the calculation is simply the index determined from the fractal calculation above added to the predetermined offset. This sum is then modulo by the total number of colors which results in an index. This new index, j, is set as the color stored in the integer array responsible for viewing. The remainder of this program includes the key and mouse events that create the interactive elements of the program. Please refer to the User Interface in the **Features** section for an understanding of what these events can do.  

## Features

The following images are screenshots from exploring the fractals at varied depth. At the end of this section is an image of the user interface that showcases the features in full.

Mandelbrot zoomed with increased iterations:

<img width="1020" alt="screen shot 2017-08-11 at 6 35 47 pm" src="https://user-images.githubusercontent.com/13093517/29237472-a336a0c2-7ed3-11e7-9fd6-2f072c144ee5.png">

<img width="1023" alt="screen shot 2017-08-11 at 8 41 41 pm" src="https://user-images.githubusercontent.com/13093517/29237556-87d02388-7ed5-11e7-984b-f5b549f45827.png">

Julia zoomed with increased iterations:

<img width="1018" alt="screen shot 2017-08-11 at 8 14 04 pm" src="https://user-images.githubusercontent.com/13093517/29237496-32452fa4-7ed4-11e7-9826-ca8973b6950e.png">

<img width="1015" alt="screen shot 2017-08-11 at 8 36 57 pm" src="https://user-images.githubusercontent.com/13093517/29237533-deb02690-7ed4-11e7-8a5d-da9e4dee84ed.png">

Mandelbrot Cube zoomed with increased iterations:

<img width="1019" alt="screen shot 2017-08-11 at 8 17 06 pm" src="https://user-images.githubusercontent.com/13093517/29237503-6263feea-7ed4-11e7-98b5-68833ee1b3e3.png">

<img width="1019" alt="screen shot 2017-08-11 at 8 19 09 pm" src="https://user-images.githubusercontent.com/13093517/29237502-62629b18-7ed4-11e7-8e64-8db067e7cb96.png">

Julia Cube zoomed with increased iterations:

<img width="1019" alt="screen shot 2017-08-11 at 8 22 02 pm" src="https://user-images.githubusercontent.com/13093517/29237510-716d9b12-7ed4-11e7-8700-0d002b9c9466.png">

<img width="1020" alt="screen shot 2017-08-11 at 8 23 56 pm" src="https://user-images.githubusercontent.com/13093517/29237509-716bc012-7ed4-11e7-9ff2-b327f25a7676.png">

User Interface:

<img width="389" alt="screen shot 2017-08-11 at 9 47 19 pm" src="https://user-images.githubusercontent.com/13093517/29237987-baac444a-7ede-11e7-9004-b5805a65baed.png">

## Implementation

To run this project, clone this repo into your terminal and generate the executable via the make command.
```
git clone https://github.com/keenanromain/fractals.git
cd fractals
rm -rf libft
git clone https://github.com/keenanromain/libft.git
make
```
A successful make command will create an executable called 'fractol'. To see the proper usage, run this executable from the root directory of the cloned fractals repo like such:
```
./fractol
```
Choose one or a combination of your prefered fractal types to execute following the usage specifications.

## Acknowledgement
This project was developed at École 42 USA in Fremont, California.
