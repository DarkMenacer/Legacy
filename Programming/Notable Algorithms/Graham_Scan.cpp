/*

*/
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define all(name) name.begin(),name.end()
#define here cout<<"here\n"
#define nl cout<<'\n'
#define display(name) for(auto it: name){cout<<it<<" ";}cout<<"\n"
#define what_is___here(name) cout<<"It is "<<name<<"\n"
#define f first
#define s second
#define mp make_pair
#define p pair
using namespace std;

float slope(pair<float,float> p1, pair<float,float> p2){return (p2.s - p1.s)/(p2.f - p1.f);}

bool criteria(stack< p<float,float> > convex_hull, pair <float,float> p3){
    p <float,float> p1, p2;
    p2 = convex_hull.top();
    convex_hull.pop();
    p1 = convex_hull.top();
    float val = (p2.s - p1.s)*(p3.f - p2.f) - (p2.f - p1.f)*(p3.s - p2.s);
    if(val>0){return true;}
    else{return false;}
}

int main(){
    cout<<"Enter total number of points: ";
    int n,i;
    cin>>n;
    vector< p <float,float> > points;
    stack<p <float,float> > convex_hull;
    points.reserve(n);
    cout<<"Enter x & y coordinates of the point with least y coordinate: ";
    cin>>points[0].f>>points[0].s;
    cout<<"Enter x & y coordinates of the rest points one-by-one in counter-clockwise direction: \n";
    FOR(i,1,n){cin>>points[i].f>>points[i].s;}
    convex_hull.push(points[0]);
    convex_hull.push(points[1]);
    convex_hull.push(points[2]);
    FOR(i,3,n){
        while(convex_hull.size()>1 && criteria(convex_hull,points[i])){convex_hull.pop();}
        convex_hull.push(points[i]);
    }
    int total = convex_hull.size();
    FOR(i,0,total-1){
        cout<<"("<<convex_hull.top().f<<","<<convex_hull.top().s<<"), ";
        convex_hull.pop();
    }
    cout<<"("<<convex_hull.top().f<<","<<convex_hull.top().s<<") are the extreme points of convex hull";
    return 0;
}