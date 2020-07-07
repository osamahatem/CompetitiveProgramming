/*
ID: 19semse1
PROG: transform
LANG: C++
*/

#include<cstdio>

int n;

void reset(char arr1[10][11],char arr2[10][11]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr2[i][j]=arr1[i][j];
        }
        arr2[i][j]='\0';
    }
    return;
}

void turn90(char arr1[10][11],char arr2[10][11]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr2[i][j]=arr1[n-1-j][i];
        }
        arr2[i][j]='\0';
    }
    return;
}

void turn180(char arr1[10][11],char arr2[10][11]){
    turn90(arr1,arr2);
    reset(arr2,arr1);
    turn90(arr1,arr2);
}

void turn270(char arr1[10][11],char arr2[10][11]){
    turn90(arr1,arr2);
    reset(arr2,arr1);
    turn90(arr1,arr2);
    reset(arr2,arr1);
    turn90(arr1,arr2);
}

void reflect(char arr1[10][11],char arr2[10][11]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr2[i][j]=arr1[i][n-1-j];
        }
        arr2[i][j]='\0';
    }
    return;
}

void mix1(char arr1[10][11],char arr2[10][11]){
    reflect(arr1,arr2);
    reset(arr2,arr1);
    turn90(arr1,arr2);
}

void mix2(char arr1[10][11],char arr2[10][11]){
    reflect(arr1,arr2);
    reset(arr2,arr1);
    turn180(arr1,arr2);
}

void mix3(char arr1[10][11],char arr2[10][11]){
    reflect(arr1,arr2);
    reset(arr2,arr1);
    turn270(arr1,arr2);
}

bool check(char arr1[10][11],char arr2[10][11]){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(arr1[i][j]!=arr2[i][j])
                return false;
    return true;
}

int main(){
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    int i;
    char grid[10][11],gridfinal[10][11],temp1[10][11],temp2[10][11];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",grid[i]);
    for(i=0;i<n;i++)
        scanf("%s",gridfinal[i]);
    reset(grid,temp1);
    reset(grid,temp2);
    turn90(temp1,temp2);
    if(check(temp2,gridfinal)){
        printf("1\n");
        return 0;
    }
    reset(grid,temp1);
    reset(grid,temp2);
    turn180(temp1,temp2);
    if(check(temp2,gridfinal)){
        printf("2\n");
        return 0;
    }
    reset(grid,temp1);
    reset(grid,temp2);
    turn270(temp1,temp2);
    if(check(temp2,gridfinal)){
        printf("3\n");
        return 0;
    }
    reset(grid,temp1);
    reset(grid,temp2);
    reflect(temp1,temp2);
    if(check(temp2,gridfinal)){
        printf("4\n");
        return 0;
    }
    reset(grid,temp1);
    reset(grid,temp2);
    mix1(temp1,temp2);
    if(check(temp2,gridfinal)){
        printf("5\n");
        return 0;
    }
    reset(grid,temp1);
    reset(grid,temp2);
    mix2(temp1,temp2);
    if(check(temp2,gridfinal)){
        printf("5\n");
        return 0;
    }
    reset(grid,temp1);
    reset(grid,temp2);
    mix3(temp1,temp2);
    if(check(temp2,gridfinal)){
        printf("5\n");
        return 0;
    }
    if(check(grid,gridfinal)){
        printf("6\n");
        return 0;
    }
    printf("7\n");
    return 0;
}
