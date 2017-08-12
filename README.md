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

The project was a great learning experience for creating child processes and multiple threads. These were necessary components to maintain the fluidity of the program. On line 112 in main, a child procress is created with a successful fork. From there, the child process executes the rest of the program while the parent process remains in main. Depending on whether the user wants to open more than one fractal at a time, the forking sits inside a while loop so multiple processes can be created for each respective fractal. 

<img width="439" alt="screen shot 2017-08-09 at 5 14 21 pm" src="https://user-images.githubusercontent.com/13093517/29236782-88f7b2d6-7ec5-11e7-8b1d-a9fe489ab7e8.png">

The next interesting function is the initialization of the environment struct pointer. It is the main struct pointer in the program and it holds the data needed for connecting to the mlx server in minilibx. From lines 74 to 83 in 'init_env', various pointers are set to functions within this project and the minilibx library. For example, the pointers in lines 75 and 81 connect to the mlx functions required for creating both the window itself and the graphical image which spawns onto that window. Line 82 holds an integer array that stores data needed for later calculations. Lines 78 to 80 initiliaze the other struct pointers in this project that are to be modified with key and mouse hooks.

<img width="516" alt="screen shot 2017-08-09 at 5 15 24 pm" src="https://user-images.githubusercontent.com/13093517/29236943-8ca5bdda-7ec8-11e7-860e-de1a39a5e335.png">


## Implementation

## Acknowledgement
This project was developed at École 42 USA in Fremont, California.
