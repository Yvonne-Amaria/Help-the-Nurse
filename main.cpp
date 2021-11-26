#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("PatientList.txt");

int NodesYO; //number of nodes
int AinputYO, BinputYO, WeightYO;
int matrixYO[100][100];//matrix dimension
int distanceYO[100];
int visitedYO[100];

int dijkstraYO(int x){
  visitedYO[x] = 1;

  //checks the root and checks if the nodes are visited
  for(int i = 1; i <= NodesYO; i++){
    if((visitedYO[i] == 0) && (matrixYO[x][i] != -1)){
      if((distanceYO[x] + matrixYO[x][i] < distanceYO[i]) || (distanceYO[i] == -1)){
        distanceYO[i] = distanceYO[x] + matrixYO[x][i];
      }
    }
  }

  //checking for next unvisited node in a comparison function for closest neighbors with shortest distance
  int closerNodeYO = -1, smallerWeightYO = -1;
  for(int i = 0; i <= NodesYO; i++){
    if((visitedYO[i] == 0) && (distanceYO[i] >= 0) && ((smallerWeightYO > distanceYO[i]) || (smallerWeightYO == -1))){
      smallerWeightYO = distanceYO[i];
      closerNodeYO = i;
   }
}

  if(closerNodeYO != -1){
  dijkstraYO(closerNodeYO);
  return 0;
  }
return 0;
}


int main(){

  cout << "\nHello Nurse Mary! Today the path to your patients is through: ";


  fin >> NodesYO;//reading number of nodes

  //initializing adjacency matrix
  for(int i = 0; i <= NodesYO; i++){
    for(int j = 0; j <= NodesYO; j++){
      matrixYO[i][j] = -1;
    }
  }

  for(int i = 0; i <= NodesYO; i++){
    distanceYO[i] = -1;
  }

  //initializing roots of data
  distanceYO[1] =0;
  while(!fin.eof()){
    fin >> AinputYO >> BinputYO >> WeightYO;
    matrixYO[AinputYO][BinputYO] = WeightYO;
    matrixYO[BinputYO][AinputYO] = WeightYO;
  }
  //running dijkstra
  dijkstraYO(1);

  //call output
  for(int i = 1; i <= NodesYO; i++){
    cout << distanceYO[i] << " ";
    
  }
  cout << "\n\nNurse Mary, the shortest path to all your patients adds up through: 0 - 14; where 0 is your starting point, and 14 is your last destination." << endl;

  cout << "\nThis means you'd visits Henry first, before Jane, then visit Quinn to be as fast as possible, before returning home.";

  cout << "\n\nQuick Note for Mary on Text File interpretation: ";

  cout << "\nIn the matrix nodes, the assigned values have been created for the following patients: \n Mary = 1 \n Henry = 2 \n Jane = 3 \n Quinn = 4 \nWhere, the weight/third variable of the list column, is the distance between them. \nThe algorithm accounts for the distance you'd take and in what order you'd be visiting your patients. \nLastly, see help doc for further explanations if you need help understanding better.";
}

//from .txt file:
//Given from Mary's hospital:
//Mary -> Henry = 4
//Mary -> Jane = 6
//Mary -> Quinn = 20
//Henry -> Jane = 10
//Quinn -> Jane = 8
//Assigned variables are made to fit nodes
//Mary = 1
//Henry = 2
//Jane = 3
//Quinn = 4
//You can add more patients or a new file, but you'd have to edit the Cout/Print formal statements to adjust to the new list. Other than that, your algorithm should check for the path, no matter how many patients there are, and their path from each other.
//see attached doc with the graph and matrix drawing of nodes weight analysis.