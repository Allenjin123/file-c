#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000
#define MAX 200
void write_f(){
	srand(time(NULL));
	FILE *tmp_file = fopen("tmp","w");
	if (tmp_file == NULL){
		fprintf(stdout,"Error: fail to open file");
		exit(1);
	}
	for (int i=0;i<SIZE;i++){
		int tmp = rand()%MAX;
		fprintf(tmp_file,"%d ",tmp);
	}
	fclose(tmp_file);
}
void read_f(int num){
	if (num >= MAX){
		fprintf(stdout,"Sorry, try another number");
		int a;
	       	scanf("%d",&a);
		read_f(a);
	}
	else{
		char *tmp_str =	malloc(SIZE*4*sizeof(char));
		char *tmp_ptr = tmp_str;
		FILE *tmp_file = fopen("tmp","r");
		if (tmp_file == NULL){
			fprintf(stdout,"Sorry Null pointer\n");	
			exit(2);
		}
		size_t n = (size_t) SIZE*4*sizeof(char);
		getline(&tmp_str, &n, tmp_file);
		//Here the usage of getline is correct, but remember only the pointer of the size is allowed
		//printf("%s",tmp_str);
		int cnt=0;
		char *tmp_test = tmp_str;
		while (tmp_str){
			long int tmp_num = strtol(tmp_ptr, &tmp_ptr, 10);
			if (num == tmp_num){
				printf("The correct number is found\n");
				cnt++;	
			}
			if (tmp_test == tmp_ptr)
				break;
			tmp_test = tmp_ptr;
		}
		fprintf(stdout,"Total %d number is found\n",cnt);
	}
}
int main(){
	write_f();
	int num;
	printf("PLease input the number you want:\n");
	scanf("%d",&num);
	read_f(num);
}

