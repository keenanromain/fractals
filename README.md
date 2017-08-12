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

Fractals was a great learning experience with regards to creating child processes and multiple threads. These were necessary components to maintain the fluidity of the program. In 'main', I create a child procress in 112 on successful forking. From there, the child process executes the rest of the program while the parent executes the remaining code in 'main'. Depending on whether the user wants to open more than one fractal at a time, the forking lies within a loop so multiple child processes can be created for each respective fractal. 

<img width="439" alt="screen shot 2017-08-09 at 5 14 21 pm" src="https://user-images.githubusercontent.com/13093517/29236782-88f7b2d6-7ec5-11e7-8b1d-a9fe489ab7e8.png">

## Implementation

## Acknowledgement
This project was developed at École 42 USA in Fremont, California.
