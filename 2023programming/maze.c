#include <stdio.h>

#define MAX_N 10
int stack_i[100],stack_j[100];
int top=0;
typedef struct{
    int i;
    int j;
}coordinate;

void push(int i,int j){
    stack_i[top]=i;
    stack_j[top]=j;
    top++;
}
coordinate pop(){
    coordinate temp;
    temp.i=stack_i[top-1];
    temp.j=stack_j[top-1];
    top--;
    return temp;
}
int is_empty(int i,int j){
    if(top==0)
        return 0;
    return 1;
}

int main() {
    char maze[MAX_N][MAX_N] = {
        { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        { '0', '0', '0', '1', '1', '0', '1', '1', '0', '1'},
        { '1', '0', '1', '1', '0','0', '0', '0', '0', '1' },
        { '1', '0', '0', '0', '0', '1', '0', '1', '0', '1'},
        { '1', '1', '1', '0', '1', '1', '0', '1', '1', '1'},
        { '1', '0', '1', '1', '1', '0', '0', '1', '0', '1'},
        { '1', '0', '0', '0', '0', '0', '1', '1', '0', '0'},
        { '1', '0', '1', '1', '1', '1', '1', '0', '0', '1'},
        { '1', '0', '0', '0', '0', '0', '0', '0', '1', '1'},
        { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };
    coordinate start,end;
    printf("Enterance:");
    scanf("%d %d",&start.i,&start.j);

    printf("Exit:");
    scanf("%d %d",&end.i,&end.j);
    push(start.i,start.j);
    int d[][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int i,j;
    int visited[MAX_N][MAX_N]={{0}};
    while(is_empty(i,j)){
        coordinate current=pop();
        maze[current.i][current.j]='x';
        visited[current.i][current.j]= 1;
        if(current.i==end.i && current.j==end.j){
            for(int y=0;y<MAX_N;y++){
                for(int x=0;x<MAX_N;x++){
                    printf("%c",maze[y][x]);
                }
                printf("\n");
            }
            break;
        }
        else{
            int found=0;
            for(int go=0;go<4;go++){
                if(current.i+d[go][0]>=0 && current.i+d[go][0]<MAX_N && current.j+d[go][1]>=0 && current.j+d[go][1]<MAX_N && maze[current.i+d[go][0]][current.j+d[go][1]]=='0'&& visited[current.i+d[go][0]][current.j+d[go][1]]==0){
                    found=1;
                }
            }
            if(found)
                push(current.i,current.j);
            int success=0;
            for(int go=0;go<4;go++){
                if(current.i+d[go][0]>=0 && current.i+d[go][0]<MAX_N && current.j+d[go][1]>=0 && current.j+d[go][1]<MAX_N && maze[current.i+d[go][0]][current.j+d[go][1]]=='0'&& visited[current.i+d[go][0]][current.j+d[go][1]]==0){
                    push(current.i+d[go][0],current.j+d[go][1]);
                    success=1;
                }
            }
            if(success==0){
                maze[current.i][current.j]='0';
            }
        }
    }
}
