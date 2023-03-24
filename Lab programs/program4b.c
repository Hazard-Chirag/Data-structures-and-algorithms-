/*b. Solving Tower of Hanoi problem with n disks.
*/

#include<stdio.h>
void towerofhanoi(int n,char s,char t,char d)
{
	if(n==0)
	return;
	towerofhanoi(n-1,s,d,t);
	printf("Move disc %d from %c to %c\n",n,s,d);
	towerofhanoi(n-1,t,s,d);
}
int main()
{
	int n;
	printf("ENter the number of disks\n");
	scanf("%d",&n);
	towerofhanoi(n,'A','B','C');
	return 0;
}
