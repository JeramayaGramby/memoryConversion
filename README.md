<br>

## This README file contains:
-Overview of the project <br>
-Use cases for the project<br>
-Project Weaknesses
-Project Photos<br><br>

## Project Overview
This lightweight data engineering project takes a numerical vector object and converts each value in the vector to the best bit representation. <br><br>

Converting numbers to their most efficient representation is very helpful for low-latency systems that require fast data conversion and manipulation methods. Efficient use of the CPU register ensures the lowest level of efficiency because every single bit of information is being processed in the most optimal way possible. <br><br>

If a 16 bit integer is fed into a 64 bit capacity CPU register, the register has to squeeze that 16 bits into the current register. If every other input is 64 bits, it means that the register has to create an entire new copy just to process the 16 bits AND THEN convert the 16 bit value to a 64 bit representation.<br><br> 

This is memory inefficient, and if that 16 bit value is not converted to a 64 bit representation, the program will incrementally add latency over many function calls and object instantiations. <br><br>

## Use Cases
This project can be used in its current form to take inputs from DLLs or the console, or can be built as a Python Module to complement a low latency data engineering pipeline. <br><br> 

## Project Weaknesses
This program only uses unsigned integers. Functionality will be shortly added to detect negative numbers and optimize the memory of the negative numbers<br><br>

## Project Photos <br><br>
