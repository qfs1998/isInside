#include<iostream>
#include<vector>
using namespace std;

class point
{
public:
	double x, y;
	point(double x, double y) :x(x), y(y) {}
};

//͹�ı���
class shape
{
public:
	vector<point> points;
	shape()
	{
		cout << "��˳ʱ�������ı����ĵ������" << endl;
		double x, y;
		for (int i = 0; i < 4; ++i)
		{
			cin >> x >> y;
			points.push_back(point(x, y));
		}
	}
	bool isInside(const point&p);
};

//���һ��M����͹�ı����ڲ࣬�����͹�ı���������˳ʱ���������Ҳ࣬
//�����������������㵽��M���������֮��õ�����������Ӧ����ͬ��������Ӧ����ͬ
//P �� Q = x1*y2 - x2*y1
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
	//=0�����ڱ��ϼ� sinֵΪ0
	if ((a >= 0 && b >= 0 && c >= 0 && d >= 0) || (a <= 0 && b <= 0 && c <= 0 && d <= 0))
		return true;
	return false;
}

int main()
{
	shape s;
	double x, y;
	cout << "�����M�����꣬�����жϵĵ㣬���ظ������M����" << endl;
	while (cin >> x >> y)
	{
		point p(x, y);
		if (s.isInside(p))
			cout << "���ڲ�" << endl;
		else
			cout << "���ⲿ" << endl;
		cout << "�����M�����꣬�����жϵĵ�" << endl;
	}
	system("pause");
	return 0;
}