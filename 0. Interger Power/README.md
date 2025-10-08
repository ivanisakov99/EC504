### <ins>Problem:</ins>
The file myPower.cpp has four different functions to compute an integer power of a real number. This includes the standard pow() routine in the C++ standard library. The first function is the highly-optimized pow() function in the standard library. The second function proceeds linearly through the iterations, and is O(n). The third and fourth functions use a divide-and-conquer approach to speed up computation and are O(ln(n)). The fourth function uses tricks such as shifts and bit reads to gain speedup.

Once you have the files somewhere in your directory, you can compile them with the makefile. The instruction is **make all** . This will compile the executable in the function **power**.
The next step is to run the function power and store the output in power.out. The command will be:

    power >> power.out

In some Linux systems, you may need to use the command as 
    
    ./power >> power.out 
    
This will run power and direct the output into a text file power.out.
