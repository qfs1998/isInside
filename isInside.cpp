#include<iostream>
#include<vector>
using namespace std;

class point
{
public:
	double x, y;
	point(double x, double y) :x(x), y(y) {}
};

//凸四边形
class shape
{
public:
	vector<point> points;
	shape()
	{
		cout << "请顺时针输入四边形四点的坐标" << endl;
		double x, y;
		for (int i = 0; i < 4; ++i)
		{
			cin >> x >> y;
			points.push_back(point(x, y));
		}
	}
	bool isInside(const point&p);
};

//如果一个M点在凸四边形内侧，则点在凸四边形内所有顺时针向量的右侧，
//因此所有向量和其起点到点M的向量叉乘之后得到的向量方向应该相同，即正负应该相同
//P × Q = x1*y2 - x2*y1
bool shape::isInside(const point&p)
{
	point AB(points[1].x - points[0].x, points[1].y - points[0].y);
	point BC(points[2].x - points[1].x, points[2].y - points[1].y);
	point CD(points[3].x - points[2].x, points[3].y - points[2].y);
	point DA(points[0].x - points[3].x, points[0].y - points[3].y);

	point AM(p.x - points[0].x, p.y - points[0].y);
	point BM(p.x - points[1].x, p.y - points[1].y);
	point CM(p.x - points[2].x, p.y - points[2].y);
	point DM(p.x - points[3].x, p.y - points[3].y);

	//AB X AM
	double a = AB.x*AM.y - AM.x*AB.y;
	//BC X BM
	double b = BC.x*BM.y - BM.x*BC.y;
	//CD X CM
	double c = CD.x*CM.y - CM.x*CD.y;
	//DA X DM
	double d = DA.x*DM.y - DM.x*DA.y;
	cout << a << '\t' << b << '\t' << c << '\t' << d << endl;
	//=0代表在边上即 sin值为0
	if ((a >= 0 && b >= 0 && c >= 0 && d >= 0) || (a <= 0 && b <= 0 && c <= 0 && d <= 0))
		return true;
	return false;
}

int main()
{
	shape s;
	double x, y;
	cout << "输入点M的坐标，即被判断的点，可重复输入点M坐标" << endl;
	while (cin >> x >> y)
	{
		point p(x, y);
		if (s.isInside(p))
			cout << "在内部" << endl;
		else
			cout << "在外部" << endl;
		cout << "输入点M的坐标，即被判断的点" << endl;
	}
	system("pause");
	return 0;
}