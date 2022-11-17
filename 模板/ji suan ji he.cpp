#include<bits/stdc++.h>
using namespace std;
namespace computationalGeometry // ���㼸�� 
{
	template<typename T> struct Point; // �������� 
	template<typename T> struct Line; // ֱ�� 
	template<typename T> struct Segment; // �߶� 
	template<typename T> struct Polygon; // ����� 
	using _T=long long; // ȫ���������Ϳɸ�double�ȣ���long doubleҪ��������Ϊ��Ӧlong double���� 
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
		T operator *(const Point &a) const {return x*a.x+y*a.y;} // ���
		T operator ^(const Point &a) const {return x*a.y-y*a.x;} // ��� 
		int toLeft(const Point &a) const {auto t=*this^a;return (t>eps)-(t<-eps);}; // 1��0���ߣ�-1�� 
		T len2() const {return (*this)*(*this);}
		T dis2(const Point &a) const {return (*this-a).len2();}
		bool isOn(const Line<T> &a) const {return (*this-a.p).toLeft(a.v)==0;}
		// -1 �����߶ζ˵� | 0 �㲻���߶��� | 1 ���ϸ����߶���
		int isOn(const Segment<T> &p) const
		{
			if (p.a==*this || p.b==*this) return -1;
			return (*this-p.a).toLeft(*this-p.b)==0 && (*this-p.a)*(*this-p.b)<-eps;
		}
		
		// �漰������
		Point<T> proj(const Line<T> &a) const {return a.p+a.v*((a.v*(*this-a.p))/(a.v*a.v));} //ͶӰ
		double len() const {return sqrt(len2());}
		double dis(const Point &a) const {return (*this-a).len();}
		double ang(const Point &a) const {return acos((*this*a)/(len()*a.len()));} // �����н� 
		Point rot(const double rad) const {return {x*cos(rad)-y*sin(rad),x*sin(rad)+y*cos(rad)};}
		Point rot(const double _sin,const double _cos) const {return {x*_cos-y*_sin,x*_sin+y*_cos};}
	};
	bool argcmp(const point &a,const point &b) // �������� 
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
	//	if (abs(t)<=eps) return a*a<b*b-eps; // ��ͬ���ȵ�������Ҫ�ֿ�
		return t>eps;
	}
	template<typename T> struct Line
	{
		Point<T>p,v; // p+tv
		Line(Point<T> a,Point<T> b){p=a,v=b-a;}
		Line(Segment<T> s){p=s.a,v=s.b-s.a;}
		bool operator ==(const Line &a) const {return v.toLeft(a.v)==0 && v.toLeft(p-a.p)==0;}
		int toLeft(const Point<T> &a) const {return v.toLeft(a-p);}
		bool operator<(const Line &a) const  // ��ƽ�潻�㷨���������
	    {
	        if (abs(v^a.v)<=eps && v*a.v>=-eps) return toLeft(a.p)==-1;
	        return argcmp(v,a.v);
	    }
		
		// �漰������ 
		Point<T> inter(const Line &a) const {return p+v*(((a.v)^(p-a.p))/(v^a.v));} // ���� 
		double dis(const Point<T> &a) const {return abs(v^(a-p))/v.len();}
	};
	template<typename T> struct Segment
	{
		Point<T>a,b;
		Segment(Point<T> _a,Point<T> _b){a=_a,b=_b;}
		// -1 ֱ�߾����߶ζ˵� | 0 �߶κ�ֱ�߲��ཻ | 1 �߶κ�ֱ���ϸ��ཻ
		int isInter(const Line<T> &l) const
		{
			if (l.toLeft(a)==0 || l.toLeft(b)==0) return -1;
			return l.toLeft(a)*l.toLeft(b)==-1;
		}
		// -1 ��ĳһ�߶ζ˵㴦�ཻ | 0 ���߶β��ཻ | 1 ���߶��ϸ��ཻ
		int isInter(const Segment<T> &s) const
		{
			if (a.isOn(s) || b.isOn(s) || s.a.isOn(*this) || s.b.isOn(*this)) return -1;
			Line<T> l(a,b-a),ls(s.a,s.b-s.a);
			return l.toLeft(s.a)*l.toLeft(s.b)==-1 && ls.toLeft(a)*ls.toLeft(b)==-1;
		}
		
		// �漰������ 
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
		vector<Point<T>>p; // ��ʱ��˳�� 
		Polygon(int n){p.resize(n);} 
		size_t nex(const size_t i) const {return i<p.size()-1?i+1:0;}
		size_t pre(const size_t i) const {return i?i-1:p.size()-1;}
		// ��ת��
    	// ����ֵ��һ���ʾ���Ƿ��ڶ���α���
    	// �����������Σ���ת��Ϊ 0 ��ʾ���ڶ�����⣬������ڶ������
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
		// ��������������
	    // �������жϵ�Ĵ洢˳����˳ʱ�����ʱ��
	    T area() const
	    {
	        T sum=0;
	        for (size_t i=0;i<p.size();i++) sum+=p[i]^p[nxt(i)];
	        return sum;
	    }
	    // ����ε��ܳ�
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

