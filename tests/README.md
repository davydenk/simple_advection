## Testing

The testing is not currently automatic.

To validate the code we use two test cases. The first one is trivial, simply running the code on the constant function (currently hardcoded to be 0.5). To compile and run this test, do:

     g++ test_constant.cpp -o test.x -I ../include
     ./test.x params_tests.txt


The second validation case works on a single harmonic. The "exact" solution of the already discrete problem (taking into account the dissipation) starting from the cosine function (that one can see in the ``initial_conditions.hpp`` file) has been calculated and encoded into the ``test_function`` in the ``test_functions.hpp`` file. Then the results are compared with a reasonable tolerance. To compile and run this test, do:

    g++ test_harmonic.cpp -o test.x -I ../include
    ./test.x params_tests.txt





 
