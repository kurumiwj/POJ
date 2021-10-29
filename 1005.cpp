#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14

class Point{
public:
	double x,y;
	Point(){}
	Point(double _x,double _y):x(_x),y(_y){}
};

double dis(Point a,Point b){
	return sqrt(pow(abs(a.x-b.x),2)+pow(abs(a.y-b.y),2));
}

int main(){
	int n;
	scanf("%d",&n);
	Point center(0,0);
	for(int i=0;i<n;i++){
		Point pt;
		scanf("%lf%lf",&pt.x,&pt.y);
		double distance=dis(center,pt);
		double radius=0;
		int square=50,year=1;
		while(true){
			radius=sqrt(square*2.0/PI);
			if(distance<radius){
				printf("Property %d: This property will begin eroding in year %d.\n",i+1,year);
				break;
			}
			year++;
			square+=50;
		}
	}
	printf("END OF OUTPUT.");
	system("pause");
	return 0;
}
