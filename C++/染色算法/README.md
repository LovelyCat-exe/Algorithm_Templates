# 中文版
## 一个基于BFS的染色算法
### 程序说明:
给定一个二位矩阵代表图片, 并通过给定修改坐标, 已$(x, y)$为起点进行广度优先遍历它周围的八连通, 并把颜色与$(x, y)$处相同颜色的格子染成目标颜色.
### 输入说明:
第一行输入两个整数$n$和$m$, 代表矩阵的长和宽.第二至$n + 1$行为矩阵内容.第$n + 2$行为一个整数q, 代表修改的次数.第$n + 3$至$n + q + 3$行, 每行三个整数, 分别代表染色起点$(x_i,  y_i)$, 以及一个目标颜色c, 表示把自$(x_i,  y_i)$开始, 所有与其八连通的所有颜色相同的个字染成目标颜色.

### 输入样例:

```input
5 5
1 1 1 1 1
0 0 1 1 1
0 0 0 1 1
0 1 1 1 1
0 0 0 0 0
1
2 1 2
```

### 样例输出
```output
1 1 1 1 1 
2 2 1 1 1 
2 2 2 1 1 
2 1 1 1 1 
2 2 2 2 2
```


# English
## A Coloring Algorithm Based on BFS
### Program Description:
Given a two-dimensional matrix representing an image, and through the provided modification coordinates, starting from $(x, y)$, perform a breadth-first traversal of the eight-connected areas around it, and color the grids with the same color as the $(x, y)$ position into the target color.
### Input Description:
The first line inputs two integers $n$ and $m$, representing the length and width of the matrix. The second to $n + 1$ lines represent the matrix content. The $(n + 2)$nd line represents an integer $q$, indicating the number of modifications. The $(n + 3)$th to $(n + q + 3)$th lines, each containing three integers, represent the coloring starting point $(x_i, y_i)$ and a target color $c$, indicating to color all the characters that are eight-connected from $(x_i, y_i)$ and have the same color as the target color. 
### Input Sample:
```input
5 5
1 1 1 1 1
0 0 1 1 1
0 0 0 1 1
0 1 1 1 1
0 0 0 0 0 1
2 1 2
```

### Sample output:
```output
1 1 1 1 1 
2 2 1 1 1 
2 2 2 1 1 
2 1 1 1 1 
2 2 2 2 2
```
