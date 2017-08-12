# fractals

This project creates colorful fractals designed to be interacted with through keyboard and mouse events. Like 3d_wireframe, it uses the minilibx library on top of OpenGL to plot images onto the screen. 

Mandelbrot:
<img width="1019" alt="screen shot 2017-08-11 at 6 22 18 pm" src="https://user-images.githubusercontent.com/13093517/29236636-0e8678dc-7ec2-11e7-968e-b9bb5dd52035.png">

Julia:
<img width="1022" alt="screen shot 2017-08-11 at 6 25 29 pm" src="https://user-images.githubusercontent.com/13093517/29236667-92f76234-7ec2-11e7-8fd0-84bb5b47e725.png">

Mandelbrot Cube:
<img width="1016" alt="screen shot 2017-08-11 at 6 27 32 pm" src="https://user-images.githubusercontent.com/13093517/29236682-f6deac30-7ec2-11e7-8814-657c0d9d3a3e.png">

Julia Cube:
<img width="1023" alt="screen shot 2017-08-11 at 6 31 16 pm" src="https://user-images.githubusercontent.com/13093517/29236698-4ba7b2ac-7ec3-11e7-8186-0cf07c2d0f6d.png">

## Key Details

The project utilized child processes and multithreading to maintain the fluidity of the program's output. On line 112 in *main*, a child procress is created via a successful fork. This child process proceeds to run through the rest of the program while the parent process completes the execution of *main*. Depending on whether the user wants to open more than one fractal at a time, the forking of a new process sits inside a while loop so multiple processes can be created if needed. 

<img width="439" alt="screen shot 2017-08-09 at 5 14 21 pm" src="https://user-images.githubusercontent.com/13093517/29236782-88f7b2d6-7ec5-11e7-8b1d-a9fe489ab7e8.png">

The next interesting detail is the environment initialization function. The returned environment struct pointer is the program's main data structure. On top of holding the dimensions and figures needed to calculate the graphical image, it also incoporates the data for connecting to the mlx graphics server in the minilibx directory. From lines 74 to 83 in *init_env*, the struct's varied pointers point to function calls within the source code directory and the minilibx library. For example, the pointers in lines 75 and 81 connect to the mlx functions that create both the window itself and the graphical image that spawns on top of it. Lines 78 to 80 initialize the other struct variables of the project as pointer members of the environment variable. These structs serve as component pieces to be modified from key and mouse events.

<img width="516" alt="screen shot 2017-08-09 at 5 15 24 pm" src="https://user-images.githubusercontent.com/13093517/29236943-8ca5bdda-7ec8-11e7-860e-de1a39a5e335.png">

The details to be examined next are in the the calling function *handle_colors* on line 78 above. This function matters as it's format served as a template for the other handlers in *init_env* and it's code demonstrates the coloring procedure as implied by the function's name.

<img width="453" alt="screen shot 2017-08-09 at 5 16 08 pm" src="https://user-images.githubusercontent.com/13093517/29237034-8b121336-7eca-11e7-9226-fa7116cc1e33.png">

After memory is allocated and set for the color struct pointer, it is then passed through 10 coloring functions in rapid and sequential order. Each coloring functions holds an integer array of 24 hard-coded hex values that are based on aesthetic color palettes. Through a simple whileloop, this array of hex values is transfered into the rgb member at an indexed position (9 in the example below) of the color struct pointer. The modular design of the coloring function below is replicated for all 10 coloring functions with the exception of the hex value array.

<img width="474" alt="screen shot 2017-08-09 at 5 16 23 pm" src="https://user-images.githubusercontent.com/13093517/29237091-a55233ce-7ecb-11e7-8685-78f29478822b.png">

Two other important members of the environment struct pointer are the function pointers to *reset_func* and *redraw_func*. These two members contain the project's multithreading aspect and image calculations. The *redraw_func* function in particular is worth exploring in depth.

<img width="482" alt="screen shot 2017-08-09 at 5 15 38 pm" src="https://user-images.githubusercontent.com/13093517/29237171-5b045aca-7ecd-11e7-82d3-0b578b7a97cf.png">

An array of type pthread_t is created on line 32 of *redraw_func*. The container stores the multiple threads that calculate the coordinates to be drawn. It is filled through a run of the while loop on line 35 before being terminated with the subsequent while loop on line 38. The rest of the function outputs the determined values and adjusts them after output has been accomplished. On line 36, *handle_threads* passes back each newly created pthread_t which contains data like the coloring and placement of each coordinate. These coordinates are found by running through all of the x and y values of the entire window and computing the math behind the correct output of each coordinate. The placement of each coordinate follows a simple formula inspired from this wonderful resource below:

http://lodev.org/cgtutor/juliamandelbrot.html 

An example of the math behind  one of the fractal types (the Mandelbrot set; shortened to simply *mand* in the function below) can be found in the following snippet:

<img width="548" alt="screen shot 2017-08-09 at 5 17 15 pm" src="https://user-images.githubusercontent.com/13093517/29237304-6d17e4f4-7ed0-11e7-84bb-e156507e85ef.png">

The data type double is used instead of interger due to the more precise nature of the type. The calculations to find the real and imaginary numbers are formulated around the midpoints of the image, the size of the image, and the complex number's relationship to the window size. (**Note**: the complex numbers for the julia types are based on the position of the horizontal and vertical values of the mouse instead of the midpoints The formula used to find the real and imaginary numbers for the mandelbrot types is instead used to find the x and y values for the julia types). Afterwards, a loop is run to calculate the new values of x and y. It is broken if the max number of iterations is exceeded or if the combined x and y values exceed a set limit. If the loop breaks from exceeding the set limit, valid coordinates have been found. The preceding function is returned the loop's index (*mand*'s index for this fractal example) and then passes the same index, environment variable, and the valid coordinates to *calculate_coordinate*. 

<img width="577" alt="screen shot 2017-08-11 at 8 55 48 pm" src="https://user-images.githubusercontent.com/13093517/29237654-833352f8-7ed7-11e7-9102-ce153c8aad1b.png">

Finally, with the coordinates and colors taken care of, *calculate_coordinate* combines the two primarily through modulus division on line 21. The calculation takes the index determined from the calculation above and adds it to a predetermined offset. This sum is then modulo by the sum total of colors which results in an index. This new index is stored in an integer array for later data processing and output. 

The remainder of this program includes key and mouse hooks that are behind the interactive elements of the project. Please refer to the User Interface in the **Features** section for an understanding of what these events can do.  

## Features

The following images are screenshots from exploring the fractals at varied depth and a screenshot of the user interface.

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
