#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

//Critical Path Management Program uses Activity-on-Edge Network

int main()
{
 int i,j,k,m,p,count,n,critical[10];
 float Network[10][10],e[10],l[10],w,t;
 cout<<"\n\n___________________Critical Path Management Program___________________\n\n";
 cout<<"\n\nInput number of nodes: ";
 cin>>n;
 cout<<"\nInput the network matrix (-1 for index to exit):\n";
 for (i = 0; i < n; i++)
  for (j = 0; j < n; j++)
	Network[i][j]=0;
	//                          17
    //                   D-------------------->F---->Finish
    //                   ↑                     ↑
	//0 2 7            7 |                     |
    //0 3 7              |    7                |
    //                   A ------> C           |
    //1 4 13                  13               | 26
    //4 5 3              B ------> E-----------|
    //3 5 17
    //5 6 26
    //-1 -1 0
  while(1){
  cin>>j>>k>>w;

  if (j == -1)
  break;
  Network[j][k]=w;
 }
 e[0]=0;    //Setting Earliest start time of first activity
 for (k = 1; k < n; k++) {
  count = 0;
  //Forward Pass
  for (i = 0; i < n; i++) {
	if (Network[i][k] != 0) {
	 count++;   //Calculate no of paths to the node
	 m = i;
	}
  }
  if(count == 1)
	e[k] = e[m] + Network[m][k];
  else{
  e[k] = 0;
  for (i = 0; i < n; i++) {
	 if (Network[i][k] != 0) {
	  t = e[i] + Network[i][k];
	  if (t > e[k])        //Set Max Earliest Finish time for each activity in Forward pass
		e[k] = t;
	 }
   }
  }
 }
 cout<<"\nEarliest Finish Time: ";
 for (i = 0; i < n; i++)
  cout<<setw(4)<<e[i]<<" ";

 l[n-1] = e[n-1]; //Setting Latest finish time of last activity
 //Backward pass
 for (k = n-2; k >= 0; k--) {
  count = 0;
  for (j = 0; j < n; j++) {
	if (Network[k][j] != 0) {
	 count++;
	 p = j;
	}
  }
  if (count == 1)
	l[k] = l[p] - Network[k][p];
  else {
	l[k] = 1000;
	for (j=0; j < n; j++) {
	 if (Network[k][j] != 0) {
	  t = l[j] - Network[k][j];
	  if (t < l[k])
		l[k] = t;     //Set least latest Start time for each activity in Backward pass
	 }
	}
  }
 }
 cout<<endl;
 cout<<"  Latest Finish Time: ";
 for(i=0;i<n;i++)
  cout<<setw(4)<<l[i]<<" ";
 for(i = 1, k = 0; i < n; i++){
  if(e[i] == l[i])
	critical[k++] = i;
 }
 cout<<"\n\nThe critical path is: 0";
 for(i = 0; i < k; i++)
 printf("->%d", critical[i]);
 cout<<endl;
 return 0;
}
