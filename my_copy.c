/*-----------------------------------|
Edited By:- Pratik and Ishaan       |
Date:- 29/1/24                      |
#----------------------------------*/



#include <stdio.h> /* input output manipulation */
#include <string.h> /* manipulation of strings */
#include <unistd.h> /* system calls, file I/O, and process management. 
Commonly used functions include read, write, close, fork and exec */
#include <fcntl.h> /*  various file control operations.
 O_RDONLY, O_WRONLY, O_CREAT, and O_EXCL are defined here for use in the 
 open function*/
#include <errno.h> /* returning the error codes */


 

#define E_OK 			     0
#define E_WRONG_ARGNUMS 	255
#define E_INVALID_ARGS 		254


int main(int argc, char *argv[]) {
  int ec = E_OK;

  // Check if the number of command-line arguments is correct
  if (argc == 5) {
    int source_fd = 0; // Default source file descriptor (stdin)
    int dest_fd = 1;   // Default destination file descriptor (stdout)
    char source[500] = "";
    char dest[500] = "";
    char data[1];
    int read_status;
    int write_status;

    // Parse command-line arguments
    for (int i = 1; i < 4; i = i + 2) {
      if (strcmp(argv[i], "-i") == 0) {
        strcat(source, argv[i + 1]);
        if (strcmp(source, "-") != 0) {
          // Open the source file for reading
          source_fd = open(source, O_RDONLY);
          if (source_fd == -1) {
            ec = errno;
            return ec;
          }
        }
      } else if (strcmp(argv[i], "-o") == 0) {
        strcat(dest, argv[i + 1]);
        if (strcmp(dest, "-") != 0) {
          // Creates and Opens the destination file
          dest_fd = open(dest, O_CREAT | O_WRONLY | O_EXCL, S_IRWXU | S_IRGRP);
          if (dest_fd == -1) {
            ec = errno;
            return ec;
          }
        }
      }
    }

    // Check if both source and destination files are specified
    if (strcmp(source, "") != 0 && strcmp(dest, "") != 0) {
  
      // Copy data from source to destination
      while ((read_status = read(source_fd, data, 1)) > 0) {
        write_status = write(dest_fd, data, 1);
        if (write_status == -1) {
          ec = errno;
          // Close file descriptors
          close(source_fd);
          close(dest_fd);
          return ec;
        }
      }

      if (read_status == -1) {
        ec = errno;
        // Close file descriptors
        close(source_fd);
        close(dest_fd);
        return ec;
      }

      // Close file descriptors
      close(source_fd);
      close(dest_fd);
    } else {
      ec = E_INVALID_ARGS;
      return ec;
    }
  } else {
    ec = E_WRONG_ARGNUMS;
    return ec;
  }

  return ec;
}
