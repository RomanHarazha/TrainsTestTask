#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

#define V 6
#define INF 9999

void printSolution(int solution[], int size, float trainsSorted[V][V], float timeSorted[V][V]) {
	float price = 0;
	float tripTime = 0;
	for (int i = 0; i < size; ++i){
		if (solution[i] == 0) printf("1902 ");
		else if (solution[i] == 1) printf("1909 ");
		else if (solution[i] == 2) printf("1921 ");
		else if (solution[i] == 3) printf("1929 ");
		else if (solution[i] == 4) printf("1937 ");
		else if (solution[i] == 5) printf("1981 ");
		if (i > 0) {
			if (solution[i - 1] == 0 && solution[i] == 1) {
				price += trainsSorted[0][1];
				tripTime += timeSorted[0][1];
			} 
			else if (solution[i - 1] == 0 && solution[i] == 2) {
				price += trainsSorted[0][2];
				tripTime += timeSorted[0][2];
			} 
			else if (solution[i - 1] == 0 && solution[i] == 3) {
				price += trainsSorted[0][3];
				tripTime += timeSorted[0][3];
			} 
			else if (solution[i - 1] == 0 && solution[i] == 4) {
				price += trainsSorted[0][4];
				tripTime += timeSorted[0][4];
			} 
			else if (solution[i - 1] == 0 && solution[i] == 5) {
				price += trainsSorted[0][5];
				tripTime += timeSorted[0][5];
			} 

			else if (solution[i - 1] == 1 && solution[i] == 0) {
				price += trainsSorted[1][0];
				tripTime += timeSorted[1][0];
			} 
			else if (solution[i - 1] == 1 && solution[i] == 2) {
				price += trainsSorted[1][2];
				tripTime += timeSorted[1][2];
			} 
			else if (solution[i - 1] == 1 && solution[i] == 3) {
				price += trainsSorted[1][3];
				tripTime += timeSorted[1][3];
			} 
			else if (solution[i - 1] == 1 && solution[i] == 4) {
				price += trainsSorted[1][4];
				tripTime += timeSorted[1][4];
			} 
			else if (solution[i - 1] == 1 && solution[i] == 5) {
				price += trainsSorted[1][5];
				tripTime += timeSorted[1][5];
			} 

			else if (solution[i - 1] == 2 && solution[i] == 0) {
				price += trainsSorted[2][0];
				tripTime += timeSorted[2][0];
			} 
			else if (solution[i - 1] == 2 && solution[i] == 1) {
				price += trainsSorted[2][1];
				tripTime += timeSorted[2][1];
			} 
			else if (solution[i - 1] == 2 && solution[i] == 3) {
				price += trainsSorted[2][3];
				tripTime += timeSorted[2][3];
			} 
			else if (solution[i - 1] == 2 && solution[i] == 4) {
				price += trainsSorted[2][4];
				tripTime += timeSorted[2][4];
			} 
			else if (solution[i - 1] == 2 && solution[i] == 5) {
				price += trainsSorted[2][5];
				tripTime += timeSorted[2][5];
			} 

			else if (solution[i - 1] == 3 && solution[i] == 0) {
				price += trainsSorted[3][0];
				tripTime += timeSorted[3][0];
			} 
			else if (solution[i - 1] == 3 && solution[i] == 1) {
				price += trainsSorted[3][1];
				tripTime += timeSorted[3][1];
			} 
			else if (solution[i - 1] == 3 && solution[i] == 2) {
				price += trainsSorted[3][2];
				tripTime += timeSorted[3][2];
			} 
			else if (solution[i - 1] == 3 && solution[i] == 4) {
				price += trainsSorted[3][4];
				tripTime += timeSorted[3][4];
			} 
			else if (solution[i - 1] == 3 && solution[i] == 5) {
				price += trainsSorted[3][5];
				tripTime += timeSorted[3][5];
			} 

			else if (solution[i - 1] == 4 && solution[i] == 0) {
				price += trainsSorted[4][0];
				tripTime += timeSorted[4][0];
			} 
			else if (solution[i - 1] == 4 && solution[i] == 1) {
				price += trainsSorted[4][1];
				tripTime += timeSorted[4][1];
			} 
			else if (solution[i - 1] == 4 && solution[i] == 2) {
				price += trainsSorted[4][2];
				tripTime += timeSorted[4][2];
			} 
			else if (solution[i - 1] == 4 && solution[i] == 3) {
				price += trainsSorted[4][3];
				tripTime += timeSorted[4][3];
			} 
			else if (solution[i - 1] == 4 && solution[i] == 5) {
				price += trainsSorted[4][5];
				tripTime += timeSorted[4][5];
			} 

			else if (solution[i - 1] == 5 && solution[i] == 0) {
				price += trainsSorted[5][0];
				tripTime += timeSorted[5][0];
			} 
			else if (solution[i - 1] == 5 && solution[i] == 1) {
				price += trainsSorted[5][1];
				tripTime += timeSorted[5][1];
			} 
			else if (solution[i - 1] == 5 && solution[i] == 2) {
				price += trainsSorted[5][2];
				tripTime += timeSorted[5][2];
			} 
			else if (solution[i - 1] == 5 && solution[i] == 3) {
				price += trainsSorted[5][3];
				tripTime += timeSorted[5][3];
			} 
			else if (solution[i - 1] == 5 && solution[i] == 4) {
				price += trainsSorted[5][4];
				tripTime += timeSorted[5][4];
			} 
		}
	}
	if (price < 3720) printf("Price: %.2f", price);
	if (tripTime < 46) printf("Time: %.2f ", tripTime);
	printf("\n");
}

void findSolution(bool graph[V][V], int visited[], int result[], int node, int start, int counter, float trainsSorted[V][V], float timeSorted[V][V]) {
	if (counter == V && node == start){
		result[counter] = node;
		printSolution(result, V + 1, trainsSorted, timeSorted);
	}
	if (counter >= V || visited[node] != -1){
		return;
	}
	visited[node] = 1;
	result[counter] = node;
	for (int i = 0; i < V; ++i) {
		if (graph[node][i] == 1)
		{
			findSolution(graph, visited, result, i, start, counter + 1, trainsSorted, timeSorted);
		}

	}
	visited[node] = -1;
}

void setDefault(int visited[]) {
	for (int i = 0; i < V; ++i){
		visited[i] = -1;
	}
}

void hamiltonianCycle(bool graph[V][V], float trainsSorted[V][V], float timeSorted[V][V]) {
	int visited[V];
	int result[V + 1];
	printf("\nAll Hamiltonian paths:\n\n");
	for (int i = 0; i < V; ++i){
		setDefault(visited);
		findSolution(graph, visited, result, i, i, 0, trainsSorted, timeSorted);
	}
}

void printSortedMatrix(float matrix[V][V], int stations[V]) {
	printf("\n%6s", "|");
	for (int i = 0; i < V; i++) {
		printf("%9d", stations[i]);
	}
	printf("\n");
	for (int i = 0; i < 60; i++) {
		printf("-");
	}
	printf("\n");
	for (int i = 0; i < V; ++i) {
		printf("%d |", stations[i]);
		for (int j = 0; j < V; ++j) {
			if (matrix[i][j] == INF) printf("%9s", "INF");
			else if (matrix[i][j] == 0) printf("%9.0f", matrix[i][j]);
			else printf("%9.2f", matrix[i][j]);
		}
		printf("\n");
	}
}

void sortByPrice(float trains[50][3], float trainsSorted[V][V]) {
	for (int i = 0; i < 250; ++i) {
		//1902
		if (trains[i][0] == 1902 && trains[i][1] == 1909) {
			if (trainsSorted[0][1] > trains[i][2]) trainsSorted[0][1] = trains[i][2];
		}
		else if (trains[i][0] == 1902 && trains[i][1] == 1921) {
			if (trainsSorted[0][2] > trains[i][2]) trainsSorted[0][2] = trains[i][2];
		}
		else if (trains[i][0] == 1902 && trains[i][1] == 1929) {
			if (trainsSorted[0][3] > trains[i][2]) trainsSorted[0][3] = trains[i][2];
		}
		else if (trains[i][0] == 1902 && trains[i][1] == 1937) {
			if (trainsSorted[0][4] > trains[i][2]) trainsSorted[0][4] = trains[i][2];
		}
		else if (trains[i][0] == 1902 && trains[i][1] == 1981) {
			if (trainsSorted[0][5] > trains[i][2]) trainsSorted[0][5] = trains[i][2];
		}
		//1909
		else if (trains[i][0] == 1909 && trains[i][1] == 1902) {
			if (trainsSorted[1][0] > trains[i][2]) trainsSorted[1][0] = trains[i][2];
		}
		else if (trains[i][0] == 1909 && trains[i][1] == 1921) {
			if (trainsSorted[1][2] > trains[i][2]) trainsSorted[1][2] = trains[i][2];
		}
		else if (trains[i][0] == 1909 && trains[i][1] == 1929) {
			if (trainsSorted[1][3] > trains[i][2]) trainsSorted[1][3] = trains[i][2];
		}
		else if (trains[i][0] == 1909 && trains[i][1] == 1937) {
			if (trainsSorted[1][4] > trains[i][2]) trainsSorted[1][4] = trains[i][2];
		}
		else if (trains[i][0] == 1909 && trains[i][1] == 1981) {
			if (trainsSorted[1][5] > trains[i][2]) trainsSorted[1][5] = trains[i][2];
		}
		//1921
		else if (trains[i][0] == 1921 && trains[i][1] == 1902) {
			if (trainsSorted[2][0] > trains[i][2]) trainsSorted[2][0] = trains[i][2];
		}
		else if (trains[i][0] == 1921 && trains[i][1] == 1909) {
			if (trainsSorted[2][1] > trains[i][2]) trainsSorted[2][1] = trains[i][2];
		}
		else if (trains[i][0] == 1921 && trains[i][1] == 1929) {
			if (trainsSorted[2][3] > trains[i][2]) trainsSorted[2][3] = trains[i][2];
		}
		else if (trains[i][0] == 1921 && trains[i][1] == 1937) {
			if (trainsSorted[2][4] > trains[i][2]) trainsSorted[2][4] = trains[i][2];
		}
		else if (trains[i][0] == 1921 && trains[i][1] == 1981) {
			if (trainsSorted[2][5] > trains[i][2]) trainsSorted[2][5] = trains[i][2];
		}
		//1929
		else if (trains[i][0] == 1929 && trains[i][1] == 1902) {
			if (trainsSorted[3][0] > trains[i][2]) trainsSorted[3][0] = trains[i][2];
		}
		else if (trains[i][0] == 1929 && trains[i][1] == 1909) {
			if (trainsSorted[3][1] > trains[i][2]) trainsSorted[3][1] = trains[i][2];
		}
		else if (trains[i][0] == 1929 && trains[i][1] == 1921) {
			if (trainsSorted[3][2] > trains[i][2]) trainsSorted[3][2] = trains[i][2];
		}
		else if (trains[i][0] == 1929 && trains[i][1] == 1937) {
			if (trainsSorted[3][4] > trains[i][2]) trainsSorted[3][4] = trains[i][2];
		}
		else if (trains[i][0] == 1929 && trains[i][1] == 1981) {
			if (trainsSorted[3][5] > trains[i][2]) trainsSorted[3][5] = trains[i][2];
		}
		//1937
		else if (trains[i][0] == 1937 && trains[i][1] == 1902) {
			if (trainsSorted[4][0] > trains[i][2]) trainsSorted[4][0] = trains[i][2];
		}
		else if (trains[i][0] == 1937 && trains[i][1] == 1909) {
			if (trainsSorted[4][1] > trains[i][2]) trainsSorted[4][1] = trains[i][2];
		}
		else if (trains[i][0] == 1937 && trains[i][1] == 1921) {
			if (trainsSorted[4][2] > trains[i][2]) trainsSorted[4][2] = trains[i][2];
		}
		else if (trains[i][0] == 1937 && trains[i][1] == 1929) {
			if (trainsSorted[4][3] > trains[i][2]) trainsSorted[4][3] = trains[i][2];
		}
		else if (trains[i][0] == 1937 && trains[i][1] == 1981) {
			if (trainsSorted[4][5] > trains[i][2]) trainsSorted[4][5] = trains[i][2];
		}
		//1981
		else if (trains[i][0] == 1981 && trains[i][1] == 1902) {
			if (trainsSorted[5][0] > trains[i][2]) trainsSorted[5][0] = trains[i][2];
		}
		else if (trains[i][0] == 1981 && trains[i][1] == 1909) {
			if (trainsSorted[5][1] > trains[i][2]) trainsSorted[5][1] = trains[i][2];
		}
		else if (trains[i][0] == 1981 && trains[i][1] == 1921) {
			if (trainsSorted[5][2] > trains[i][2]) trainsSorted[5][2] = trains[i][2];
		}
		else if (trains[i][0] == 1981 && trains[i][1] == 1929) {
			if (trainsSorted[5][3] > trains[i][2]) trainsSorted[5][3] = trains[i][2];
		}
		else if (trains[i][0] == 1981 && trains[i][1] == 1937) {
			if (trainsSorted[5][4] > trains[i][2]) trainsSorted[5][4] = trains[i][2];
		}
		//1902, 1909, 1921, 1929, 1937, 1981
	}
}

void buildGraph(float trainsSorted[V][V], bool graph[V][V]) {
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			if (trainsSorted[i][j] != 0 && trainsSorted[i][j] != INF)
				graph[i][j] = 1;
			else graph[i][j] = 0;
		}
	}
	printf("\nGraph to build Hamiltonian paths:\n\n");
	for (int i = 0; i < V; ++i) {
		printf("\t");
		for (int j = 0; j < V; ++j) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

struct Train {
	int num;
	int st1;
	int st2;
	float price;
	float tripTime;
};

void sortStructByPrice(const Train Obj[], float trainsSorted[V][V], float timeSorted[V][V]) {
	for (int i = 0; i < 250; ++i) {
		//1902
		if (Obj[i].st1 == 1902 && Obj[i].st2 == 1909) {
			if (trainsSorted[0][1] > Obj[i].price) trainsSorted[0][1] = Obj[i].price;
			if (timeSorted[0][1] > Obj[i].tripTime) timeSorted[0][1] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1902 && Obj[i].st2 == 1921) {
			if (trainsSorted[0][2] > Obj[i].price) trainsSorted[0][2] = Obj[i].price;
			if (timeSorted[0][2] > Obj[i].tripTime) timeSorted[0][2] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1902 && Obj[i].st2 == 1929) {
			if (trainsSorted[0][3] > Obj[i].price) trainsSorted[0][3] = Obj[i].price;
			if (timeSorted[0][3] > Obj[i].tripTime) timeSorted[0][3] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1902 && Obj[i].st2 == 1937) {
			if (trainsSorted[0][4] > Obj[i].price) trainsSorted[0][4] = Obj[i].price;
			if (timeSorted[0][4] > Obj[i].tripTime) timeSorted[0][4] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1902 && Obj[i].st2 == 1981) {
			if (trainsSorted[0][5] > Obj[i].price) trainsSorted[0][5] = Obj[i].price;
			if (timeSorted[0][5] > Obj[i].tripTime) timeSorted[0][5] = Obj[i].tripTime;
		}
		//1909
		else if (Obj[i].st1 == 1909 && Obj[i].st2 == 1902) {
			if (trainsSorted[1][0] > Obj[i].price) trainsSorted[1][0] = Obj[i].price;
			if (timeSorted[1][0] > Obj[i].tripTime) timeSorted[1][0] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1909 && Obj[i].st2 == 1921) {
			if (trainsSorted[1][2] > Obj[i].price) trainsSorted[1][2] = Obj[i].price;
			if (timeSorted[1][2] > Obj[i].tripTime) timeSorted[1][2] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1909 && Obj[i].st2 == 1929) {
			if (trainsSorted[1][3] > Obj[i].price) trainsSorted[1][3] = Obj[i].price;
			if (timeSorted[1][3] > Obj[i].tripTime) timeSorted[1][3] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1909 && Obj[i].st2 == 1937) {
			if (trainsSorted[1][4] > Obj[i].price) trainsSorted[1][4] = Obj[i].price;
			if (timeSorted[1][4] > Obj[i].tripTime) timeSorted[1][4] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1909 && Obj[i].st2 == 1981) {
			if (trainsSorted[1][5] > Obj[i].price) trainsSorted[1][5] = Obj[i].price;
			if (timeSorted[1][5] > Obj[i].tripTime) timeSorted[1][5] = Obj[i].tripTime;
		}
		//1921
		else if (Obj[i].st1 == 1921 && Obj[i].st2 == 1902) {
			if (trainsSorted[2][0] > Obj[i].price) trainsSorted[2][0] = Obj[i].price;
			if (timeSorted[2][0] > Obj[i].tripTime) timeSorted[2][0] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1921 && Obj[i].st2 == 1909) {
			if (trainsSorted[2][1] > Obj[i].price) trainsSorted[2][1] = Obj[i].price;
			if (timeSorted[2][1] > Obj[i].tripTime) timeSorted[2][1] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1921 && Obj[i].st2 == 1929) {
			if (trainsSorted[2][3] > Obj[i].price) trainsSorted[2][3] = Obj[i].price;
			if (timeSorted[2][3] > Obj[i].tripTime) timeSorted[2][3] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1921 && Obj[i].st2 == 1937) {
			if (trainsSorted[2][4] > Obj[i].price) trainsSorted[2][4] = Obj[i].price;
			if (timeSorted[2][4] > Obj[i].tripTime) timeSorted[2][4] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1921 && Obj[i].st2 == 1981) {
			if (trainsSorted[2][5] > Obj[i].price) trainsSorted[2][5] = Obj[i].price;
			if (timeSorted[2][5] > Obj[i].tripTime) timeSorted[2][5] = Obj[i].tripTime;
		}
		//1929
		else if (Obj[i].st1 == 1929 && Obj[i].st2 == 1902) {
			if (trainsSorted[3][0] > Obj[i].price) trainsSorted[3][0] = Obj[i].price;
			if (timeSorted[3][0] > Obj[i].tripTime) timeSorted[3][0] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1929 && Obj[i].st2 == 1909) {
			if (trainsSorted[3][1] > Obj[i].price) trainsSorted[3][1] = Obj[i].price;
			if (timeSorted[3][1] > Obj[i].tripTime) timeSorted[3][1] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1929 && Obj[i].st2 == 1921) {
			if (trainsSorted[3][2] > Obj[i].price) trainsSorted[3][2] = Obj[i].price;
			if (timeSorted[3][2] > Obj[i].tripTime) timeSorted[3][2] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1929 && Obj[i].st2 == 1937) {
			if (trainsSorted[3][4] > Obj[i].price) trainsSorted[3][4] = Obj[i].price;
			if (timeSorted[3][4] > Obj[i].tripTime) timeSorted[3][4] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1929 && Obj[i].st2 == 1981) {
			if (trainsSorted[3][5] > Obj[i].price) trainsSorted[3][5] = Obj[i].price;
			if (timeSorted[3][5] > Obj[i].tripTime) timeSorted[3][5] = Obj[i].tripTime;
		}
		//1937
		else if (Obj[i].st1 == 1937 && Obj[i].st2 == 1902) {
			if (trainsSorted[4][0] > Obj[i].price) trainsSorted[4][0] = Obj[i].price;
			if (timeSorted[4][0] > Obj[i].tripTime) timeSorted[4][0] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1937 && Obj[i].st2 == 1909) {
			if (trainsSorted[4][1] > Obj[i].price) trainsSorted[4][1] = Obj[i].price;
			if (timeSorted[4][1] > Obj[i].tripTime) timeSorted[4][1] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1937 && Obj[i].st2 == 1921) {
			if (trainsSorted[4][2] > Obj[i].price) trainsSorted[4][2] = Obj[i].price;
			if (timeSorted[4][2] > Obj[i].tripTime) timeSorted[4][2] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1937 && Obj[i].st2 == 1929) {
			if (trainsSorted[4][3] > Obj[i].price) trainsSorted[4][3] = Obj[i].price;
			if (timeSorted[4][3] > Obj[i].tripTime) timeSorted[4][3] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1937 && Obj[i].st2 == 1981) {
			if (trainsSorted[4][5] > Obj[i].price) trainsSorted[4][5] = Obj[i].price;
			if (timeSorted[4][5] > Obj[i].tripTime) timeSorted[4][5] = Obj[i].tripTime;
		}
		//1981
		else if (Obj[i].st1 == 1981 && Obj[i].st2 == 1902) {
			if (trainsSorted[5][0] > Obj[i].price) trainsSorted[5][0] = Obj[i].price;
			if (timeSorted[5][0] > Obj[i].tripTime) timeSorted[5][0] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1981 && Obj[i].st2 == 1909) {
			if (trainsSorted[5][1] > Obj[i].price) trainsSorted[5][1] = Obj[i].price;
			if (timeSorted[5][1] > Obj[i].tripTime) timeSorted[5][1] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1981 && Obj[i].st2 == 1921) {
			if (trainsSorted[5][2] > Obj[i].price) trainsSorted[5][2] = Obj[i].price;
			if (timeSorted[5][2] > Obj[i].tripTime) timeSorted[5][2] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1981 && Obj[i].st2 == 1929) {
			if (trainsSorted[5][3] > Obj[i].price) trainsSorted[5][3] = Obj[i].price;
			if (timeSorted[5][3] > Obj[i].tripTime) timeSorted[5][3] = Obj[i].tripTime;
		}
		else if (Obj[i].st1 == 1981 && Obj[i].st2 == 1937) {
			if (trainsSorted[5][4] > Obj[i].price) trainsSorted[5][4] = Obj[i].price;
			if (timeSorted[5][4] > Obj[i].tripTime) timeSorted[5][4] = Obj[i].tripTime;
		}
		//1902, 1909, 1921, 1929, 1937, 1981
	}
}

/*
Subtasks:
	- calculate minimal time for each route.
	- return Hamiltonian paths with only minimal weight;
Then display train numbers instead of stations etc.
*/

int main() {
	int h1, h2, m1, m2, s1, s2;
	float time1, time2;
	Train trainsStruct[250] = {};
	Train train;
	ifstream file("test_task_data.csv");
	string line;
	int linenum = 0;

	while (getline(file, line)) {
		istringstream linestream(line);
		string item;
		getline(linestream, item, ';');
		stringstream ss(item);
		ss >> train.num;
		getline(linestream, item, ';');
		stringstream ss2(item);
		ss2 >> train.st1;
		getline(linestream, item, ';');
		stringstream ss3(item);
		ss3 >> train.st2;
		getline(linestream, item, ';');
		stringstream ss4(item);
		ss4 >> train.price;

		//time 1
		getline(linestream, item, ':');
		stringstream ss5(item);
		ss5 >> h1;
		getline(linestream, item, ':');
		stringstream ss6(item);
		ss6 >> m1;
		getline(linestream, item, ';');
		stringstream ss7(item);
		ss7 >> s1;
		time1 = h1 * 3600 + m1 * 60 + s1;

		//time 2
		getline(linestream, item, ':');
		stringstream ss8(item);
		ss8 >> h2;
		getline(linestream, item, ':');
		stringstream ss9(item);
		ss9 >> m2;
		getline(linestream, item, ';');
		stringstream ss10(item);
		ss10 >> s2;
		time2 = h2 * 3600 + m2 * 60 + s2;

		if (time1 > time2) train.tripTime = ((time2 + 86400) - time1) / 3600;
		else train.tripTime = (time2 - time1) / 3600;

		trainsStruct[linenum] = train;
		linenum++;
	}
	file.close();

	printf("Train looks like:\n\nNumber: \t\t%d\nStation 1: \t\t%d\nStation 2: \t\t%d\nPrice: \t\t\t%.2f\nTrip time (in hours): \t%.2f\n\n",
		trainsStruct[0].num, trainsStruct[0].st1, trainsStruct[0].st2, trainsStruct[0].price, trainsStruct[0].tripTime);

	bool graph[V][V];
	float priceSorted[V][V] = { {0, INF, INF, INF, INF, INF},
								{INF, 0, INF, INF, INF, INF},
								{INF, INF, 0, INF, INF, INF},
								{INF, INF, INF, 0, INF, INF},
								{INF, INF, INF, INF, 0, INF},
								{INF, INF, INF, INF, INF, 0} };
	float timeSorted[V][V] = { {0, INF, INF, INF, INF, INF},
								{INF, 0, INF, INF, INF, INF},
								{INF, INF, 0, INF, INF, INF},
								{INF, INF, INF, 0, INF, INF},
								{INF, INF, INF, INF, 0, INF},
								{INF, INF, INF, INF, INF, 0} };
	int stations[V] = { 1902, 1909, 1921, 1929, 1937, 1981 };
	sortStructByPrice(trainsStruct, priceSorted, timeSorted);
	printf("\nMinimal price matrix:\n");
	printSortedMatrix(priceSorted, stations);
	printf("\nMinimal time matrix:\n");
	printSortedMatrix(timeSorted, stations);
	printf("\nINF represents non-existent routes.\n");
	buildGraph(priceSorted, graph);
	hamiltonianCycle(graph, priceSorted, timeSorted);
}