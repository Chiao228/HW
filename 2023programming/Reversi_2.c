#include <stdio.h>
#define Spacing 0
#define Black 1
#define White 2

int next[8][8];
int newStep(int chess[8][8], int x, int y, int dx, int dy){
    int find_color, color = chess[x][y];

    if(color == Black){
        find_color = White;
    }
    else{
        find_color = Black;
    }
    for(int dx = -1 ; dx <= 1 ; dx++){
         for(int dy = -1 ; dy <=1 ; dy++){
             if(dx == 0 && dy == 0){
                    continue;
              }

              int newX = x+dx;
              int newY = y+dy;

              while(newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && chess[newX][newY] == find_color){
                     newX += dx;
                     newY += dy;
                     if(chess[newX][newY] == 0){
                         next[newX][newY] = color;
                     }
               }
           }
       }
}




void check_new_step_by_color(int chess[8][8], int next[8][8], int color){

}

void check_new_step(int chess[8][8], int next[8][8], int x, int y){

}

int new_step(int chess[8][8], int next[8][8], int x, int y, int dx, int dy){

    return 0;
    return 1;
}

void print_chessboard(int chess[8][8]){

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("%d ", chess[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int chess[8][8] = {
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,1,2,0,0,0},
          {0,0,0,2,1,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0}
    };
    int x, y, color;
    print_chessboard(chess);
    scanf("%d %d",&x ,&y);
    return 0;
}

