## HW 2

 - Name: Wing Nie
 - Email: wcnie@usc.edu

### Programming Problem Notes

 - To Compile Code: make all, ./amazon database.txt

 - In this programming assignment, I worked to model a simplified version of Amazon. 
   I worked to create some code that would read in a database of products from certain
   categories as well as the users and their information. The program allowed for
   the user to search for products, add them to their carts, view their carts, and 
   buy them.

 - Firstly, I implemented functions that would allow for the use of AND and OR in the search.
   I created an setIntersection and setUnion function to do this. These functions continuously 
   either intersected or unioned with each other to return an appropriate list of corresponding 
   products. 

 - After that, I wrote derived product classes to handle the different types of products the user
   can add to their carts. These were the: Book, Clothing, and Movie products. Each of these
   classes a few functions, and were similarly written.
