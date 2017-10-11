//Fernand B.
class Box
{
private:
	double x, y;
	double size_x, size_y;
public:
	Box(double, double, double, double);

	bool isColliding(Box&);
};

