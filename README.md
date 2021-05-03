# Simple advection simulator

This code performs a simple advection simulation in 1 dimention using the first order [upwind scheme](https://en.wikipedia.org/wiki/Upwind_scheme).

The doxygen documentation is provided. To view the .html version, open the "documenation.html file in any browser. The doxygen file is included in the root folder.

## To compile and run

Currently the project only has header files and can be compiled with a simple one line comand:

    g++ main.cpp -o advection.x -Iinclude

However, the [meson](https://mesonbuild.com/Manual.html) configuration file is also provided . To compile the project with meson, do: 

    meson build (in the top directory)
    cd build
    ninja

The default executable name is set to advection.x. The executable requires parameter files, the example of which provided in the param_files folder. To run the program, do:

    ./advection.x PATH_TO_PARAM_FILE

For example the inside the build folder you can run: 

    ./advection.x ../param_files/params_default.txt

The final output is printed to the "result.txt" file. The intermidiate output files are written to the "gif_dir" folder with the names "TIME_STEP.dat".
Currently, the output is performed in text format, so it is not adviced to print too many steps.  

## Parameter files

The parameter files have a strict format that must be followed. 
    
1. The variables in the file must be in order:
   
    * domain_start
    * domain_end
    * equation coefficient
    * diresed time_step
    * desired intermidiate output interval (0 for no intermidiate output)
    
2. each variable must follow the ":" symbol.The space before the ":" is best used for the variable name (and possible comments about it).

The example of a valid parameter file is:

```
domain start coordinate: 0.0
domain end coordinate: 1000.0
equation coefficient: 1.0
time step: 0.1
number of time steps: 100000
number of cells: 1000
intermidiate output step: 0``
```



