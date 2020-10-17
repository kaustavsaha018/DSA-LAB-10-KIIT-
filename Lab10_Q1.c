#include<stdio.h>
#include<string.h>

void push(char);
char pop();
int precedence(char);
void infix_to_postfix(char []);
void evaluation_postfix(char []);
void int_push(int);
int int_pop();

int temp, length=0, index1=0, pos=0, top= -1;
char symbol, infix[30], postfix[30], stack[50];
int int_stack[30],int_top=0;
void main(){
	char infix[25];
	printf("Enter the infix expression:\n");
	gets(infix);
	infix_to_postfix(infix);
	printf("The equivalent postfix expression :\n");
	puts(postfix);
	evaluation_postfix(postfix);
}

void int_push(int element){
	int_stack[int_top++]=element;
}

int int_pop(){
	return int_stack[--int_top];
}

void evaluation_postfix(char postfix_exp[]){
	int i=0;
	int j=0;
	for(i=0,j=0;i<=strlen(postfix_exp);i++){	
		if(postfix_exp[i]!='+'&&postfix_exp[i]!='-'&&postfix_exp[i]!='*'&&postfix_exp[i]!='/'&&postfix_exp[i]!='^'){
			int_push(postfix_exp[i]-48);
			j++;
		}
		else{
			if(j>=1){
        		int num1 = int_pop();
        		int num2 = int_pop();
    
				switch (postfix_exp[i]){ 
            	case '+':		
					int_push(num2+num1);
					break; 
            	case '-':    	
            		int_push(num2-num1);
					break; 
            	case '*': 				
					int_push(num2*num1);
					break; 
            	case '/':		
					int_push(num2/num1);
					break; 
				case '^': 
					int_push(num2^num1);
					break; 
            	} 
			}
			
		}
	}
		printf("\n\nThe Evaluated Result will be : ");
		printf("%d",int_stack[0]);

}

void push(char symbol){
	top=top+1;
	stack[top]= symbol; 
}

char pop(){
	char temp;
	temp=stack[top];
	top=top-1;
	return temp; 
}

int precedence(char symbol){
	int priority;
	switch(symbol){
 		case '#':
 			priority=0;
 			break;
 		case '(':
 		case ')':
 			priority=1;
			break;
 		case '+':
 		case '-':
 			priority=2;
 			break;
 		case '*':
 		case '/':
 			priority=3;
 			break;
 		case '^':
 			priority=4;
 			break;
 
	}
return (priority);
}

void infix_to_postfix(char infix[]){
	length= strlen(infix);
	push('#');
	while(index1<length){
 		symbol= infix[index1];
 		switch(symbol){
			case '(':
				push(symbol);
 				break;
			case ')':
 				temp=pop();
				while(temp!='('){
					postfix[pos]=temp;
					pos++;
					temp=pop();
 				}
 				break;
 			case '+':
 			case '-':
			case '*':
			case '/':
 			case '^':
 				while(precedence(stack[top])>=precedence(symbol)){
 					temp=pop();
 					postfix[pos]=temp;
 					pos++;
 				}
				push(symbol);
				break;
 			default:
 				postfix[pos++]=symbol;
 				break;
 			}
		index1++;
	}

	while(top>0){
		temp=pop();
		postfix[pos++]=temp;
 		postfix[pos]='\0';
	} 
}
