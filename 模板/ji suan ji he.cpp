#include<bits/stdc++.h>
using namespace std;
namespace computationalGeometry // 计算几何 
{
	template<typename T> struct Point; // 点与向量 
	template<typename T> struct Line; // 直线 
	template<typename T> struct Segment; // 线段 
	template<typename T> struct Polygon; // 多边形 
	using _T=long long; // 全局数据类型可改double等，改long double要将函数改为对应long double类型 
	using point=Point<_T>;
	using line=Line<_T>;
	using segment=Segment<_T>;
	using polygon=Polygon<_T>;
	const _T eps=1e-8;
	const double pi=acos(-1);
	template<typename T> struct Point
	{
		T x,y;
		Point(T _x=0,T _y=0){x=_x,y=_y;}
        bool operator <(const Point &a) const {return abs(x-a.x)<=eps?y<a.y-eps:x<a.x-eps;}
		bool operator ==(const Point &a) const {return abs(x-a.x)<=eps && abs(y-a.y)<=eps;}
		Point operator +(const Point &a) const {return {x+a.x,y+a.y};}
		Point operator -(const Point &a) const {return {x-a.x,y-a.y};}
		Point operator -() const {return {-x,-y};}
		Point operator *(const T k) const {return {x*k,y*k};}
		Point operator /(const T k) const {return {x/k,y/k};}
		T operator *(const Point &a) const {return x*a.x+y*a.y;} // 点积
		T operator ^(const Point &a) const {return x*a.y-y*a.x;} // 叉积 
		int toLeft(const Point &a) const {auto t=*this^a;return (t>eps)-(t<-eps);}; // 1左，0共线，-1右 
		T len2() const {return (*this)*(*this);}
		T dis2(const Point &a) const {return (*this-a).len2();}
		bool isOn(const Line<T> &a) const {return (*this-a.p).toLeft(a.v)==0;}
		// -1 点在线段端点 | 0 点不在线段上 | 1 点严格在线段上
		int isOn(const Segment<T> &p) const
		{
			if (p.a==*this || p.b==*this) return -1;
			return (*this-p.a).toLeft(*this-p.b)==0 && (*this-p.a)*(*this-p.b)<-eps;
		}
		
		// 涉及浮点数
		Point<T> proj(const Line<T> &a) const {return a.p+a.v*((a.v*(*this-a.p))/(a.v*a.v));} //投影
		double len() const {return sqrt(len2());}
		double dis(const Point &a) const {return (*this-a).len();}
		double ang(const Point &a) const {return acos((*this*a)/(len()*a.len()));} // 向量夹角 
		Point rot(const double rad) const {return {x*cos(rad)-y*sin(rad),x*sin(rad)+y*cos(rad)};}
		Point rot(const double _sin,const double _cos) const {return {x*_cos-y*_sin,x*_sin+y*_cos};}
	};
	bool argcmp(const point &a,const point &b) // 极角排序 
	{
		auto quad=[](const point &a)
		{
			if (a.y<-eps) return 1;
			if (a.y>eps) return 4;
			if (a.x<-eps) return 5;
			if (a.x>eps) return 3;
			return 2;
		};
		int qa=quad(a),qb=quad(b);
		if (qa^qb) return qa<qb;
		auto t=a^b;
	//	if (abs(t)<=eps) return a*a<b*b-eps; // 不同长度的向量需要分开
		return t>eps;
	}
	template<typename T> struct Line
	{
		Point<T>p,v; // p+tv
		Line(Point<T> a,Point<T> b){p=a,v=b-a;}
		Line(Segment<T> s){p=s.a,v=s.b-s.a;}
		bool operator ==(const Line &a) const {return v.toLeft(a.v)==0 && v.toLeft(p-a.p)==0;}
		int toLeft(const Point<T> &a) const {return v.toLeft(a-p);}
		bool operator<(const Line &a) const  // 半平面交算法定义的排序
	    {
	        if (abs(v^a.v)<=eps && v*a.v>=-eps) return toLeft(a.p)==-1;
	        return argcmp(v,a.v);
	    }
		
		// 涉及浮点数 
		Point<T> inter(const Line &a) const {return p+v*(((a.v)^(p-a.p))/(v^a.v));} // 交点 
		double dis(const Point<T> &a) const {return abs(v^(a-p))/v.len();}
	};
	template<typename T> struct Segment
	{
		Point<T>a,b;
		Segment(Point<T> _a,Point<T> _b){a=_a,b=_b;}
		// -1 直线经过线段端点 | 0 线段和直线不相交 | 1 线段和直线严格相交
		int isInter(const Line<T> &l) const
		{
			if (l.toLeft(a)==0 || l.toLeft(b)==0) return -1;
			return l.toLeft(a)*l.toLeft(b)==-1;
		}
		// -1 在某一线段端点处相交 | 0 两线段不相交 | 1 两线段严格相交
		int isInter(const Segment<T> &s) const
		{
			if (a.isOn(s) || b.isOn(s) || s.a.isOn(*this) || s.b.isOn(*this)) return -1;
			Line<T> l(a,b-a),ls(s.a,s.b-s.a);
			return l.toLeft(s.a)*l.toLeft(s.b)==-1 && ls.toLeft(a)*ls.toLeft(b)==-1;
		}
		
		// 涉及浮点数 
		double len() const {return a.dis(b);}
		double dis(const Point<T> &p) const 
		{
			if ((p-a)*(b-a)<-eps || (p-b)*(a-b)<-eps) return min(p.dis(a),p.dis(b));
			Line<T> l(a,b-a);
			return l.dis(p);
		}
		double dis(const Segment<T> &s) const
		{
			if (isInter(s)) return 0;
			return min({dis(s.a),dis(s.b),s.dis(a),s.dis(b)});
		}
	};
	template<typename T> struct Polygon
	{
		vector<Point<T>>p; // 逆时针顺序 
		Polygon(int n){p.resize(n);} 
		size_t nex(const size_t i) const {return i<p.size()-1?i+1:0;}
		size_t pre(const size_t i) const {return i?i-1:p.size()-1;}
		// 回转数
    	// 返回值第一项表示点是否在多边形边上
    	// 对于狭义多边形，回转数为 0 表示点在多边形外，否则点在多边形内
		pair<bool,int> winding(const Point<T> &a) const
		{
			int cnt=0;
			for (size_t i=0;i<p.size();i++)
			{
				Point<T> u=p[i],v=p[nex(i)];
				if (a.isOn((Segment<T>){u,v})) return {true,0};
				if (abs(u.y-v.y)<=eps) continue;
				Line<T> l(u,v-u);
				if (u.y<v.y-eps && l.toLeft(a)<=0) continue;
				if (u.y>v.y+eps && l.toLeft(a)>=0) continue;
				if (u.y<a.y-eps && v.y>=a.y-eps) cnt++;
				if (u.y>=a.y-eps && v.y<a.y-eps) cnt--;
			}
			return {false,cnt};
		}
		// 多边形面积的两倍
	    // 可用于判断点的存储顺序是顺时针或逆时针
	    T area() const
	    {
	        T sum=0;
	        for (size_t i=0;i<p.size();i++) sum+=p[i]^p[nxt(i)];
	        return sum;
	    }
	    // 多边形的周长
	    double round() const
	    {
	        double sum=0;
	        for (size_t i=0;i<p.size();i++) sum+=p[i].dis(p[nex(i)]);
	        return sum;
	    }
	};
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	return 0;
}

