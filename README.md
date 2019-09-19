# isInside
判断点M是否在凸四边形内</br>
如果一个M点在凸四边形内侧，则点在凸四边形内所有顺时针向量的右侧，</br>
因此所有向量和其起点到点M的向量叉乘之后得到的向量方向应该相同，即正负应该相同</br>
可以到下面这个在线坐标轴网站取点：
https://www.math10.com/en/geometry/geogebra/geogebra.html
![image](https://github.com/qfs1998/isInside/blob/master/%E5%9B%BE.png)


# 示例:
请顺时针输入四边形四点的坐标</br>
-2 2</br>
3.23 3.99</br>
4.02 -3.16</br>
-2 -4</br>
输入点M的坐标，即被判断的点，可重复输入点M坐标</br>
0 0</br>
在内部</br>
输入点M的坐标，即被判断的点</br>
2.5 2.5</br>
在内部</br>
输入点M的坐标，即被判断的点</br>
-3 -4</br>
在外部</br>
输入点M的坐标，即被判断的点</br>
-2 -4</br>
在内部</br>
输入点M的坐标，即被判断的点</br>
