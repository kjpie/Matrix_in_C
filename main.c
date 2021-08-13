//
//  main.c
//  softdev_4
//
//  Created by Kornsakon Dumrongkullanit on 13/8/2564 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double **matrix( int m, int n ) {
    double **mat = (double **)malloc( m*sizeof(double*) );
    if ( mat ) {
for ( int i=0; i < m; i++ ) {
           mat[i] = (double *)malloc( n*sizeof(double) );
    }
    }
    return mat;
}


void free_matrix( double **mat, int m, int n ) {
    if (mat) {
    for ( int i=0; i < n; i++ ) {
if (mat[i]) free(mat[i]);
    }
        free(mat);
}
}


double **copy_matrix(
    double **dst, double **src, int m, int n )
{
for ( int r=0; r < m; r++ ) {
    for ( int c=0; c < n; c++ ) {
dst[c][r] = src[c][r];
        }
    }
    return dst;
}


double **fill_matrix(
    double **mat, int m, int n, double *vec, int len )
{
int r, c;
for ( int i=0; i < len; i++ ) {
r = i/n;
c = i%m;
    mat[r][c] = vec[i];
    }
    return mat;
}


double **zero_matrix( double **mat, int m, int n ) {
for ( int r=0; r < m; r++ ) {
    for ( int c=0; c < n; c++ ) {
mat[r][c] = 0;
        }
    }
    return mat;
}


void print_matrix( double **mat, int m, int n ) {
    printf("[\n");
    for ( int r=0; r < m; r++ ) {
        printf(" [ ");
        for ( int c=0; c < n; c++ ) {
           printf( "%.0lf ", mat[r][c] );
    }
        printf("]\n");
    }
    printf("]\n");
}

//สร้าง Function Identity และรับ Parameter
double **identity(double **mat, int m, int n) {
    printf("Identity Matrix\n %d * %d\n",m,n);
    //Matrix จะมี Iden ได้ก็ต่อเมื่อ M = N
    if (m == n){
        //เข้าถึงแถวของ Matrix
        for (int r = 0; r < m; r++)
            {
                //เข้าถึงคอลัมน์ของ Matrix
                for (int c = 0; c < n; c++)
                {
                    //เอกลักษณ์ Matrix แถว = คอลัมน์
                    if (r == c)
                        mat[r][c] = 1;
                    else
                        mat[r][c] = 0;
                }
            }
        //ใช้งานฟังก์ชันด้านบน
        print_matrix(mat, m, n);
    } else {
        printf("\nNot have Identity\n");
    }
    
    return mat;
}

//สร้าง Function Transpose และรับ Parameter
double **transpose(double **mat, int m, int n){
    //สร้าง array เก็บข้อมูล transpose
    double trans[10][10];
    printf("\nFind Transpose");
    printf("\nEnter Element of matrix\n");
    //เข้าถึงแถว Matrix
    for (int i = 0; i < m; i++) {
        //เข้าถึงคอลัมน์ Matrix
        for (int j = 0; j < n; j++) {
          printf("Enter element a row %d column %d: ", i + 1, j + 1);
          //เปลี่ยนแปลงข้อมูล ของแถว และคอลัมน์ ใน Matrix
          scanf("%lf", &mat[i][j]);
        }
      }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //สลับ Transpose
            trans[j][i] = mat[i][j];
        }
      }
    printf("\nTranspose of the matrix:\n");
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //แสดงข้อมูลที่สลับอีกครั้ง
          printf("%.0lf  ", trans[i][j]);
          if (j == m - 1) {
            printf("\n");
          }
        }
      }
    return 0;
}

//สร้าง Function Multiple และรับ Parameter
double **multiple(double **mat, double **mat2, double **mat3, int m, int n, int p){
    printf("\nFind Multiple");
    printf("\nEnter the a matrix element=\n");
    //เข้าถึงแถว Matrix
     for(int i = 0; i < m; i++)
     {
       //เข้าถึงคอลัมน์ Matrix
       for(int j = 0; j < n; j++)
       {
         printf("a row %d column %d: ", i + 1, j + 1);
         //ใส่ค่า แถว และคอลัมน์ของ Matrix a
         scanf("%lf", &mat[i][j]);
       }
     }
    //ใส่ค่า แถว และคอลัมน์ของ Matrix a
    printf("\nEnter the b matrix element=\n");
      //เข้าถึงแถว Matrix
      for(int i = 0; i < n; i++)
      {
        //เข้าถึงคอลัมน์ Matrix
        for(int j = 0; j < p; j++)
        {
          printf("b row %d column %d: ", i + 1, j + 1);
          //ใส่ค่า แถว และคอลัมน์ของ Matrix
          scanf("%lf", &mat2[i][j]);
        }
      }
    
    for(int i = 0; i < m; i++)
      {
        for(int j = 0; j < n; j++)
        {
          //เซ็ทค่า Matrix ใหม่
          mat3[i][j]=0;
          for(int k = 0; k < n; k++)
          {
            //หาผลคูณของ Matrix
            mat3[i][j] += mat[i][k] * mat2[k][j];
          }
        }
      }
    printf("\nMultiple\n");
    for(int i = 0; i < m; i++)
      {
        for(int j = 0; j < p; j++)
        {
          //แสดงผลค่า Matrix
          printf("%.0lf\t", mat3[i][j]);
        }
      printf("\n");
      }
    return 0;
}



int main() {
    // create vectors of length 3
    int M, N, P;
    printf("Enter row : ");
    scanf("%d",&M);
    printf("Enter collumn : ");
    scanf("%d",&N);
    printf("Enter column of b matrix : ");
    scanf("%d",&P);
    //ประกาศตัวแปร โดยให้สร้าง Matrix จาก Function matrix
    double **m1 = matrix( M, N );
    double **m2 = matrix( N, P );
    double **mul = matrix(M, N);
    
    //สร้าง Number array 9 ช่อง 2 แถว
    double numbers[][9] = {
        {1,2,3,4,5,6,7,8,9 },
        {1,0,0,0,1,0,0,0,1 }
    };
    
    //สร้างช่ิงเปล่าสำหรับ Matrix
    fill_matrix( m1, M, N, numbers[0], M*N );
    fill_matrix( m2, N, P, numbers[1], N*P );
    fill_matrix( mul, M, N, numbers[0], M*N);

    //เรียนกใช้ฟังก์ชัน
    identity(m1, M,N);
    
    transpose(m1, M, N);
    
    multiple(m1, m2, mul, M, N, P);
    
    return 0;
}
