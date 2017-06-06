 #include <stdio.h>
 #include "operators.h"
 #include "my_fscanf.h"
 int main(){
 	FILE *fp = fopen("read.txt","r");
 	int operand1, operand2,line=0;
 	char operator = ' ';
// 	double result;
 	double (*cal) (int ,int );
  	
  	fp = fopen("read.txt","r");
  	if(fp != NULL){
 		my_fscanf(fp, "%d", &line);
  	
 		for(int i=0; i<line && !feof(fp); i++) {
 			my_fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
  			switch(operator) {
  				case '+':
  				//result = add(operand1, operand2);
 				cal = add;
 				break;
 				case '-':
 				//result = minus(operand1, operand2);
 				cal = minus;
 				break;
 				case '*':
 				//result = mul(operand1, operand2);
 				cal = mul;
 				break;
 				case '/':
 				//result = div(operand1, operand2);
 				cal = div;
 				break;
 			}
//			result = cal(operand1,operand2);		
 			printf("%d %c %d = %f\n",
 				 operand1, operator, operand2, cal(operand1,operand2));
 		}
 	}
 	return 0;
 }
