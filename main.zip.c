#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
char board[8][8] = {{'r','n','b','q','k','b','n','r'},
                    {'p','p','p','p','p','p','p','p'},
                    {'.','-','.','-','.','-','.','-'},
                    {'-','.','-','.','-','.','-','.'},
                    {'.','-','.','-','.','-','.','-'},
                    {'-','.','-','.','-','.','-','.'},
                    {'P','P','P','P','P','P','P','P'},
                    {'R','N','B','Q','K','B','N','R'}};

char white_kill[16]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char black_kill[16]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
int kill_count1,kill_count2;
void printboard(char a[8][8])
{
    int i,j;
     printf ("   a b c d e f g h\n");
     printf("  ----------------\n");
    for(i=0; i<8; i++)
    {
        printf("%d  ",8-i );
        for(j=0; j<8; j++)
        {
            printf ("%c ",a[i][j]);
        }
        printf (" %d\n",8-i);
    }
    printf ("  ----------------\n");
    printf ("   a b c d e f g h\n");
}
int a,b,c,d,x,k,turn=1,p=0;
int c1=1,c2=1,c3=1;
int c4=1,c5=1,c6=1,arr_turn[300],p1;
char arr[300][8][8];
 char u, n;
 char temp;

int black_rook_white_king(int x,int y,int  w,int z){        //x,y for bl rook  w,z for wh king
    int r,i;
    if(x==w){
        if(z>y){
            for(i=y+1;i<=z;i++){
                if(board[x][i]=='.'||board[x][i]=='-'){
                    r=0;
                }
                else if(board[x][i]=='K'){
                    r=1;
                    break;
                }
                else {
                    r=0;
                    break;
                }
            }
        }else if(y>z){
            for(i=y-1;i>=z;i--){
                if(board[x][i]=='.'||board[x][i]=='-'){
                    r=0;
                }
                else if(board[x][i]=='K'){
                    r=1;
                    break;
                }
                else {
                    r=0;
                    break;
                }
            }
        }else{
            r=0;
        }
    }else if(y==z){
        if(w>x){
            for(i=x+1;i<=w;i++){
                if(board[i][y]=='.'||board[i][y]=='-'){
                    r=0;
                }
                else if(board[i][y]=='K'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else if(x>w){
            for(i=x-1;i>=w;i--){
                if(board[i][y]=='.'||board[i][y]=='-'){
                    r=0;
                }
                else if(board[i][y]=='K'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else{
            r=0;
        }
    }else{
        r=0;
    }
    return r;
}
int white_rook_black_king(int x,int y,int  w,int z){        //x,y for bl rook  w,z for wh king
    int r,i;
    if(x==w){
        if(z>y){
            for(i=y+1;i<=z;i++){
                if(board[x][i]=='.'||board[x][i]=='-'){
                    r=0;
                }
                else if(board[x][i]=='k'){
                    r=1;
                    break;
                }
                else {
                    r=0;
                    break;
                }
            }
        }else if(y>z){
            for(i=y-1;i>=z;i--){
                if(board[x][i]=='.'||board[x][i]=='-'){
                    r=0;
                }
                else if(board[x][i]=='k'){
                    r=1;
                    break;
                }
                else {
                    r=0;
                    break;
                }
            }
        }else{
            r=0;
        }
    }else if(y==z){
        if(w>x){
            for(i=x+1;i<=w;i++){
                if(board[i][y]=='.'||board[i][y]=='-'){
                    r=0;
                }
                else if(board[i][y]=='k'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else if(x>w){
            for(i=x-1;i>=w;i--){
                if(board[i][y]=='.'||board[i][y]=='-'){
                    r=0;
                }
                else if(board[i][y]=='k'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else{
            r=0;
        }
    }else{
        r=0;
    }
    return r;
}
int black_knight_white_king(int x,int y,int w,int z){
int r;
    if((x==w+2&&y==z+1&&board[w][z]=='K')||(x==w+2&&y==z-1&&board[w][z]=='K')||(x==w-2&&y==z-1&&board[w][z]=='K')||(x==w-2&&y==z+1&&board[w][z]=='K')||(x==w+1&&y==z-2&&board[w][z]=='K')||(x==w+1&&y==z+2&&board[w][z]=='K')||(x==w-1&&y==z-2&&board[w][z]=='K')||(x==w-1&&y==z+2&&board[w][z]=='K')){
        r=1;
    }
    else{
        r=0;
    }
    return r;
}
int white_knight_black_king(int x,int y,int w,int z){
int r;
    if((x==w+2&&y==z+1&&board[w][z]=='k')||(x==w+2&&y==z-1&&board[w][z]=='k')||(x==w-2&&y==z-1&&board[w][z]=='k')||(x==w-2&&y==z+1&&board[w][z]=='k')||(x==w+1&&y==z-2&&board[w][z]=='k')||(x==w+1&&y==z+2&&board[w][z]=='k')||(x==w-1&&y==z-2&&board[w][z]=='k')||(x==w-1&&y==z+2&&board[w][z]=='k')){
        r=1;
    }
    else{
        r=0;
    }
    return r;
}
int black_bishop_white_king(int x,int y,int w,int z){
    int i,r,j;
    if(x-w==y-z){
        if(w>x){
            j=y+1;
            for(i=x+1;i<=w;i++){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j++;
                }
                else if(board[i][j]=='K'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break;
                }
            }
        }
        else if(x>w){
             j=y-1;
            for(i=x-1;i>=w;i--){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j--;
                }
                else if(board[i][j]=='K'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break;
                }
            }
        }
        else{
            r=0;
        }
    }
    else if(x-w==z-y){
        if(w>x){
            j=y-1;
            for(i=x+1;i<=w;i++){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j--;
                }
                else if(board[i][j]=='K'){
                    r=1;
                    break;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else if(x>w){
             j=y+1;
            for(i=x-1;i>=w;i--){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j++;
                }
                else if(board[i][j]=='K'){
                    r=1;
                    break;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else{
            r=0;
        }
    }
    else{
        r=0;
    }
    return r;
}
int white_bishop_black_king(int x,int y,int w,int z){
    int i,r,j;
    if(x-w==y-z){
        if(w>x){
            j=y+1;
            for(i=x+1;i<=w;i++){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j++;
                }
                else if(board[i][j]=='k'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break;
                }
            }
        }
        else if(x>w){
             j=y-1;
            for(i=x-1;i>=w;i--){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j--;
                }
                else if(board[i][j]=='k'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break;
                }
            }
        }
        else{
            r=0;
        }
    }
    else if(x-w==z-y){
        if(w>x){
            j=y-1;
            for(i=x+1;i<=w;i++){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j--;
                }
                else if(board[i][j]=='k'){
                    r=1;
                    break;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else if(x>w){
             j=y+1;
            for(i=x-1;i>=w;i--){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j++;
                }
                else if(board[i][j]=='k'){
                    r=1;
                    break;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else{
            r=0;
        }
    }
    else{
        r=0;
    }
    return r;
}
int black_queen_white_king (int x,int y,int w,int z){
    int i,j,r;
    if(x-w==y-z){
        if(w>x){
            j=y+1;
            for(i=x+1;i<=w;i++){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j++;
                }
                else if(board[i][j]=='K'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break;
                }
            }
        }
        else if(x>w){
             j=y-1;
            for(i=x-1;i>=w;i--){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j--;
                }
                else if(board[i][j]=='K'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break;
                }
            }
        }
        else{
            r=0;
        }
    }
    else if(x-w==z-y){
        if(w>x){
            j=y-1;
            for(i=x+1;i<=w;i++){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j--;
                }
                else if(board[i][j]=='K'){
                    r=1;
                    break;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else if(x>w){
             j=y+1;
            for(i=x-1;i>=w;i--){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j++;
                }
                else if(board[i][j]=='K'){
                    r=1;
                    break;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else{
            r=0;
        }
    }
    else if(x==w){
        if(z>y){
            for(i=y+1;i<=z;i++){
                if(board[x][i]=='.'||board[x][i]=='-'){
                    r=0;
                }
                else if(board[x][i]=='K'){
                    r=1;
                    break;
                }
                else {
                    r=0;
                    break;
                }
            }
        }else if(y>z){
            for(i=y-1;i>=z;i--){
                if(board[x][i]=='.'||board[x][i]=='-'){
                    r=0;
                }
                else if(board[x][i]=='K'){
                    r=1;
                    break;
                }
                else {
                    r=0;
                    break;
                }
            }
        }else{
            r=0;
        }
    }else if(y==z){
        if(w>x){
            for(i=x+1;i<=w;i++){
                if(board[i][y]=='.'||board[i][y]=='-'){
                    r=0;
                }
                else if(board[i][y]=='K'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else if(x>w){
            for(i=x-1;i>=w;i--){
                if(board[i][y]=='.'||board[i][y]=='-'){
                    r=0;
                }
                else if(board[i][y]=='K'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else{
            r=0;
        }
    }
    else{
        r=0;
    }

    return r;
}
int white_queen_black_king (int x,int y,int w,int z){
    int i,j,r;
    if(x-w==y-z){
        if(w>x){
            j=y+1;
            for(i=x+1;i<=w;i++){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j++;
                }
                else if(board[i][j]=='k'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break;
                }
            }
        }
        else if(x>w){
             j=y-1;
            for(i=x-1;i>=w;i--){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j--;
                }
                else if(board[i][j]=='k'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break;
                }
            }
        }
        else{
            r=0;
        }
    }
    else if(x-w==z-y){
        if(w>x){
            j=y-1;
            for(i=x+1;i<=w;i++){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j--;
                }
                else if(board[i][j]=='k'){
                    r=1;
                    break;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else if(x>w){
             j=y+1;
            for(i=x-1;i>=w;i--){
                if(board[i][j]=='.'||board[i][j]=='-'){
                    r=0;
                    j++;
                }
                else if(board[i][j]=='k'){
                    r=1;
                    break;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else{
            r=0;
        }
    }
    else if(x==w){
        if(z>y){
            for(i=y+1;i<=z;i++){
                if(board[x][i]=='.'||board[x][i]=='-'){
                    r=0;
                }
                else if(board[x][i]=='k'){
                    r=1;
                    break;
                }
                else {
                    r=0;
                    break;
                }
            }
        }else if(y>z){
            for(i=y-1;i>=z;i--){
                if(board[x][i]=='.'||board[x][i]=='-'){
                    r=0;
                }
                else if(board[x][i]=='k'){
                    r=1;
                    break;
                }
                else {
                    r=0;
                    break;
                }
            }
        }else{
            r=0;
        }
    }else if(y==z){
        if(w>x){
            for(i=x+1;i<=w;i++){
                if(board[i][y]=='.'||board[i][y]=='-'){
                    r=0;
                }
                else if(board[i][y]=='k'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else if(x>w){
            for(i=x-1;i>=w;i--){
                if(board[i][y]=='.'||board[i][y]=='-'){
                    r=0;
                }
                else if(board[i][y]=='k'){
                    r=1;
                    break ;
                }
                else{
                    r=0;
                    break ;
                }
            }
        }
        else{
            r=0;
        }
    }
    else{
        r=0;
    }

    return r;
}
int black_pawn_white_king(int x,int y,int w,int z){
    int r;
    if(w==x+1&&(z==y-1||z==y+1)&&board[w][z]=='K'){
        r=1;
    }
    else {
        r=0;
    }
    return r;
}
int white_pawn_black_king(int x,int y,int w,int z){
    int r;
    if(w==x-1&&(z==y-1||z==y+1)&&board[w][z]=='k'){
        r=1;
    }
    else {
        r=0;
    }
    return r;
}
int black_king_white_king(int x,int y,int w,int z){
    int r;
    if((board[w][z]=='K'&&x==w&&z==y-1)||(board[w][z]=='K'&&x==w&&z==y+1)||(board[w][z]=='K'&&y==z&&x==w-1)||(board[w][z]=='K'&&y==z&&x==w+1)||(board[w][z]=='K'&&x==w+1&&z==y+1)||(board[w][z]=='K'&&x==w+1&&z==y-1)||(board[w][z]=='K'&&x==w-1&&y==z+1)||(board[w][z]=='K'&&x==w-1&&y==z-1)){
        r=1;
    }
    else {
        r=0;
    }
    return r;
}
int white_king_black_king(int x,int y,int w,int z){
    int r;
    if((board[w][z]=='k'&&x==w&&z==y-1)||(board[w][z]=='k'&&x==w&&z==y+1)||(board[w][z]=='k'&&y==z&&x==w-1)||(board[w][z]=='k'&&y==z&&x==w+1)||(board[w][z]=='k'&&x==w+1&&z==y+1)||(board[w][z]=='k'&&x==w+1&&z==y-1)||(board[w][z]=='k'&&x==w-1&&y==z+1)||(board[w][z]=='k'&&x==w-1&&y==z-1)){
        r=1;
    }
    else {
        r=0;
    }
    return r;
}

int Conversion_Char(char x )
{
    int m;
    if (x=='a')
    {
        m=0;

    }
    else if (x=='b')
    {
        m=1;
    }
    else if(x=='c')
    {
        m=2;
    }
    else if (x=='d')
    {
        m=3;
    }
    else if (x=='e')
    {
        m=4;
    }
    else if (x=='f')
    {
        m=5;
    }
    else if (x=='g')
    {
        m=6;
    }
    else if (x=='h')
    {
        m=7;
    }
    return m;
}

int Conversion_Number(int y)
{
    int n;
    n=8-y;
    return n;
}


int valid_black_pawn(int x,int y,int w,int z)
{ char m=board[w][z],n=board[x][y];
    int r;
    if(x!=1)
    {
        if(y==z)
        {
            if(w==x+1)
            {
                if(board [w][z]=='.'||board[w][z]=='-')
                {
                    board[w][z]='p';
                    board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                }
                else
                {
                    r=0;
                }
            }
            else
            {
                r=0;
            }
        }
        else if(w==x+1)
        {
            if(z==y+1||z==y-1)
            {
                if(board[w][z]=='R'||board[w][z]=='B'||board[w][z]=='Q'||board[w][z]=='P'||board[w][z]=='N'||board[w][z]=='K')
                {
                      board[w][z]='p';
                       board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                }
                else
                {
                    r=0;
                }
            }
        }
        else
        {
            r=0;
        }
    }
    else
    {
        if(y==z)      //move
        {
            if(w==x+1)
            {
                if(board [w][z]=='.'||board[w][z]=='-')
                {
                      board[w][z]='p';
                       board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                }
                else
                {
                    r=0;
                }
            }
            else if(w==x+2 &&(board[x+1][y]=='.'||board[x+1][y]=='-'))
            {
                if(board[w][z]=='.'||board[w][z]=='-')
                {
                      board[w][z]='p';
                       board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                }
                else
                {
                    r=0;
                }
            }
            else
            {
                r=0;
            }
        }
        else if(w==x+1)    //eat
        {
            if(z==y+1||z==y-1)
            {
                if(board[w][z]=='R'||board[w][z]=='B'||board[w][z]=='Q'||board[w][z]=='P'||board[w][z]=='N'||board[w][z]=='K')
                {
                      board[w][z]='p';
                       board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                }
                else
                {
                    r=0;
                }
            }
            else{
                r=0;
            }
        }
        else
        {
            r=0;
        }
    }
    return r;
}

int valid_white_pawn(int x,int y,int w,int z)
{ char m=board[w][z],n=board[x][y];
    int r;
    if(x!=6)
    {
        if(y==z)
        {
            if(w==x-1)
            {
                if(board [w][z]=='.'||board[w][z]=='-')
                {
                      board[w][z]='P';
                       board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                }
                else
                {
                    r=0;
                }
            }
            else
            {
                r=0;
            }
        }
        else if(w==x-1)
        {
            if(z==y+1||z==y-1)
            {
                if(board[w][z]=='r'||board[w][z]=='b'||board[w][z]=='q'||board[w][z]=='p'||board[w][z]=='n'||board[w][z]=='k')
                {
                    board[w][z]='P';
                     board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                }
                else
                {
                    r=0;
                }
            }
            else{
                r=0;
            }
        }
        else
        {
            r=0;
        }
    }
    else
    {
        if(y==z)      //move
        {
            if(w==x-1)
            {
                if(board [w][z]=='.'||board[w][z]=='-')
                {
                    board[w][z]='P';
                     board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                }
                else
                {
                    r=0;
                }
            }
            else if(w==x-2 && (board[x-1][y]=='.'||board[x-1][y]=='-'))
            {
                if(board[w][z]=='.'||board[w][z]=='-')
                {
                    board[w][z]='P';
                     board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                }
                else
                {
                    r=0;
                }
            }
            else
            {
                r=0;
            }
        }
        else if(w==x-1)    //eat
        {
            if(z==y+1||z==y-1)
            {
                if(board[w][z]=='r'||board[w][z]=='b'||board[w][z]=='q'||board[w][z]=='p'||board[w][z]=='n'||board[w][z]=='k')
                {
                    board[w][z]='P';
                     board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                }
                else
                {
                    r=0;
                }
            }
            else{
                r=0;
            }
        }
        else
        {
            r=0;
        }
    }
    return r;
}

int valid_white_king(int x,int y,int w,int z)
{
    char m=board[w][z],n=board[x][y];
    int r;
    if(board[w][z]!='R'&&board[w][z]!='K'&&board[w][z]!='B'&&board[w][z]!='Q'&&board[w][z]!='N'&&board[w][z]!='P')
    {
        if(x==w)
        {
            if(z==y-1)
            {
                 board[w][z]='K';
                  board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(z==y+1)
            {
                 board[w][z]='K';
                  board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(y==z)
        {
            if(w==x-1)
            {
                 board[w][z]='K';
                  board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(w==x+1)
            {
                 board[w][z]='K';
                  board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(w==x+1)
        {
            if(z==y+1)
            {
                 board[w][z]='K';
                  board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(z==y-1)
            {
                 board[w][z]='K';
                  board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(w==x-1)
        {
            if(z==y+1)
            {
                 board[w][z]='K';
                  board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(z==y-1)
            {
                 board[w][z]='K';
                  board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else
        {
            r=0;
        }
    }
    else
    {
        r=0;
    }
    return r;
}

int valid_black_king(int x,int y,int w,int z)
{
   char m=board[w][z],n=board[x][y];
    int r;
    if(board[w][z]!='r'&&board[w][z]!='k'&&board[w][z]!='b'&&board[w][z]!='q'&&board[w][z]!='n'&&board[w][z]!='p'&&check_black_king()==0)
    {
        if(x==w)
        {
            if(z==y-1)
            {
                 board[w][z]='k';
                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(z==y+1)
            {
                                 board[w][z]='k';
                                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(y==z)
        {
            if(w==x-1)
            {
                                 board[w][z]='k';
                                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(w==x+1)
            {
                                 board[w][z]='k';
                                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(w==x+1)
        {
            if(z==y+1)
            {
                                 board[w][z]='k';
                                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(z==y-1)
            {
                                 board[w][z]='k';
                                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(w==x-1)
        {
            if(z==y+1)
            {
                                 board[w][z]='k';
                                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(z==y-1)
            {
                                 board[w][z]='k';
                                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else
        {
            r=0;
        }
    }
    else
    {
        r=0;
    }
    return r;
}

int valid_white_rook(int x,int y,int w,int z)
{   char m=board[w][z],n=board[x][y];
    int i,r=1;
    if(board[w][z]!='R'&&board[w][z]!='K'&&board[w][z]!='B'&&board[w][z]!='Q'&&board[w][z]!='N'&&board[w][z]!='P')
    {
        if(x==w&&(z==y+1||z==y-1)) /////
        {
            board[w][z]='R';
             board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
        }
        else if(y==z&&(w==x-1||w==x+1)){
            board[w][z]='R';
             board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
        }
        else if(x==w)
        {
            if(y>z)
            {
                for(i=y-1; i>z; i--)
                {
                    if(board[x][i]=='-'||board[x][i]=='.')
                    {
                            board[w][z]='R';
                             board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }


                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
            else
            {
                for(i=y+1; i<z; i++)
                {
                    if(board[x][i]=='-'||board[x][i]=='.')
                    {
                         board[w][z]='R';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }

                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        else if(y==z)
        {
            if(w>x)
            {
                for(i=x+1; i<w; i++)
                {
                    if(board[i][y]=='.'||board[i][y]=='-')
                    {
                         board[w][z]='R';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }

                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
            else
            {
                for(i=x-1; i>w; i--)
                {
                    if(board[i][y]=='-'||board[i][y]=='.')
                    {
                         board[w][z]='R';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }

                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        else{
            r=0;
        }

    }
    else
    {
        r=0;
    }
    return r;
}

int valid_black_rook(int x,int y,int w,int z)
{  char m=board[w][z],n=board[x][y];
    int i,r=1;
    if(board[w][z]!='r'&&board[w][z]!='k'&&board[w][z]!='b'&&board[w][z]!='q'&&board[w][z]!='n'&&board[w][z]!='p')
    {
    if(x==w&&(z==y-1||z==y+1)){
        board[w][z]='r';
         board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
    }
    else if(z==y&&(w==x+1||w==x-1)){
        board[w][z]='r';
         board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
    }
       else if(x==w)
        {
            if(y>z)
            {
                for(i=y-1; i>z; i--)
                {
                    if(board[x][i]=='-'||board[x][i]=='.')
                    {
                         board[w][z]='r';
                          board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
            else
            {
                for(i=y+1; i<z; i++)
                {
                    if(board[x][i]=='-'||board[x][i]=='.')
                    {
                         board[w][z]='r';
                          board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        else if(y==z)
        {
            if(w>x)
            {
                for(i=x+1; i<w; i++)
                {
                    if(board[i][y]=='.'||board[i][y]=='-')
                    {
                         board[w][z]='r';
                          board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
            else
            {
                for(i=x-1; i>w; i--)
                {
                    if(board[i][y]=='-'||board[i][y]=='.')
                    {
                         board[w][z]='r';
                          board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        else
        {
            r=0;
        }

    }
    else
    {
        r=0;
    }
    return r;
}

int valid_white_knight(int x,int y,int w,int z)
{ char m=board[w][z],n=board[x][y];
    int r;
    if(board [w][z]!='R'&&board [w][z]!='N'&&board [w][z]!='B'&&board [w][z]!='Q'&&board [w][z]!='K'&&board [w][z]!='P')
    {
        if(x==w-1)
        {
            if(y==z+2)
            {
                board[w][z]='N';
                 board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(y==z-2)
            {
                board[w][z]='N';
                 board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(x==w+1)
        {
            if(y==z+2)
            {
                board[w][z]='N';
                 board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(y==z-2)
            {
                board[w][z]='N';
                 board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(x==w-2)
        {
            if(y==z-1)
            {
                board[w][z]='N';
                 board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(y==z+1)
            {
                board[w][z]='N';
                 board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(x==w+2)
        {
            if(y==z+1)
            {
                board[w][z]='N';
                 board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(y==z-1)
            {
                board[w][z]='N';
                 board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else
        {
            r=0;
        }
    }
    else
    {
        r=0;
    }
    return r;
}

int valid_black_knight(int x,int y,int w,int z)
{ char m=board[w][z],n=board[x][y];
    int r;
    if(board [w][z]!='r'&&board [w][z]!='n'&&board [w][z]!='b'&&board [w][z]!='q'&&board [w][z]!='k'&&board [w][z]!='p')
    {
        if(x==w-1)
        {
            if(y==z+2)
            {
                board[w][z]='n';
                 board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(y==z-2)
            {
                 board[w][z]='n';
                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(x==w+1)
        {
            if(y==z+2)
            {
                 board[w][z]='n';
                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(y==z-2)
            {
                 board[w][z]='n';
                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(x==w-2)
        {
            if(y==z-1)
            {
                 board[w][z]='n';
                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(y==z+1)
            {
                 board[w][z]='n';
                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else if(x==w+2)
        {
            if(y==z+1)
            {
                 board[w][z]='n';
                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else if(y==z-1)
            {
                 board[w][z]='n';
                  board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
            }
            else
            {
                r=0;
            }
        }
        else
        {
            r=0;
        }
    }
    else
    {
        r=0;
    }
    return r;
}
int valid_white_bishop(int x,int y,int w,int z)
{ char m=board[w][z],n=board[x][y];
    int r=1,i,j;
    if(board[w][z]!='R'&&board[w][z]!='B'&&board[w][z]!='N'&&board[w][z]!='Q'&&board[w][z]!='K'&&board[w][z]!='P')
    {
    if(w==x-1&&(z==y-1||z==y+1)){
        board[w][z]='B';
         board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
    }
    else if(w==x+1&&(z==y-1||z==y+1)){
        board[w][z]='B';
         board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
    }
        else if(x-w==y-z)
        {
            if(x>w)
            {
                j=z;
                for(i=w+1; i<x; i++)
                {
                    j=j+1;
                    if(board[i][j]=='-'||board[i][j]=='.')
                    {
                         board[w][z]='B';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
            else
            {
                j=y;  //w>x
                for(i=x+1; i<w; i++)
                {
                    j=j+1;
                    if(board[i][j]=='-'||board[i][j]=='.')
                    {
                        board[w][z]='B';
                         board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        //
        else if(x-w==z-y)
        {
            if(x>w)
            {
                j=y;
                for(i=x-1; i>w; i--)
                {
                    j=j+1;
                    if(board[i][j]=='.'||board[i][j]=='-')
                    {
                        board[w][z]='B';
                         board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
            else   //w>x
            {
                j=y;
                for(i=x+1; i<w; i++)
                {
                    j=j-1;
                    if(board[i][j]=='.'||board[i][j]=='-')
                    {
                        board[w][z]='B';
                         board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
        }
        else
        {
            r=0;
        }
    }
    else
    {
        r=0;
    }
    return r;
}

int valid_black_bishop(int x,int y,int w,int z)
{ char m=board[w][z],n=board[x][y];
    int r=1,i,j;
    if(board[w][z]!='r'&&board[w][z]!='b'&&board[w][z]!='n'&&board[w][z]!='q'&&board[w][z]!='k'&&board[w][z]!='p')
    {
        if(x==w-1&&(z==y-1||z==y+1)){
            board[w][z]='b';
             board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
        }
        else if(x==w+1&&(z==y-1||z==y+1)){
            board[w][z]='b';
             board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
        }
        else if(x-w==y-z)
        {
            if(x>w)
            {
                j=z;
                for(i=w+1; i<x; i++)
                {
                    j=j+1;
                    if(board[i][j]=='-'||board[i][j]=='.')
                    {
                        board[w][z]='b';
                         board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
            else
            {
                j=y;  //w>x
                for(i=x+1; i<w; i++)
                {
                    j=j+1;
                    if(board[i][j]=='-'||board[i][j]=='.')
                    {
                         board[w][z]='b';
                          board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        else if(x-w==z-y)
        {
            if(x>w)
            {
                j=z;
                for(i=w+1; i<x; i++)
                {
                    j=j-1;
                    if(board[i][j]=='.'||board[i][j]=='-')
                    {
                         board[w][z]='b';
                          board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
            else   //w>x
            {
                j=y;
                for(i=x+1; i<w; i++)
                {
                    j=j-1;
                    if(board[i][j]=='.'||board[i][j]=='-')
                    {
                         board[w][z]='b';
                          board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
        }
        else
        {
            r=0;
        }
    }
    else
    {
        r=0;
    }
    return r;
}
int valid_white_queen(int x,int y,int w,int z)
{ char m=board[w][z],n=board[x][y];
    int r=1,i,j;
    if(board[w][z]!='R'&&board[w][z]!='B'&&board[w][z]!='N'&&board[w][z]!='Q'&&board[w][z]!='K'&&board[w][z]!='P')
    {
        if((w==x+1&&(z==y-1||z==y+1))||(w==x-1&&(z==y-1||z==y+1))||(x==w&&(z==y-1||z==y+1))||(y==z&&(w==x+1||w==x-1))){
            board[w][z]='Q';
             board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
        }
        else if(x-w==y-z)
        {
            if(x>w)
            {
                j=z;
                for(i=w+1; i<x; i++)
                {
                    j=j+1;
                    if(board[i][j]=='-'||board[i][j]=='.')
                    {
                         board[w][z]='Q';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
            else
            {
                j=y;  //w>x
                for(i=x+1; i<w; i++)
                {
                    j=j+1;
                    if(board[i][j]=='-'||board[i][j]=='.')
                    {
                         board[w][z]='Q';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        else if(x-w==z-y)
        {
            if(x>w)
            {
                j=z;
                for(i=w+1; i<x; i++)
                {
                    j=j-1;
                    if(board[i][j]=='.'||board[i][j]=='-')
                    {
                         board[w][z]='Q';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
            else   //w>x
            {
                j=y;
                for(i=x+1; i<w; i++)
                {
                    j=j-1;
                    if(board[i][j]=='.'||board[i][j]=='-')
                    {
                         board[w][z]='Q';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
        }
        else if(x==w)
        {
            if(y>z)
            {
                for(i=y-1; i>z; i--)
                {
                    if(board[x][i]=='-'||board[x][i]=='.')
                    {
                         board[w][z]='Q';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
            else
            {
                for(i=y+1; i<z; i++)
                {
                    if(board[x][i]=='-'||board[x][i]=='.')
                    {
                         board[w][z]='Q';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        else if(y==z)
        {
            if(w>x)
            {
                for(i=x+1; i<w; i++)
                {
                    if(board[i][y]=='.'||board[i][y]=='-')
                    {
                         board[w][z]='Q';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
            else
            {
                for(i=x-1; i>w; i--)
                {
                    if(board[i][y]=='-'||board[i][y]=='.')
                    {
                         board[w][z]='Q';
                          board[x][y]='.';
                            if(check_white_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        else
        {
            r=0;
        }
    }
    else
    {
        r=0;
    }
    return r;
}

int valid_black_queen(int x,int y,int w,int z)
{ char m=board[w][z],n=board[x][y];
    int r=1,i,j;
    if(board[w][z]!='r'&&board[w][z]!='b'&&board[w][z]!='n'&&board[w][z]!='q'&&board[w][z]!='k'&&board[w][z]!='p')
    {
    if((w==x&&(z==y+1||z==y-1))||(y==z&&(w==x-1||w==x+1))||(w==x-1&&(z==y-1||z==y+1))||(w==x+1&&(z==y-1||z==y+1))){
        board[w][z]='q';
         board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
    }
        else if(x-w==y-z)
        {
            if(x>w)
            {
                j=z;
                for(i=w+1; i<x; i++)
                {
                    j=j+1;
                    if(board[i][j]=='-'||board[i][j]=='.')
                    {
                         board[w][z]='q';
                          board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
            else
            {
                j=y;  //w>x
                for(i=x+1; i<w; i++)
                {
                    j=j+1;
                    if(board[i][j]=='-'||board[i][j]=='.')
                    {
                        board[w][z]='q';
                         board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        else if(x-w==z-y)
        {
            if(x>w)
            {
                j=z;
                for(i=w+1; i<x; i++)
                {
                    j=j-1;
                    if(board[i][j]=='.'||board[i][j]=='-')
                    {
                        board[w][z]='q';
                         board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
            else   //w>x
            {
                j=y;
                for(i=x+1; i<w; i++)
                {
                    j=j-1;
                    if(board[i][j]=='.'||board[i][j]=='-')
                    {
                        board[w][z]='q';
                         board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break ;
                    }
                }
            }
        }
        else if(x==w)
        {
            if(y>z)
            {
                for(i=y-1; i>z; i--)
                {
                    if(board[x][i]=='-'||board[x][i]=='.')
                    {
                        board[w][z]='q';
                         board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
            else
            {
                for(i=y+1; i<z; i++)
                {
                    if(board[x][i]=='-'||board[x][i]=='.')
                    {
                        board[w][z]='q';
                         board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        else if(y==z)
        {
            if(w>x)
            {
                for(i=x+1; i<w; i++)
                {
                    if(board[i][y]=='.'||board[i][y]=='-')
                    {
                        board[w][z]='q';
                         board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
            else
            {
                for(i=x-1; i>w; i--)
                {
                    if(board[i][y]=='-'||board[i][y]=='.')
                    {
                        board[w][z]='q';
                         board[x][y]='.';
                            if(check_black_king()){
                                r=0;
                                board[x][y]=n;
                                board[w][z]=m;
                            }
                            else{
                                r=1;
                                 board[x][y]=n;
                                board[w][z]=m;
                            }
                    }
                    else
                    {
                        r=0;
                        break;
                    }
                }
            }
        }
        else
        {
            r=0;
        }
    }
    else
    {
        r=0;
    }
    return r;
}

int check_white_king(){
int r=0,i,j,k,h,x,y,w,z,con=0;
for (i=0;i<8;i++){
    for(j=0;j<8;j++){
        if (board[i][j]=='K'){
        w=j;
        z=i;
        }
        else{
            continue ;
        }
    }
}
for (i=0;i<8;i++){
    for(j=0;j<8;j++){
        if(board[i][j]=='p'){
                if(black_pawn_white_king(i,j,z,w)){r++;}
        }
        else if (board[i][j]=='p'){
            if(black_pawn_white_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='p'){
             if(black_pawn_white_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='p'){
            if(black_pawn_white_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='p'){
             if(black_pawn_white_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='p'){
            if(black_pawn_white_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='p'){
            if(black_pawn_white_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='p'){
            if(black_pawn_white_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='r'){
            if(black_rook_white_king(i,j ,z,w)){r++;}
        }else if (board[i][j]=='r'){
            if(black_rook_white_king(i,j ,z,w)){r++;}
        }else if (board[i][j]=='b'){
            if(black_bishop_white_king(i,j,z,w)==1){r++;}
        }
        else if (board[i][j]=='b'){
            if(black_bishop_white_king(i,j ,z,w)){r++;}
        }
        else if (board[i][j]=='n'){
            if(black_knight_white_king(i,j ,z,w)){r++;}
        }
        else if (board[i][j]=='n'){
            if(black_knight_white_king(i,j ,z,w)){r++;}
        }
        else if (board[i][j]=='q'){
            if(black_queen_white_king(i ,j ,z,w)){r++;}
        }
        else if (board[i][j]=='k'){
            if(black_king_white_king(i,j ,z,w)){r++;}
        }
        else {
            continue;
        }}}

return r;
}



int check_black_king(){
int r=0,i,j,k,h,x,y,w,z;
for (i=0;i<8;i++){
    for(j=0;j<8;j++){
        if (board[i][j]=='k'){
        w=j;
        z=i;
        }
        else{
            continue ;
        }
    }
}
for (i=0;i<8;i++){
    for(j=0;j<8;j++){

        if(board[i][j]=='P'){
                if(white_pawn_black_king(i,j,z,w)){r++;}
        }
        else if (board[i][j]=='P'){
            if(white_pawn_black_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='P'){
             if(white_pawn_black_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='P'){
            if(white_pawn_black_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='P'){
             if(white_pawn_black_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='P'){
            if(white_pawn_black_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='P'){
            if(white_pawn_black_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='P'){
            if(white_pawn_black_king(i,j,z,w)){r++;}
        }else if (board[i][j]=='R'){
            if(white_rook_black_king(i,j ,z,w)){r++;}
        }else if (board[i][j]=='R'){
            if(white_rook_black_king(i,j ,z,w)){r++;}
        }else if (board[i][j]=='B'){
            if(white_bishop_black_king(i,j,z,w)==1){r++;}
        }
        else if (board[i][j]=='B'){
            if(white_bishop_black_king(i,j ,z,w)){r++;}
        }
        else if (board[i][j]=='N'){
            if(white_knight_black_king(i,j ,z,w)){r++;}
        }
        else if (board[i][j]=='N'){
            if(white_knight_black_king(i,j ,z,w)){r++;}
        }
        else if (board[i][j]=='Q'){
            if(white_queen_black_king(i ,j ,z,w)){r++;}
        }
        else if (board[i][j]=='K'){
            if(white_king_black_king(i,j ,z,w)){r++;}
        }
        else {
            continue;
        }}}

return r;
}


int play_white(){



     int o=0, l=0;
        scanf(" %c",&u);
        if (u!='s')
        {
            if(u!='l')
            {
                 if(u!='u')
                {
                    if (u!='r')
                        {
              scanf("%d",&o);
                scanf(" %c",&n);
                scanf("%d",&l);
                b = Conversion_Char(u);
                a= Conversion_Number(o);
                d= Conversion_Char(n);
                c=Conversion_Number(l);
            }
        }
        }
        }

       if (u=='s')
        {
            int i, j,h;
            char ch = 'l';
            FILE * Save;
            Save = fopen("Chess.txt","w");
            for(i=0 ; i<8; i++)
            {
                for (j=0; j<8; j++)
                {
                    fprintf(Save,"%c",board[i][j]);
                }
            }
            //    fprintf(Save,"%d",turn);
            fclose(Save);
            printf("Save Succesful\nCountinue Playing\n");
            return 0;
        }
        if (u=='l')
        {
            FILE * Save;
            Save = fopen("Chess.txt","r");
            char singleLine[150];
            while(!feof(Save))
            {
                for(int i=0; i<8; i++)
                {
                    for(int j=0; j<8; j++)
                    {
                        fscanf(Save,"%c", &board[i][j]);
                    }
                }
            }
            fclose(Save);
            printboard(board);
            printf("Load is Successful\n");
        return 0;
        }







    if (u=='u'){
            int var=p-1;
            for(int i=0;i<8;i++){
    for (int j=0;j<8;j++){
        printf("%c ",arr[var][i][j]);
    }
    printf ("\n");
}
    }

    if (u=='r'){
            int var=p+1;
            for(int i=0;i<8;i++){
    for (int j=0;j<8;j++){
        printf("%c ",arr[var][i][j]);
    }
    printf ("\n");
}
    }





        k=a+b;
         if(board[a][b]=='K'&& c==7&&d==6){
            x=valid_white_castling_right();
            if(x!=0){
                board[7][4]='-';
                board[7][5]='R';
                board[7][6]='K';
              board[7][7]='.';
                printboard(board);
                wkills(white_kill);
                bkills(black_kill);
              turn =0;
           }
            else{
                printf("you can't do this move\n");
            }

        }
       else if(board[a][b]=='K'&& c==7&&d==2){
            x=valid_white_castling_left();
            if(x!=0){
                board[7][4]='-';
                board[7][3]='R';
                board[7][2]='K';
                board[7][0]='-';
                printboard(board);
                wkills(white_kill);
                bkills(black_kill);
              turn =0;
            }
            else{
                printf("you can't do this move\n");
            }

        }


        else if(board[a][b]=='P')
        {
            x=valid_white_pawn(a,b,c,d);

            if(x!=0)
            {
            if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='P';
                    printboard (board);
                    wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                else    //-
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='P';
                    printboard (board);
                    wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                turn=0;
            }else{
             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='P';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='P';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=0;
                }
                    char w;
if(board[0][0]=='P' || board[0][1]=='P'||board[0][2]=='P'||board[0][3]=='P'||board[0][4]=='P'||board[0][5]=='P'||board[0][6]=='P'||board[0][7]=='P'){
    printf("Choose one of the following R,Q,B,N\n");
    scanf(" %c",&w);
    board[c][d]=w;
    printboard(board);
}
            }
            else
            {
                printf ("you can't do this move\n");
            }
        }
        else if(board[a][b]=='B')
        {
            x=valid_white_bishop(a,b,c,d);
            if(x!=0)
            {
                 if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='B';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                else    //-
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='B';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                turn=0;
            }else{
             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='B';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='B';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=0;
                }
            }
            else
            {
                printf ("you can't do this move \n");
            }
        }
        else if(board[a][b]=='Q')
        {
            x=valid_white_queen(a,b,c,d);
            if(x!=0)
            {
                  if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='Q';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                else    //-
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='Q';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                turn=0;
            }else{
             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='Q';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='Q';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=0;
                }
            }
            else
            {
                printf ("you can't do this move\n");
            }
        }
        else if(board[a][b]=='R')
        {
            x=valid_white_rook(a,b,c,d);
            if(x!=0)
            {
                 if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='R';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                else    //-
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='R';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                turn=0;
                if(a==7&&b==0&&board[7][0]=='R'&&valid_white_rook(a,b,c,d)==1){
                c3=0;
            }
            else if(a==7&&b==7&&board[7][7]=='R'&&valid_white_rook(a,b,c,d)==1){
                c2=0;
            }
            }else{
             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='R';
                    printboard (board);
                    wkills(white_kill);
                    bkills(black_kill);

                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='R';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=0;
                if(a==7&&b==0&&board[7][0]=='R'&&valid_white_rook(a,b,c,d)==1){
                c3=0;
            }
            else if(a==7&&b==7&&board[7][7]=='R'&&valid_white_rook(a,b,c,d)==1){
                c2=0;
            }
                }
            }
            else
            {
                printf ("you can't do this move\n");
            }
        }
        else if(board[a][b]=='N')
        {
            x=valid_white_knight(a,b,c,d);
            if(x!=0)
            {
                 if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='N';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                else    //-
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='N';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                turn=0;
            }else{
             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='N';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='N';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=0;
                }
            }
            else
            {
                printf ("you can't do this move\n");
            }
        }
        else if(board[a][b]=='K')
        {
            x=valid_white_king(a,b,c,d);
            if(x!=0)
            {  if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='K';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                else    //-
                {
                    temp=board[a][b];
                    black_kill[kill_count1]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='K';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count1++;
                }
                turn=0;
                c1=0;
            }else{
             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='K';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='K';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=0;
                c1=0;
                }
            }
            else
            {
                printf ("you can't do this move\n");
            }
        }
   for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        arr[p][i][j]=board[i][j];
    }
}



return 0;
}
int play_black(){
 while (1)
    {


    int o=0, l=0;
        scanf(" %c",&u);
        if (u!='s')
        {
            if(u!='l')
            {
              scanf("%d",&o);
                scanf(" %c",&n);
                scanf("%d",&l);
                b = Conversion_Char(u);
                a= Conversion_Number(o);
                d= Conversion_Char(n);
                c=Conversion_Number(l);
            }
        }

       if (u=='s')
        {
            int i, j;
            char ch = 'l';
            FILE * Save;
            Save = fopen("Chess.txt","w");
            for(i=0 ; i<8; i++)
            {
                for (j=0; j<8; j++)
                {
                    fprintf(Save,"%c",board[i][j]);
                }
            }
            fclose(Save);
            printf("Save Succesful\nCountinue Playing\n");
            return 0;
        }
        if (u=='l')
        {
            FILE * Save;
            Save = fopen("Chess.txt","r");
            char singleLine[150];
            while(!feof(Save))
            {
                for(int i=0; i<8; i++)
                {
                    for(int j=0; j<8; j++)
                    {
                        fscanf(Save,"%c", &board[i][j]);
                    }
                }
            }
            fclose(Save);
            printboard(board);
            printf("Load is Successful\n");
        return 0;
        }


if (u=='u'){
       for(int i=0;i<8;i++){
    for (int j=0;j<8;j++){
        printf("%c ",arr[p-1][i][j]);
    }
    printf ("\n");
}
}
    if (u=='r'){
             for(int i=0;i<8;i++){
    for (int j=0;j<8;j++){
        printf("%c ",arr[p+1][i][j]);
    }
    printf ("\n");
}
    }

        k=a+b;

            if(board[a][b]=='k'&& c==0&&d==6){
            x=valid_black_castling_right();
            if(x!=0){
                board[0][4]='.';
                board[0][5]='r';
                board[0][6]='k';
              board[0][7]='-';
                printboard(board);
                wkills(white_kill);
              bkills(black_kill);
              turn =0;
           }
            else{
                printf("you can't do this move\n");
            }

        }
        else if(board[a][b]=='k'&& c==0&&d==2){
            x=valid_black_castling_left();
            if(x!=0){
                board[0][4]='.';
                board[0][3]='r';
                board[0][2]='k';
                board[0][0]='.';
                printboard(board);
                wkills(white_kill);
                bkills(black_kill);
              turn =0;
            }
            else{
                printf("you can't do this move\n");
            }

        }
        else if(board[a][b]=='q')
        {
            x=valid_black_queen(a,b,c,d);
            if(x!=0)
            {
                 if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='q';
                    printboard (board);
                    wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;
                }

                else    //-
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='q';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;
                }
                turn=1;
            }else{

             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='q';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='q';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=1;
                }
                }
                else
                {
                    printf ("you can't do this move\n");
                }
            }

        else if(board[a][b]=='p')
        {
            x=valid_black_pawn(a,b,c,d);
            if(x!=0)
            {
                  if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='p';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;


                }

                else    //-
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='p';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;
                }
                turn=1;
            }else{

             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='p';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='p';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=1;
                }
                 char e;
                if (board[7][0]=='p' || board[7][1]=='p'||board[7][2]=='p'||board[7][3]=='p'||board[7][4]=='p'||board[7][5]=='p'||board[7][6]=='p'||board[7][7]=='p'){
                    printf("Choose one of the following r,q,b,n\n");
                    scanf(" %c",&e);
                    board[c][d]=e;
                    printboard(board);
                }

            }
            else
            {
                printf ("you can't do this move\n");
            }
        }
        else if(board[a][b]=='k')
        {
            x=valid_black_king(a,b,c,d);
            if(x!=0)
            {
                 if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='k';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;
                }

                else    //-
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='k';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;
                }
                turn=1;
                c4=0;
            }else{

             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='k';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='k';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=1;
                c4=0;
                }
            }
            else
            {
                printf ("you can't do this move\n");
            }
        }
        else if(board[a][b]=='r')
        {
            x=valid_black_rook(a,b,c,d);
            if(x!=0)
            {
                 if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='r';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;
                }

                else
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='r';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;
                }
                turn=1;
                 if(a==0&&b==0&&board[0][0]=='R'&&valid_black_rook(a,b,c,d)==1){
                c6=0;
            }
            else if(a==0&&b==7&&board[0][7]=='R'&&valid_black_rook(a,b,c,d)==1){
                c5=0;
            }
            }else{

             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='r';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='r';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=1;
                 if(a==0&&b==0&&board[0][0]=='R'&&valid_black_rook(a,b,c,d)==1){
                c6=0;
            }
            else if(a==0&&b==7&&board[0][7]=='R'&&valid_black_rook(a,b,c,d)==1){
                c5=0;
            }
                }
                }
                else
                {
                    printf ("you can't do this move\n");
                }
            }

        else if(board[a][b]=='n')
        {
            x=valid_black_knight(a,b,c,d);
            if(x!=0)
            {
                  if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='n';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;
                }

                else    //-
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='n';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;
                }
                turn=1;
            }else{

             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='n';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='n';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=1;
                }
            }
            else
            {
                printf("you can't do this move\n");
            }
        }
        else if(board[a][b]=='b')
        {
            x=valid_black_bishop(a,b,c,d);
            if(x!=0)
            {
                 if(board[c][d]!='.'&&board[c][d]!='-'){
               if(k%2==0)  //.
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='.';
                    board[c][d]='b';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;
                }

                else    //-
                {
                    temp=board[a][b];
                    white_kill[kill_count2]=board[c][d];
                    board[a][b]='-';
                    board[c][d]='b';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                    kill_count2++;
                }
                turn=1;
            }else{

             if(k%2==0)  //.
                {
                    temp=board[a][b];
                    board[a][b]='.';
                    board[c][d]='b';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                else    //-
                {
                    temp=board[a][b];
                    board[a][b]='-';
                    board[c][d]='b';
                    printboard (board);
                     wkills(white_kill);
                    bkills(black_kill);
                }
                turn=1;
                }
            }
            else
            {
                printf ("you can't do this move\n");
            }
        }
        else
        {
            printf("error\n");
        }

     for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        arr[p][i][j]=board[i][j];
    }
}

    return 0;
}
}

int valid_white_castling_right(){
int r;
if(board[7][4]=='K'&&board[7][7]=='R'&&c1==1&&c2==1&&board[7][5]=='.'&&board[7][6]=='-'){
    if(check_white_king()==0){
        board[7][4]='-';
        board[7][5]='K';
        if(check_white_king()==0){
            board[7][5]='.';
            board[7][6]='K';
            if(check_white_king()==0){
                r=1;
                board[7][6]='-';
                board[7][4]='K';

            }
            else{
                r=0;
                board[7][6]='-';
                board[7][4]='K';
            }

        }
        else{
            r=0;
            board[7][5]='.';
            board[7][4]='K';
        }
    }
    else{
        r=0;
    }
}


else {
        r=0;
}

  return r;
}


int valid_white_castling_left(){
    int r;
 if(board[7][4]=='K'&&board[7][0]=='R'&&c1==1&&c3==1&&board[7][2]=='-'&&board[7][3]=='.'&&board[7][1]=='.'){

    if(check_white_king()==0){
        board[7][4]='-';
        board[7][3]='K';
        if(check_white_king()==0){
            board[7][3]='-';
            board[7][2]='K';
            if(check_white_king()==0){
                r=1;
                board[7][2]='.';
                board[7][4]='K';

            }
            else{
                r=0;
                board[7][2]='.';
                board[7][4]='K';
            }

        }
        else{
            r=0;
            board[7][3]='-';
            board[7][4]='K';
        }
    }
    else{
        r=0;
    }
}
else {
        r=0;
}
return r;
}

int valid_black_castling_right(){
int r;
if(board[0][4]=='k'&&board[0][7]=='r'&&c4==1&&c5==1&&board[0][5]=='-'&&board[0][6]=='.'){
    if(check_black_king()==0){
        board[0][4]='.';
        board[0][5]='k';
        if(check_black_king()==0){
            board[0][5]='-';
            board[0][6]='k';
            if(check_black_king()==0){
                r=1;
                board[0][6]='.';
                board[0][4]='k';

            }
            else{
                r=0;
                board[0][6]='.';
                board[0][4]='k';
            }

        }
        else{
            r=0;
            board[0][5]='-';
            board[0][4]='k';
        }
    }
    else{
        r=0;
    }
}


else {
        r=0;
}

  return r;
}

int valid_black_castling_left(){
    int r;
 if(board[0][4]=='k'&&board[0][0]=='r'&&c4==1&&c6==1&&board[0][2]=='.'&&board[0][3]=='-'&&board[0][1]=='-'){

    if(check_black_king()==0){
        board[0][4]='.';
        board[0][3]='k';
        if(check_black_king()==0){
            board[0][3]='-';
            board[0][2]='k';
            if(check_black_king()==0){
                r=1;
                board[0][2]='.';
                board[0][4]='k';

            }
            else{
                r=0;
                board[0][2]='.';
                board[0][4]='k';
            }

        }
        else{
            r=0;
            board[0][3]='-';
            board[0][4]='k';
        }
    }
    else{
        r=0;
    }
}
else {
        r=0;
}
return r;
}

int stalemate(){
    int r,i,j,x=0,count1=0,count2=0,c1=0,c2=0,c3=0,c4=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]!='-'&&board[i][j]!='.'){
                x++;
            }
        }
    }
    if(x==2){
        r=1;
    }
    else if(x==3){
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(board[i][j]=='b'){
                    c1++;
                }
                else if(board[i][j]=='B'){
                    c2++;
                }
                else if(board[i][j]=='n'){
                    c3++;
                }
                else if(board[i][j]=='N'){
                    c4++;
                }
                else{
                    continue ;
                }
            }
        }
        if(c1==1||c2==1||c3==1||c4==1){
            r=1;
        }
        else{
            r=0;
        }
    }
    else if(x==4){
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(board[i][j]=='n'){
                    count1 ++;
                }
                else if(board[i][j]=='N'){
                    count2 ++;
                }
                else{
                    continue ;
                }
            }
        }
        if(count1 ==2||count2==2){
            r=1;
        }
        else{
            r=0;
        }
    }
    else{
        r=0;
    }
    return r;
}
int end_white_game(){
    int r=0,i,j,n,m;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]=='P'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_white_pawn(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else if(board[i][j]=='R'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_white_rook(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else if(board[i][j]=='N'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_white_knight(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else if(board[i][j]=='B'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_white_bishop(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else if(board[i][j]=='K'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_white_king(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else if(board[i][j]=='Q'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_white_queen(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else{
                continue ;
            }
        }
    }
    return r;
}
int end_black_game(){
    int r=0,i,j,n,m;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]=='p'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_black_pawn(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else if(board[i][j]=='r'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_black_rook(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else if(board[i][j]=='n'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_black_knight(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else if(board[i][j]=='b'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_black_bishop(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else if(board[i][j]=='k'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_black_king(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else if(board[i][j]=='q'){
                for(n=0;n<8;n++){
                    for(m=0;m<8;m++){
                        if(valid_black_queen(i,j,n,m)){
                            r++;
                        }
                        else{
                            continue ;
                        }
                    }
                }
            }
            else{
                continue ;
            }
        }
    }
    return r;
}
void wkills(char array[])
{
    int i=0;
    printf("white kills : ");
    for (i=0;i<16;i++){
        printf(" %c",array[i]);
    }
    printf("\n");
}
void bkills(char array[])
{
    int i=0;
    printf("black kills : ");
    for (i=0;i<16;i++){
        printf(" %c",array[i]);
    }
    printf("\n");
}
int main()
{    // int a,b,c,d,x,k;
//char temp;
printboard(board);
 while(1)
    {


    if(stalemate()==0){

    if(turn==1){
        if(check_white_king()!=0){
        printf("white king is under attack\n");
        printf("white turn\n");
       play_white();
      if(end_white_game()==0)
        {
            break ;
        }


        }
      else{
             printf("white turn\n");
       play_white();
        if(end_white_game()==0)
        {
            break ;
        }

        }

    }
    else {
         if(check_black_king()!=0){
        printf("black king is under attack\n");
        printf("black turn\n");
       play_black();
      if(end_black_game()==0)
        {
            break ;
        }


        }
      else{
             printf("black turn\n");
       play_black();
        if(end_black_game()==0)
        {
            break ;
        }
        }
    }
    }
    else{
   break ;
   }
p=p+1;
    }
    if(stalemate()==1){
        printf("game is draw!");
    }
    else if(check_white_king()!=0){
            printf("Black is winner");
    }
    else if(check_white_king==0){
        printf("game is draw*");
    }
    else if(check_black_king()!=0){
        printf("White is winner");
    }
    else if(check_black_king()==0){
        printf("game is draw//");
    }
    return 0;
}
