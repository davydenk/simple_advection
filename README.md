# Simple advection simulator

This code performs a simple advection simulation in 1 dimention using the first order [upwind scheme](https://en.wikipedia.org/wiki/Upwind_scheme).

The doxygen documentation is provided. To view the .html version, open the ``documenation.html`` file in any browser. The doxygen file ``doxy.in`` is included in the root folder.

The current initial conditions functions available can be found the ``initial_conditions.hpp`` file. The default initial conditions function is the ``hat_function`` from this file. To switch to a different function, simply invoke the mesh constructor with its name.

## To compile and run

The project is written in c++, at the moment only using the c++11 standard. Currently the project only has header files and can be compiled with gcc with a simple one line command:

    g++ main.cpp -o advection.x -Iinclude

However, the [meson](https://mesonbuild.com/Manual.html) configuration file is also provided . To compile the project with meson, do: 

    meson build (in the top directory)
    cd build
    ninja

The default executable name is set to advection.x. The executable requires parameter files, the example of which can be found in the param_files folder. To run the program, do:

    ./advection.x PATH_TO_PARAM_FILE

For example, from the inside of the meson build folder you can run: 

    ./advection.x ../param_files/params_default.txt

The final output is printed to the ``result.txt`` file. The intermediate output files are written to the ``gif_dir`` folder with the names ``TIME_STEP.dat``.
Currently, the output is performed in text format, so it is not adviced to print too many steps.  

The example gnuplot script ``gif.gp`` to create a gif out of the results obtained by running with the default parameters file (from the ``param_files`` folder) together with the resulting gif are provided in the ``plots`` folder.

## Parameter files

The parameter files have a strict format that must be followed. 
    
1. The variables in the file must be in order:
   
    * domain_start
    * domain_end
    * equation coefficient
    * desired time_step
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
intermidiate output step: 0

```



