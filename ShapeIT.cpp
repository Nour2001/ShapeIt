
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
