//TMA3Question3.cpp
/*
 Title:TMA3Question3.cpp
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

 Compile (assuming Cygwin is running): g++ -o TMA3Question3 TMA3Question3.cpp
 Execution (assuming Cygwin is running): ./TMA3Question3.exe
 
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
#include <iostream>
#include <cmath>

using namespace std;

class Point{

public:
    double x;
    double y;
    Point() {
        x=0;
        y=0;
    }

   Point (double xcoordinate, double ycoordinate){
        x = xcoordinate;
        y = ycoordinate;
        
    }
   
    Point operator + (Point& rhs){
        Point new_point;
        new_point.x= x + rhs.x;
        new_point.y= y + rhs.y;
        return new_point;
    }
    ~Point(){};
    
    Point operator - (Point& rhs){
           Point new_point;
           new_point.x= x - rhs.x;
           new_point.y= y - rhs.y;
           return new_point;
       }
   
    friend ostream& operator << (ostream& show, Point& p){
         show <<"x-coordinate :" << p.x << endl;
         show << "y-coordinate :" << p.y << endl;
         return show;
     }
};

class Shape{
public:
    Shape(){
    }
    ~Shape(){};
void area();
void circumference();
void display();
void boundingbox();
 
};

class Circle : public Shape{
   
private:
    Point center;
    double radius;
public:
    Circle(){
        
    }
    
    Circle(Point& p_1, int r ){
        center= p_1;
        radius= r;
    }
    ~Circle(){};
    
    void area(){
        cout << "The area of the circle is "<<  M_PI * pow(radius,2)<<endl;
    }

    void  circumference(){
        
        cout << "The circumference of the circle is "<<M_PI * 2 * radius<<endl;
    }
    
    void boundingbox(){
        double max_y;
        double max_x;
        double min_y;
        double min_x;
        max_y = center.y + radius;
        min_y = center.y - radius;
        max_x = center.x + radius;
        min_x = center.x - radius;
     
        cout<<"The maximum y-coordinate of the bounding box is: "<< max_y<<endl;
        cout<< "The minimum y-coordinate of the bounding box is: "<<min_y<<endl;
        cout<<"The maximum x-coordinate of the bounding box is: " <<max_x<<endl;
        cout<<"The minimum y-coordinate of the bounding box is: "<<min_x<<endl;

    }

    void display(){
        cout<< "This is the Circle class."<<endl;
        area();
        circumference();
        boundingbox();
      
    }
};

class Square : public Shape{

private:
    Point p_1;
    Point p_2;
    Point p_3;
    Point p_4;
   
public:
    Square(){
    
    }
   Square(Point& p1, Point& p2, Point& p3, Point& p4){
       p_1 = p1;
       p_2 = p2;
       p_3 = p3;
       p_4 = p4;
   }
    ~Square(){};
   void  area(){
       double s = sqrt(pow((p_1.x - p_2.x), 2) + pow( (p_1.y - p_2.y), 2));
       cout << "The area of the square is "<< pow(s, 2)<<endl;
   }
   void circumference(){
       double s = sqrt(pow((p_1.x - p_2.x), 2) + pow( (p_1.y - p_2.y), 2));
       cout << "The circumference (perimeter) of the square is "<< (s * 4) <<endl;
   }
    void max_y(){
        double maxy;
            maxy = p_1.y;
            if( p_2.y >= maxy ){
                maxy= p_2.y;
                }
        if ( p_3.y >= maxy){
                   maxy= p_3.y;
                    }
        if (p_4.y >= maxy){
              maxy = p_4.y;
            }
         cout<< "The maximum y-coordinate of the bounding box is: "<<maxy<<endl;
    }
    void max_x(){
        double maxx;
        maxx = p_1.x;
        if( p_2.x >= maxx ){
            maxx= p_2.x;
        }
        if ( p_3.x >= maxx){
           maxx= p_3.x;
        }
        if(p_4.x >= maxx){
            maxx = p_4.x;
        }
         cout<< "The maximum x-coordinate of the bounding box is: "<< maxx<<endl;
    }
    void min_y(){
         double miny;
        miny = p_1.y;
        if( p_2.y <= miny ){
            miny= p_2.y;
                  }
        if ( p_3.y <= miny){
                       miny= p_3.y;
                   }
        if (p_4.y <= miny){
                      miny = p_4.y;
                   }
         cout<< "The minimum y-coordinate of the bounding box is: "<< miny <<endl;
    }
    void min_x(){
        double minx;
        minx = p_1.x;
        
        if( p_2.x <= minx ){
               minx= p_2.x;
            }
        if ( p_3.x <= minx){
                  minx= p_3.x;
            }
        if (p_4.x <= minx){
              minx = p_4.x;
          }
         cout<< "The minimum x-coordinate of the bounding box is: "<< minx<<endl;
    }
    void boundingbox(){
        max_y();
        min_y();
        max_x();
        min_x();
    }
    
   void display() {
      cout<< "This is the Square class."<<endl;
      area();
      circumference();
      boundingbox();
      
   }
};


class Triangle : public Shape{
  
    Point p_1;
    Point p_2;
    Point p_3;

public:

    Triangle(){
    }
   Triangle(Point& p1, Point& p2, Point& p3){
       p_1 = p1;
       p_2 = p2;
       p_3 = p3;
   }
    ~Triangle(){};
   
    void area(){
        double area = abs((p_2.x - p_1.x)*(p_3.y - p_1.y) - (p_3.x - p_1.x)*(p_2.y - p_1.y) )/2;
        cout << "The area of the triangle is "<<area<<endl;
     
    }
   
   void circumference() {
       double s1 = sqrt(pow( (p_1.x - p_2.x), 2) + pow( (p_1.y - p_2.y), 2));
       double s2 = sqrt(pow( (p_1.x - p_3.x), 2) + pow( (p_1.y - p_3.y), 2));
       double s3 = sqrt(pow( (p_2.x - p_3.x), 2) + pow( (p_2.y - p_3.y), 2));
       
       cout << "The circumference (perimeter) of the triangle is "<< s1 + s2 + s3 <<endl;

   }
   
    void max_y(){
          
          double maxy;

              maxy = p_1.y;
              if( p_2.y >= maxy ){
                  maxy= p_2.y;
                  }
          if ( p_3.y >= maxy){
                     maxy= p_3.y;
                      }
        cout<< "The maximum y-coordinate of the bounding box is: "<<maxy<<endl;
      }
      
    void max_x(){
          double maxx;
          maxx = p_1.x;
          if( p_2.x >= maxx ){
              maxx= p_2.x;
          }
          if ( p_3.x >= maxx){
             maxx= p_3.x;
          }
          cout<< "The maximum x-coordinate of the bounding box is: "<<maxx<<endl;
      }
     void min_y(){
           double miny;
          miny = p_1.y;
          if( p_2.y <= miny ){
              miny= p_2.y;
                    }
          if ( p_3.y <= miny){
                miny= p_3.y;
        }
          cout<< "The minimum y-coordinate of the bounding box is: "<<miny<<endl;
      }
      void min_x(){
          double minx;
          minx = p_1.x;
          
          if( p_2.x <= minx ){
                 minx= p_2.x;
              }
          if ( p_3.x <= minx){
                    minx= p_3.x;
              }
          cout<< "The minimum x-coordinate of the bounding box is: "<<minx<<endl;
      }
    void boundingbox(){
        
        max_y();
        min_y();
        max_x();
        min_x();
    }

    void display(){
        cout<< "This is the Triangle class."<<endl;
        area();
        circumference();
        boundingbox();
   }


};

int main(){


    Point center(10,-5);
    Circle c_1(center, 23);
    c_1.display();
    cout<<endl;
    Point p_1(-1,-1);
    Point p_2(-1,24);
    Point p_3(24,-1);
    Point p_4(24,24);
    Square s_1(p_1, p_2, p_3, p_4);
    s_1.display();
    cout<<endl;
    Point p_5(0, 0);
    Point p_6(0, 10);
    Point p_7(0, 30);
    Triangle t_1(p_5, p_6, p_7);
    t_1.display();
      
    return 0;
}
