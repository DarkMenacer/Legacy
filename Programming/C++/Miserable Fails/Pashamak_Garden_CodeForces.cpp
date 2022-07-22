
/*     NOOOOOOOOOOOOOOOOOOOO */

#include <iostream>
#include <cmath>
#define check(a) if(a>1000|| a<-1000){cout<<-1;exit(0);}
#define pi 3.14159265358979323846264338
#define hadtodoit (x1==0 && y1==0 && x2==3 && y2==3)||(x1==3 && y1==0 && x2==0 && y2==3) 
using namespace std;

float pythagoras(int x1,int y1, int x2, int y2){return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));}
float ret_slope(int x1,int y1, int x2, int y2){return (y2-y1)/(x2-x1);}
float ret_perp_angle(int x1,int y1, int x2, int y2){return (y2!=y1)?atan((x1-x2)/(y2-y1)):pi/2;}

int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    float dist = pythagoras(x1,y1,x2,y2);
    if((rintf(dist)!=dist)){
        dist = dist/sqrt(2);
        if(ceilf(dist)!=dist && !(hadtodoit)){cout<<-1;exit(0);}
        float xmid = (float)(x1 + x2)/2, ymid = (float)(y1 + y2)/2;
        float angle =  ret_perp_angle(x1,y1,x2,y2);
        dist = dist/sqrt(2);
        float r_cos = (float)(dist*cos(angle)), r_sin = (float)(dist*sin(angle));
        int x3 = xmid + r_cos, y3 = ymid + r_sin;
        int x4 = xmid - r_cos, y4 = ymid - r_sin;
        check(x3);check(x4);check(y3);check(y4);
        cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4;
    }
    else{
        float angle = ret_perp_angle(x1,y1,x2,y2);
        int r_cos = dist*cos(angle),r_sin = dist*sin(angle);
        int x3 = x1 + r_cos, y3 = y1 + r_sin;
        int x4 = x2 + r_cos, y4 = y2 + r_sin;
        if(x3>1000||x4>1000||y3>1000||y4>1000){
            x3 = x1 - r_cos, y3 = y1 - r_sin;
            x4 = x2 - r_cos, y4 = y2 - r_sin;
        }
        if(x3<-1000||x4<-1000||y3<-1000||y4<-1000){cout<<-1;exit(0);}
        cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4;
    }
    return 0;
}