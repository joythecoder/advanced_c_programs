/*This is the Dumb(Non-smart) version of the famous Tic-Tac-Tow game Made by joy_the_coder ;) */

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void disp(int a[][3]){
	cout<<"\n\n\t\t  ";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){	cout<<"|";
			if(a[i][j]==2)	   cout<<" O ";
			if(a[i][j]==1) 	cout<<" X ";
			if(a[i][j]==0)		cout<<"___";
		}
		cout<<"|\n\t\t\t  ";
//		cout<<"\n\t\t  -------------\n\t\t  ";
	}
}

int possible(int a[][3], int r, int c){
	if(a[r][c]==0) return 1;
	else return 0;
}

void rndm(int a[][3], int *x, int *y){
	int allow=0;
	while(allow!=1){
		*x=rand()%3;
		*y=rand()%3;
		
		if(a[*x][*y]==0) allow=1;
	}
}

int check(int a[][3]){
	int o=0,x=0,s=0,f=0;
	for(int i=0;i<3;i++){
		o=x=s=0;
		for(int j=0;j<3;j++){
			if(a[i][j]==0) s=f=1;
			if(a[i][j]==1)  x=1;
			if(a[i][j]==2)  o=1;
		}
		if(o==0 && x==1 && s==0) return 0;
		if(o==1 && x==0 && s==0) return 0;
		
		o=s=x=0;
		for(int j=0;j<3;j++){
			if(a[j][i]==0) s=1;
			if(a[j][i]==1)  x=1;
			if(a[j][i]==2)  o=1;
		}
		if(o==0 && x==1 && s==0) return 0;
		if(o==1 && x==0 && s==0) return 0;
	}
	if(f==0) return -1;
	
	o=x=s=0;
	for(int i=0;i<3;i++){
		
		if(a[i][i]==0)  s=1;
		if(a[i][i]==1)  x=1;
		if(a[i][i]==2)  o=1;
	}
	if(o==0 && x==1 && s==0) return 0;
	if(o==1 && x==0 && s==0) return 0;
	
	o=s=x=0;
	for(int i=0,j=2;i<3;i++,j--){
		if(a[i][j]==0) s=1;
		if(a[i][j]==1)  x=1;
		if(a[i][j]==2)  o=1;
	}
	if(o==0 && x==1 && s==0) return 0;
	if(o==1 && x==0 && s==0) return 0;
	
	return 1;
}

int main(){
	int r,c,a[3][3]={0},flag=1,x,y;
	srand(time(NULL));
	
	while(flag!=0){
user_tag:	cout<<"\n Enter the row and column of your turn(X) : "; cin>>r>>c;
		r--; c--;
		if(possible(a,r,c)) a[r][c]=1;
		else{
			cout<<"\n\n\t\t\t  AREA OCCUPIED ENTER AGAIN :- \n\n";
			goto user_tag;
		}
//		for(int i=0;i<3;i++) for(int j=0;j<3;j++) cout<<" ....  "<<a[i][j]<<" ";
		disp(a);
		flag=check(a);
		
		if(flag==0) cout<<"\n\n\t\t\t YOU WIN ... :) \n\n";
		else if(flag==-1) { cout<<"\n\n\t\t\t !!!! GAME DRAW !!!!\n"; break; }
		else{
		rndm(a,&x,&y);
		cout<<"\n Cpu Chooses : "<<x+1<<" & "<<y+1<<'\n';
		a[x][y]=2;
		disp(a);	   
		flag=check(a);
		
		if(flag==0) cout<<"\n\n\t\t\t YOU Lose... :'( \n\n";
		else if(flag==-1) { cout<<"\n\n\t\t\t !!!! GAME DRAW !!!!\n"; break; }
	   }
	}
	return 0;
}
