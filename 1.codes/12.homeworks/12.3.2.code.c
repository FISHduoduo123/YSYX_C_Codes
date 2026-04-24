/*
本节程序中predecessor这个数据结构占用的存储空间太多了，
改变它的存储方式可以节省空间，想想该怎么改。

  1.区分直路和分支点：只保存关键节点，节省内存
  2.使用 unsigned char：内存效率高
*/
#include <stdio.h>

#define MAX_X 7
#define MAX_Y 7
/*
  0: 空气
  1: 墙壁
  3: 终点
*/
int map[MAX_Y][MAX_X] = {
    {1,1,1,1,1,1,1},
    {1,0,1,0,0,0,1},
    {1,0,1,0,0,0,1},
    {1,0,1,0,1,0,1},
    {1,0,1,0,0,0,1},
    {1,0,0,0,1,3,1},
    {1,1,1,1,1,1,1},
};

void print_map(void) {
    unsigned char x, y;
    for (y = 0; y < MAX_Y; y++) {
        for (x = 0; x < MAX_X; x++)
            printf("%d ", map[y][x]);
        putchar('\n');
    }
    printf("**********\n");
}

struct point {
    unsigned char x;
    unsigned char y;
    unsigned char around[4];
} robot[256];
int point_index = 0;

void push(unsigned char x, unsigned char y, unsigned char *around) {
    robot[point_index].x = x;
    robot[point_index].y = y;
    for (int i = 0; i < 4; i++)
        robot[point_index].around[i] = around[i];
    point_index++;
}

struct point pop(void) {
    return robot[--point_index];
}

struct point st_top(void) {
    return robot[point_index - 1];
}

unsigned char left(unsigned char dir) {
    return (dir + 3) % 4;
}

unsigned char right(unsigned char dir) {
    return (dir + 1) % 4;
}

unsigned char reverse(unsigned char dir) {
    return (dir + 2) % 4;
}

unsigned char move(unsigned char dir, unsigned char *x, unsigned char *y, unsigned char move_en) {
    unsigned char nx = *x, ny = *y;

    switch(dir) {
        case 0: ny = *y - 1; break;
        case 1: nx = *x + 1; break;
        case 2: ny = *y + 1; break;
        case 3: nx = *x - 1; break;
    }
    
    if (map[ny][nx] != 1) {
        if (move_en) {
            *x = nx;
            *y = ny;
        }
        return 1;
    }
    return 0;
}

int main(void) {
    unsigned char x = 1, y = 1;
    unsigned char dir = 2;
    int step = 0;
    
    // 起点入栈并标记
    unsigned char start_around[4] = {0};
    push(x, y, start_around);
    map[y][x] = 2;
    
    print_map();
    
    while (1) {
        printf("Step: %d\n", step++);
        
        unsigned char around[4] = {0, 0, 0, 0};
        around[reverse(dir)] = 1;
        unsigned char branch_flag = 3;
        
        // 前方有墙
        if (!(move(dir, &x, &y, 0))) {
            around[dir] = 1;
            branch_flag--;
        }
        // 左侧有墙
        if (!(move(left(dir), &x, &y, 0))) {
            around[left(dir)] = 1;
            branch_flag--;
        }
        // 右侧有墙
        if (!(move(right(dir), &x, &y, 0))) {
            around[right(dir)] = 1;
            branch_flag--;
        }
        
        // 死路
        if (branch_flag == 0) {
            // 无路
            if (point_index == 0) {
                printf("No path!\n");
                break;
            }
            struct point point_buf = st_top();
            while (1) {
                int i;
                for (i = 0; i < 4; i++) if (!point_buf.around[i]) break;
                // 前驱分支结束
                if (i > 3) {
                    point_buf = pop();
                    continue;
                } else {
                    robot[point_index - 1].around[i] = 1;
                    dir = i;
                    x = point_buf.x;
                    y = point_buf.y;
                    map[y][x] = 2;
                    move(dir, &x, &y, 1);
                    break;
                }
            }
        }
        // 仅一通道
        else if (branch_flag == 1) {
            int i;
            for (i = 0; i < 4; i++) {
                if (i != reverse(dir) && !around[i])
                    break;
            }
            dir = i;
            map[y][x] = 2;
            move(dir, &x, &y, 1);
        }
        // 有分支(2或3个方向)压栈
        else {
            int i;
            for (i = 0; i < 4; i++) {
                if (i != reverse(dir) && !around[i])
                    break;
            }
            around[i] = 1;
            push(x, y, around);
            dir = i;
            map[y][x] = 2;
            move(dir, &x, &y, 1);
        }
        
        print_map();
        
        // 终点检测
        if (map[y][x] == 3) break;
    }
    
    printf("Find the exit! (%d, %d)\n", x, y);
    return 0;
}