#include <iostream>
using namespace std;

int main(){
	double c;
	while(scanf("%lf",&c)&&c!=0){
		double sum=0;
		for(int i=2;;i++){
			sum+=1.0/i;
			if(sum>c){
				printf("%d card(s)\n",i-1);
				break;
			}
		}
	}
	system("pause");
	return 0;
}
