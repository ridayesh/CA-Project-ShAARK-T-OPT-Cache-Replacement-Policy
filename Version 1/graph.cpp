#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

// #define SIZE 50
#define SIZE 5

// int matrix[SIZE][SIZE];
int matrix[SIZE][SIZE] = {{0,0,0,0,0,},{1,0,1,0,1,},{1,1,0,0,1,},{1,0,0,0,1,},{0,1,1,0,0,},};

void __attribute__((noinline)) __attribute__((optimize("O0"))) INS_num_vertices(int num)
{
    // asm("");
}
void __attribute__((noinline)) __attribute__((optimize("O0"))) INS_graph(int src, int dst)
{
    // asm("");
}
void __attribute__((noinline)) __attribute__((optimize("O0"))) INS_done()
{
    // asm("");
}
void __attribute__((noinline)) __attribute__((optimize("O0"))) INS_base_graph(int* base)
{
    // asm("");
}
void __attribute__((noinline)) __attribute__((optimize("O0"))) INS_update_index(int vertex)
{
    // asm("");
}
void __attribute__((noinline)) __attribute__((optimize("O0"))) INS_update_sending_vertex(int vertex)
{
    // asm("");
}

int main ()
{
	// for(int a = 0; a < SIZE; a++){
	// for(int b = 0; b < SIZE; b++){
	
	// 	if(a == b) matrix[a][b] = 0;
	// 	else if(float(rand())/float(RAND_MAX) > 0.5){
	// 		matrix[a][b] = 1;
	// 	}
	// 	else{
	// 	matrix[a][b] = 0;
	// 	}
	// }
	// }
	vector<int> adj_list[SIZE];
	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
			if(matrix[i][j] == 1)
				adj_list[i].push_back(j);

	int dstData[SIZE], srcData[SIZE];
	
	INS_base_graph(&srcData[0]);
	
	INS_num_vertices(SIZE);

	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
			if(matrix[i][j] == 1)
				INS_graph(i, j);

	INS_done();

	//pull execution

	for(int i=0; i<SIZE; i++){
		INS_update_index(i);
		for(int j : adj_list[i]){
			INS_update_sending_vertex(j);
			int x = srcData[j];
			dstData[i] += x;
		}
	}

}


