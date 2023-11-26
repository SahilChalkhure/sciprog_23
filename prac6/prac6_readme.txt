Week 6 Practical


Q1. Matrix Multiplication


For Step 1 to 5:

To Compile 

    gcc -o main main.c

To Run 

    ./main


In step6_main folder

main.c consists of the code where the matrices are initialized and printed.

matmult.c consists strictly of the function doing the multiplicaiton on the matrices.

    gcc -c main.c

    gcc -c matmult.c

    gcc -o  matmultc main.o matmult.o

    ./matmultc

OR

To Run 

    make clean

    make (This will compile the 2 files present in the folder creating an executable
	gcc -c main.c

    	gcc -c matmult.c

    	gcc -o  matmultc main.o matmult.o

	running the above commands automatically)
	
    ./matmultc