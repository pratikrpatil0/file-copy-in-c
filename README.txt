#-----------------------------------|
Edited By:- Pratik and Ishaan       |
Date:- 29/1/24                      |
#-----------------------------------|

---------------------------------------------------------------------------------------------------

==>  Assignment

This zip file contains a C program (my_copy.c) and a Bash script (error.sh) designed to 
create a copy of a given file. The C program allows users to specify input and output files 
through command-line arguments and handles various error scenarios.

Use "make" command before executing flame_cp

---------------------------------------------------------------------------------------------------

==>  Dependencies

Standard C library

Bash

POSIX-compliant system calls

mysql-server-core-8.0 package (perror command dependency)

---------------------------------------------------------------------------------------------------


==>  Building the Program

gcc -o flame_cp my_copy.c

---------------------------------------------------------------------------------------------------

==>  Usage

./flame_cp -i <source_file> -o <destination_file>

bash error.sh $?

---------------------------------------------------------------------------------------------------


==>  Alternative for errors

chmod +x error.sh

./error.sh $?

---------------------------------------------------------------------------------------------------


==>  Description

The Bash script (error.sh) interprets error codes returned by the C program and provides human-readable error messages.
$? - This captures the return value of the previous process. We pass it as an argument to the bash script. 

The alternative commands can be used because of the shebang line - #!/bin/bash.
chmod +x gives permission to make the file executable without having to explicitely use the bash command. 

---------------------------------------------------------------------------------------------------


==>  Error Codes

E_OK (0): "No errors"

E_WRONG_ARGNUMS (255): "Incorrect number of command-line arguments"

E_INVALID_ARGS (254): "Invalid command-line arguments"


---------------------------------------------------------------------------------------------------

==================================================================================================

@  Example 1

./flame_cp -i sample.sh -o "Assignment 1/Errors.sh"

chmod +x Errors.sh

./Errors.sh $?

==================================================================================================

@  Example 2

cat subassi2.c | ./flame_cp -i - -o new.c

bash Errors.sh $?

==================================================================================================
