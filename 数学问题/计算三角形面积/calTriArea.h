
struct point
{
	double x;
	double y;
};
class CalTriArea
{
	public :
	 double	calByR(double,double,double,double);
	 double	calByr(double,double,double,double);
	 double calByEdge(double ,double,double  );
	 double calByPoint(point,point,point);
	private:
	double a;
	double b;
	double c;
	double r;//内接圆半径 
	double R;//外接圆半径 
	point p1;
	point p2;
	point p3;
};
double CalTriArea::calByEdge(double a,double b,double c)
{
	double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));	
}
double CalTriArea::calByR(double a,double b,double c,double R)
{
	return a*b*c/4/R;
}
double CalTriArea::calByr(double a,double b,double c,double r)
{	
	return r*(a+b+c)/2;
}
double CalTriArea::calByPoint(point p1,point p2,point p3)
{	
	double t = -p2.x*p1.y+p3.x*p1.y+p1.x*p2.y-p3.x*p2.y-p1.x*p3.y+p2.x*p3.y;
	if(t < 0) t = -t;
	return t/2;

}