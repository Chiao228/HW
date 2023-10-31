# include <stdio.h>
# define Spacing 0
# define Black 1
# define White 2

int next[8][8]={
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,1,2,0,0,0},
          {0,0,0,2,1,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0}
    };
int chess[8][8]={
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,1,2,0,0,0},
          {0,0,0,2,1,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0}
    };

int new_step(int x, int y){
    int find_color, color , new_x , new_y;
    for(int i =3 ; i<5 ; i++){
        for(int j=3 ; j<5 ; j++){
             color = chess[i][j];
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
                    new_x = i+dx;
                    new_y = j+dy;
                    while(new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8 && chess[new_x][new_y] == find_color){
                        new_x += dx;
                        new_y += dy;
                        if(chess[new_x][new_y] == 0){
                            next[new_x][new_y] = color;
                            if(i == x && j == y){
                                printf("(%d,%d)",new_x ,new_y);
                            }
                        }
                    }
                }
             }
        }
    }
}

void print_can_move(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("%d ", next[i][j]);
        }
        printf("\n");
    }
}

void printf_chess_Black(int x , int y){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(chess[i][j] != 0){
                continue;
            }
            else{
                if(next[i][j] == Black){
                    printf("(%d,%d)\t",i ,j);
                }
            }
        }
    }
}

void printf_chess_White(int x , int y){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(chess[i][j] != 0){
                continue;
            }
            else{
                if(next[i][j] == White){
                    printf("(%d,%d)\t",i ,j);
                }
            }
        }
    }
}

int main(){
    int x, y;
    scanf("%d %d",&x , &y);
    new_step(x, y);
    printf("\n");
    print_can_move();
    printf("白子可下位置:\n");
    printf_chess_White(x,y);
    printf("\n");
    printf("黑子可下位置:\n");
    printf_chess_Black(x,y);
}
