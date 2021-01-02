# Project_WnCC
Project for the post of Convener of WnCC, IITB

### Question
2. Time Is All I Have
My friend executed a program many times and collected the time data. But she is unable to analyse it. The same input was used for 100 runs and the timing figures were appended to a file, named as [timestat](https://drive.google.com/file/d/1-f7EBKW43suwBTrrvaFjsFn4i70bH8Wb/view). For each run, time displays three times as shown below. 

real 0m6.153s
user 0m6.050s
sys 0m0.080s

Here m stands for minutes and s refers to seconds. So if “real 0m6.153s” means real time of program is 0 minutes 6.153 seconds. You have to process this string to get the numerical value of time.

Your task is to write a program that (a) reads in the timestat file, (b) processes real, user and sys time for each run and produces the following output. 
Number of runs : ......
Average Time statistics
real .............. user .................. sys .......................
Standard deviation of Time statistics
real .............. user .................. sys .......................
Number of runs within (average - standard deviation) to (average + standard deviation)
real .............. user .................. sys .......................

You have to print the number of runs (of each times) which lie within range average -standard deviation to average + standard deviation.
Suppose the average of real time is .270 and standard deviation is 0.020. so you have to print number of real times that are within range (0.250, 0.290) 

