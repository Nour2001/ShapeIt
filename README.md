# ShapeIt
A program that uses Object oriented programming to allow the user to create a square, circle, or a triangle by just providing their coordinates 
/*
 Description: creates a hierarchy of a class that calculates simple geometry.
 Date: July 29, 2020
 Author: Nour Elgawish
 AU Student ID: 3480626
 Version: 1.0
 Copyright: 2020 Nour Elgawish
*/

/*
 DOCUMENTATION
 
 Program Purpose:
     This program uses the concept of inhertiance and class hierarchy to calculate the area, circumfrance, and bounding box of three shapes. The three shapes are a square, circle and a triangle and they all are objects from their corrosponding classes.
 
 Note: in Cygwin, main must return type int
 
  Classes: Point class, Shape class, Circle class, Square Class, Triangle Class
  
  Variables declared in the Point class:
  x - double - used to indicate the x coordinate of the (x,y) point;
  y - double - used to indicate the y coordinate of the (x,y) point;
  xcoordinate-double- used in the constructers to assign it to the value of x.
  ycoordinate-double- used in the constructers to assign it to the value of y.
 
  Variables declared in the Shape class:
  Only functions were declared.

 Variables declared in the Circle class:
  center - Point - is of type Point class and stores the point center of the circle
  radius - double - a variable to store the radius of the cirlce
  r - int - used in the constructor to assign it to the value of radius
  max_y - double - used to calculate the maximum y for the bounding box
  max_x - double - used to calculate the maximum x for the bounding box
  min_y - double - used to calculate the minimum y for the bounding box
  min_x - double - used to calculate the minimum x for the bounding box
 
 Variables declared in the Square class:
  p_1 - Point - is of type Point class and stores the first point of the square
  p_2 - Point - is of type Point class and stores the second point of the square
  p_3 - Point - is of type Point class and stores the third point of the square
  p_4 - Point - is of type Point class and stores the fourth point of the square
  p1 - Point - used in the constructor to assign it to the value of p_1
  p2 - Point - used in the constructor to assign it to the value of p_2
  p3 - Point - used in the constructor to assign it to the value of p_3
  p4 - Point - used in the constructor to assign it to the value of p_4
  s-double- to indicate the side length of the square
  maxy - double - used to calculate the maximum y for the bounding box
  maxx - double - used to calculate the maximum x for the bounding box
  miny - double - used to calculate the minimum y for the bounding box
  minx - double - used to calculate the minimum x for the bounding box

 
 Note: for the Triangle class I decided to just print out the values of premiter and area whatever it may be.
 
 Variables declared in the Triangle class:
  p_1 - Point - is of type Point class and stores the first point of the triangle
  p_2 - Point - is of type Point class and stores the second point of the triangle
  p_3 - Point - is of type Point class and stores the third point of the triangle
  p1 - Point - used in the constructor to assign it to the value of p_1
  p2 - Point - used in the constructor to assign it to the value of p_2
  p3 - Point - used in the constructor to assign it to the value of p_3
  area- double- to store the area of the triangle
  s1-double- to indicate the first side length of the triangle
  s2-double- to indicate the second side length of the triangle
  s3-double- to indicate the third side length of the triangle
  maxy - double - used to calculate the maximum y for the bounding box
  maxx - double - used to calculate the maximum x for the bounding box
  miny - double - used to calculate the minimum y for the bounding box
  minx - double - used to calculate the minimum x for the bounding box
  
 Variables declared in main:
      center - Point - an object made from the Point class to make an (x,y) coordinate specifically indicating center of the circle
      c_1 - Circle - an object made from the Circle class to get all the information about the c_1 object
      p_1 - Point - an object made from the Point class to make an (x,y) coordinate for the square shape
      p_2 - Point - an object made from the Point class to make an (x,y) coordinate for the square shape
      p_3 - Point - an object made from the Point class to make an (x,y) coordinate for the square shape
      p_4 - Point - an object made from the Point class to make an (x,y) coordinate for the square shape
      s_1 - Square - an object made from the Square class to get all the information about the s_1 object
      p_5 - Point - an object made from the Point class to make an (x,y) coordinate for the triangle shape
      p_6 - Point - an object made from the Point class to make an (x,y) coordinate for the triangle shape
      p_7 - Point - an object made from the Point class to make an (x,y) coordinate for the triangle shape
      t_1 - Triangle - an object made from the Triangle class to get all the information about the t_1 object
 
 */

/*
 TEST PLAN

 Normal case:
     >The program excutes properly and calculates the area and circumfrance of each shape
     >The coordinates that are given are valide ( not inf or nan )
     >The bounding box is calculated accordingly and correctly.
 
 Bad Data case (The coordinates given are not numbers)
     >The program will not excute since invalid data is given
     >There will be a compiler error
 
 Abnormal data (data given forms werid shapes (not square or triangle ) )
     >If the coordinates do not really create the shape desired, the program will still run
     >The numbers calculated are not going to be a true representitive of a square or
 
 Limits of the program
 >Instant of the class need to be made in main in order for correct program excution
 
 Discussion:
     The program will output correct values if valid coordinates are given
     If coordinates do not correctly describe a square, triangle values will still be calculated
     Main needs to have instants of the classes (objects) in order to create shapes
 
*/
