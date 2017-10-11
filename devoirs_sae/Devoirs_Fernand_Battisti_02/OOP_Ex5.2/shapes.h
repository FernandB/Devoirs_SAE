//Fernand Battisti

#ifndef SHAPES_H
#define SHAPES_H
	class Shape
	{

	protected:
		double x;
		double y;

	public:
		Shape(double, double);
		virtual bool isColliding(Shape*)=0;
	
	};
	class Rectangle;
	class Circle :public Shape
	{
	private:
		double radius;
	public:
		Circle(double, double, double);
		bool Circle::isColliding(Shape*);
		bool Circle::isColliding(Circle*);
		bool Circle::isColliding(Rectangle*);
		double getX();
		double getY();
		double getRadius();


	};

	class Rectangle:public Shape
	{
	private:
		double height;
		double width;

	public :
		Rectangle(double, double, double, double);
		double getX();
		double getY();
		double getHeight();
		double getWidth();
		bool Rectangle::isColliding(Shape*);
		bool Rectangle::isColliding(Circle*);
		bool Rectangle::isColliding(Rectangle*);
	};

	
	


#endif 