#include<stdio.h>
#include<stdlib.h>

int size;
static int top1,top2,top3;

void push(int [],int,int);
int pop(int [],int);
void display(int []);

int main(){
	printf("Enter the size of each stack: ");
	scanf("%d",&size);
	int arr[size*3];
	top1=-1;
	top2=(size*2)-1;
	top3=(size*3)-1;
	printf("\nEnter 1 for push() element\nEnter 2 for pop() element\nEnter 3 to Exit\n");
	int flag=1,choice,n,ele;
	while(flag==1){
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nEnter the stack number: ");
				scanf("%d", &n);
				printf("Enter the element to be pushed: ");
				scanf("%d", &ele);
				push(arr,n,ele);
			
				break;
			case 2:
				printf("\nEnter the stack number: ");
				scanf("%d", &n);
				printf("%d has been pop out of stack %d",pop(arr,n),n);
				
				break;
			case 3:
				printf("\nExiting...");
				flag=0;
				break;
			default:
				printf("\nInvalid Choice! Enter again");
		}
	}

	return 0;
}

void push(int stack[],int stack_no, int element){
	if(stack_no==1){
		if(top1>=size-1){
			printf("\nStack Overflow!\n");
			return;
		}
		else
			stack[++top1]=element;
	}
	else if(stack_no==2){
		if(top2>(size*2)-1){
			printf("\nStack Overflow!\n");
			return;
		}
		else
			stack[++top2]=element;	
	}
	else if(stack_no==3){
		if(top3>(size*3)-1){
			printf("\nStack Overflow!\n");
			return;
		}
		else
			stack[++top3]=element;
	}
	else{
		printf("\nInvalid stack number");
		return;
	}
}

int pop(int stack[],int stack_no){
	if(stack_no==1){
		if(top1==-1){
			printf("\nStack Underflow!\n");
			exit(1);
		}
		else
			return stack[top1--];
	}
	else if(stack_no==2){
		if(top2==size){
			printf("\nStack Underflow!\n");
			exit(1);
		}
		else
			return stack[top2--];	
	}
	else if(stack_no==3){
		if(top3==(size*2)-1){
			printf("\nStack Underflow!\n");
			exit(1);
		}
		else
			return stack[top3--];	
	}
	else{
		printf("\nInvalid stack number");
	}
}

