#include<stdio.h>
#include<conio.h>
#include<time.h> 
#include<stdlib.h>
 
int score,moved,dim;
int **num;

void init_num();
void repeat_print(char s,int n);
void appear();
void prin_num();
void menu();
void play();
int main(void);
void add_same(int *p);
void game_fail();
void game_rule();

int main(void){
   
    moved = 0;
    score = 0;

    menu();
    
    return 0;
}



//重复打印
void repeat_print(char s,int n){
    for(int i = 0; i < n; i++)
    {
        printf("%c",s);
    }
}
//打印出num 
void prin_num( ){
    system("cls");

    printf("\t\t");
    repeat_print('-',dim*5);
    printf("\n\t\t");
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            if(num[i][j] == 0)
                printf("|    ");
            else
                printf("|%4d",num[i][j]);
        }
        printf("|\n");
        printf("\t\t");
        repeat_print('-',dim*5);
        printf("\n\t\t");
    }
    printf("\n\t\tMoved:%5d\n\t\t",moved);
    printf("\n\t\tYour Score:%5d\n\t\t",score);
}

//在0区域随机生成2或4
void appear(  ){
    int count_zero = 0;
    //int zero_index[dim*dim];
    int *zero_index = (int*)malloc(dim*dim*sizeof(int));
    int col, row, rnd;
    srand((int)time(0)); 

    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            if(num[i][j] == 0)
            {
                zero_index[count_zero] = 10*i + j; 
                count_zero ++;
            }
        }
    }

    if(count_zero == 1)
        rnd = 0;
    else if(count_zero ==0)
       return;
    else
       rnd = rand() % (count_zero - 1);

    col = zero_index[rnd] % 10;
    row = zero_index[rnd] / 10;
        
    if(rand() % 4 > 1)
        num[row][col] = 2;
    else 
        num[row][col] = 4;
    free(zero_index);

}

//将相同并且相邻的数字相加
void add_same(int *p){
    int i = 0,b;

    while(i < (dim-1))  
    {
        if(*(p + i) != 0)
        {
            for(b = i + 1; b < dim; b++)
            {
                if(*(p + b) != 0)
                {
                    if(*(p + b) == *(p + i))
                    {
                        *(p + i) = *(p + b) +*(p + i);
                        score = score + *(p + i);
                        *(p + b) = 0;
                        i = b + 1;
                        break; 
                    }
                    else
                    {
                        i = b;
                    } 
                }
            }
            if(b == dim)
               break; 
        }
        else
        {
            i++;
        }
        
    }
}

void game_fail(){
    int x;

    system("cls");

    printf("\t\t\t\t********************************************\n\t\t");
    printf("\t\t*   11      111111  111111  111111   11    *\n\t\t");
    printf("\t\t*   11      11  11  11      11       11    *\n\t\t");
    printf("\t\t*   11      11  11  111111  111111   11    *\n\t\t");
    printf("\t\t*   11      11  11      11  11             *\n\t\t");
    printf("\t\t*   111111  111111  111111  111111   11    *\n\t\t");
    printf("\t\t********************************************\n\t\t");
    printf("\t\t       [Press any key to return ......]     \n\t\t");


    x = getch();
    switch (x)
    {
    default:
        main();
        break;
    }
}

void game_rule(){
    system("cls");
    int x;

    printf("\t\t\t\t************************************************************\n\t\t");
    printf("\t\t*  SETTING THE GAME AREA BY INPUT NUMBER BEFORE THE GAME  *\n\t\t");
    printf("\t\t*           USE WASD CONTROL NUMBER MOVE DIRECTION        *\n\t\t");
    printf("\t\t*       ESC TO RETURN BACK TO MENU DURING THE GAME        *\n\t\t");
    printf("\t\t*                [Press any key to return ......]         *\n\t\t");
    printf("\t\t***********************************************************\n\t\t");

    x = getch();
    switch (x)
    {
    default:
        main();
        break;
    }
}


void play(){
    char key;
    int *d = (int*)malloc(dim*sizeof(int));
    int e;
    int ifmove;
    int isfail;

    appear();
    appear();
    while(1)
    {
        ifmove = 0;
        isfail = 1;
        appear();
        prin_num();
        key = getch();
        switch(key)
        {
            case 'W':
            case 'w':
                for(int j = 0; j < dim; j++)
                {
                    for(int i = 0; i < dim; i++)
                    {
                        d[i] = num[i][j];
                        num[i][j] = 0; 
                    }
                    add_same(d);
                    e = 0;
                    for(int i = 0; i < dim; i ++)
                    {
                        if(d[i] != 0)
                        {
                            num[e][j] = d[i];
                            if(i != e)
                               ifmove = 1;
                            e++;
                        }
                    }  
                }
                break;
            case 'A':
            case 'a':
                for(int i = 0; i < dim; i++)
                {
                    for(int j = 0; j < dim; j++)
                    {
                        d[j] = num[i][j];
                        num[i][j] = 0; 
                    }
                    add_same(d);
                    e = 0;
                    for(int j = 0; j < dim; j ++)
                    {
                        if(d[j] != 0)
                        {
                            num[i][e] = d[j];
                            if(j != e)
                               ifmove = 1;
                            e++;
                        }
                    }  
                }
                break;
            case 'S':
            case 's':
                for(int j = 0; j < dim; j++)
                {
                    for(int i = 0; i < dim; i++)
                    {
                        d[i] = num[i][j];
                        num[i][j] = 0; 
                    }
                    add_same(d);
                    e = dim - 1;
                    for(int i = dim-1; i >= 0; i--)
                    {
                        if(d[i] != 0)
                        {
                            num[e][j] = d[i];
                            if(i != e)
                               ifmove = 1;
                            e--;
                        }
                    }  
                }
                break;
            case 'D':
            case 'd':
                for(int i = 0; i < dim; i++)
                {
                    for(int j = 0; j < dim; j++)
                    {
                        d[j] = num[i][j];
                        num[i][j] = 0; 
                    }
                    add_same(d);
                    e = dim - 1;
                    for(int j = dim-1; j >= 0; j--)
                    {
                        if(d[j] != 0)
                        {
                            num[i][e] = d[j];
                            if(j != e)
                               ifmove = 1;
                            e--;
                        }
                    }  
                }
                break;
            case 27:
                system("cls");
                free(num);
                main();
                break;               
        }
        if(ifmove == 1)
            moved ++;
        for(int i = 0; i < dim; i++)
        {
            for(int j = 0; j < dim; j++)
            {
                if(i < dim -1 && j < dim -1)
                {
                    if(num[i][j] == num[i+1][j] || num[i][j] == num[i][j+1] )
                    {
                        isfail = 0;
                        goto end;
                    }
                }
                else if(i == dim -1 && j < dim - 1)
                {
                    if(num[i][j] == num[i][j+1])
                    {
                        isfail = 0;
                        goto end;
                    }
                }
                else if(j == dim -1 && i < dim - 1)
                {
                    if(num[i][j] == num[i+1][j])
                    {
                        isfail = 0;
                        goto end;
                    }
                }
            }
        }
        end:
        if(isfail == 1)
            game_fail();
    }

    free(d);
}

//初始化数组
void init_num(){
    //申请动态内存空间
   num = (int**)malloc(dim*sizeof(int*));
   for(int i = 0; i < dim; i++)
   {
       num[i] = (int*)malloc(dim*sizeof(int));
   }
   
   //初始化二维数组
   for(int i = 0; i < dim; i++)
   {
       for (int j = 0; j < dim; j++)
       {
           num[i][j] = 0;
       } 
   }
}

void menu(){
    system("cls");
    printf("\t******************************\t\n");
    printf("\t*   Enter 1 to start game  *\n");
    printf("\t*   Enter 2 to check rule  *\n");
    printf("\t*   Enter 3 to quit game   *\n");
    printf("\t*******************************\t\n");
    
    int x;
    scanf("%d",&x);

    switch (x)
    {
    case 1:
        printf("\tPlease set the game size...\n");
        scanf("%d",&dim);
        init_num();
        play();
        break;
    
    case 2:
        game_rule();
        break;
    case 3:
        exit(0);
        break;
    }



}
 
