# Cpp-Basics-Course
This project for Faculty of Engineering, Ain Shams University at my 1st Electrical year
It is required to develop a program to do Matrix operations. The program use
a defined string format to represent the matrix in the user input and output
sections. For the following matrix:
the string representation of the Matrix is :
[10 2.13 3;-5 0 4;16.5 1 8]
In the program, the user enters a matrix in the defined string format then
asked to enter an operator from the following list:


| operator      | Meaning | Action Required from the Program     |
| :---        |    :----:   |          ---: |
| +      | Plus to another Matrix      | Reads from the user another matrix in the defined format, do the ADD operation and print the result in the same matrix format.|                                               result in the same matrix format.|
| -   | Minus to another Matrix        | Reads from the user another matrix in the defined format, do the SUB operation and print the result in the same matrix format.|
| ^   | Power | Reads from the user a positive integer number (x). Calculate the matrix to the power (x) and print the result in the same matrix format.|
| T | Transpose | No extra input is needed from the User. Calculate the transpose of the matrix and print the result in the same matrix format.|
| D | Determinant | No extra input is needed from the User. Calculate the Determinant value of the matrix and print the result value. |
| I | inverse | No extra input is needed from the User. Calculate the inverse of the matrix and print the result in the same matrix format.|
| / | Divide by another Matrix |Reads from the user another matrix in the defined format, do the Divide operation as Multiply between the first matrix and inverse of the second matrix and print the result in the same matrix format. |

## General Constraints:
<ol>
<li>User can input matrices of any size up to 100 x 100.</li>
<li>All values are of float data types.</li>
<li>Do not prompt user to enter anything , just read the input directly.</li>
<li>Any error in user input, the program should output the word “ERROR”
in uppercase letters and exits. List of Errors includes the following: 
  <ul>
    <li>Any missing or unexpected input in the entered string matrix.</li>
    <li>Invalid corresponding matrices size in +, -, * , / operators.</li>
    <li>Non square matrix in Inverse and Power operators.</li>
    <li>Non integer positive power in power operator.</li>
  </ul>
  </li>
  <li>Output should not include any extra white spaces or any extra texts
more than the results.</li> 
</ol>
