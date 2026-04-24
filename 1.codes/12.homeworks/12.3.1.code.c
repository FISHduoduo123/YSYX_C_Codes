#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point { int row, col; } stack[512];
int top = 0;

void push(struct point p) {
    stack[top++] = p;
}

struct point pop(void) {
    return stack[--top];
}

int is_empty(void) {
    return top == 0;
}

int maze[MAX_ROW][MAX_COL] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};

void print_maze(void) {
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++)
            printf("%d ", maze[i][j]);
        putchar('\n');
    }
    printf("*********\n");
}

struct point predecessor[MAX_ROW][MAX_COL] = {
    {{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
    {{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
    {{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
    {{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
    {{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
};

void visit(int row, int col, struct point pre) {
    struct point visit_point = { row, col };
    maze[row][col] = 2;
    predecessor[row][col] = pre;
    push(visit_point);
}

int main(void) {
    struct point p = { 0, 0 };

    maze[p.row][p.col] = 2;
    push(p);

    while (!is_empty()) {
        p = pop();
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
            break;
        if (p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0)
            visit(p.row, p.col + 1, p);
        if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0)
            visit(p.row + 1, p.col, p);
        if (p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0)
            visit(p.row, p.col - 1, p);
        if (p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0)
            visit(p.row - 1, p.col, p);
        // print_maze();   // 若不需要逐步打印可注释
    }

    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
        // 打印路径坐标（包含起点）
        printf("Path coordinates (from end to start):\n");
        struct point cur = p;
        while (1) {
            printf("(%d, %d)\n", cur.row, cur.col);
            if (predecessor[cur.row][cur.col].row == -1)
                break;
            cur = predecessor[cur.row][cur.col];
        }

        // ----- 添加部分：用二维数组打印正确路径 -----
        int path[MAX_ROW][MAX_COL] = {0};   // 新二维数组，初始全0
        cur = p;                            // 从终点开始回溯
        while (1) {
            path[cur.row][cur.col] = 1;     // 路径上的点标记为1
            if (predecessor[cur.row][cur.col].row == -1)
                break;
            cur = predecessor[cur.row][cur.col];
        }

        printf("\nCorrect path visualized (1 = on path, 0 = not on path):\n");
        for (int i = 0; i < MAX_ROW; i++) {
            for (int j = 0; j < MAX_COL; j++)
                printf("%d ", path[i][j]);
            putchar('\n');
        }
        // -----------------------------------------
    } else {
        printf("No path!\n");
    }

    return 0;
}