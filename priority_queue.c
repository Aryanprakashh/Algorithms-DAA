#include<stdio.h>
#include<limits.h>

typedef struct{
	int key;
	int id;
}process;

void swap(process *a,process *b){
    process temp=*a;
    *a=*b;
    *b=temp;
}

process find_max(process proc_arr[],int size){
	if(size<1){
		printf("Invalid operation.");
        return proc_arr[0];
	}
	return proc_arr[1];
}

void max_heapify(process proc_arr[],int i,int n){
    int max=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && proc_arr[left].key>proc_arr[max].key)
        max=left;
    if(right<=n && proc_arr[right].key>proc_arr[max].key)
        max=right;
    if(max!=i){
        swap(&proc_arr[max],&proc_arr[i]);
        max_heapify(proc_arr,max,n);
    }
}

process extract_max(process proc_arr[],int* size){
	if(*size<1){
		printf("-->Invalid operation.\n");
        return proc_arr[0];
	}
	process temp=proc_arr[1];
	proc_arr[1]=proc_arr[*size];
	(*size)--;
	max_heapify(proc_arr,1,*size);
	return temp;
}

void increase_key(process proc_arr[],int i,int size,int key){
	if(proc_arr[i].key>=key){
		printf("-->Invalid Operation.\n");
	}
	else{
		proc_arr[i].key=key;
		while(i>1 && proc_arr[i/2].key<key){
            swap(&proc_arr[i],&proc_arr[i/2]);
			i/=2;
		}
	}
}

void insert(process proc_arr[],int* size,process newproc){
	(*size)++;
	proc_arr[*size]=newproc;
	proc_arr[*size].key=INT_MIN;
	increase_key(proc_arr,*size,*size,newproc.key);
}

void build_max_heap(process proc_arr[],int n){
    for(int i=n/2;i>0;i--){
        max_heapify(proc_arr,i,n);
    }
}

void priority_queue(process array[],int n){
    build_max_heap(array,n);
	process temp;
    int a,id,key,flag;
	do{
		printf("1.find_max\n2.extract_max\n3.increase_key\n4.insert\n0.stop\n");
        scanf("%d",&a);
		switch(a){
			case 1:
				printf("-->%d\n",(find_max(array,n)).key);
                break;
			case 2:
				printf("-->%d\n",(extract_max(array,&n)).key);
                break;
			case 3:
				printf("-->Enter ID-Key pair");
				scanf("%d%d",&id,&key);
				for(int i=1;i<=n;i++){
					if(array[i].id==id){
						increase_key(array,i,n,key);
						flag=0;break;
					}
				}
				if(flag){
					printf("-->process not found.\n");
				}
				break;
			case 4:	
                printf("-->Enter ID-Key pair-> ");
                scanf("%d %d",&temp.id,&temp.key);
				insert(array,&n,temp);break;
			case 0:
				break;
			default:
				printf("-->incorrect choice.\n");
		}
	}while(a);
}

int main()
{	
	printf("Enter no of elements in priority queue(in begining): ");
	int n;
    scanf("%d",&n);
    // operating on index [1...n]
	process array[n+1];
    printf("Enter %d ID-Key pair\n->",n);
	for(int i=0;i<n;i++){
        scanf("%d %d",&array[i+1].id,&array[i+1].key);
    }
    // used to return for an invalid operations
    array[0].id=INT_MIN;
    array[0].key=INT_MIN;
	priority_queue(array,n);
	return 0;
}