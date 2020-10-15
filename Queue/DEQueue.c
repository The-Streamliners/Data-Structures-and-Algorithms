#include<stdio.h>
#define MAX 100
int DEQueue[MAX],F,R;
void Ins_Front();
void Del_Front();
void Ins_Rear();
void Del_Rear();
void Display();
int main()
{
    F = R = -1;

    printf("DEQueue Implementation");
    int opt1;
    printf("\nF = %d, R = %d ( Initally Empty)\n",F,R);
    do{
        printf("\nOperations\n1.Insertion_Front\n2.Deletion_Front\n3.Insertion_Rear\n4.Deletion_Rear\n5.Display\n6.Exit Operation\nEnter your choice: ");
        scanf("%d",&opt1);
        switch(opt1){
            case(1):{
                Ins_Front();
                break;
            }
            case(2):{
                Del_Front();
                break;
            }
            case(3):{
                Ins_Rear();
                break;
            }
            case(4):{
                Del_Rear();
                break;
            }
            case(5):{
                Display();
                break;
            }
            case(6):{
                printf("\nExit Operation");
                break;
            }
            default:
                printf("Please enter valid choice:1/2/3/4/5/6");

        }
    }while(opt1 != 6);
}

void Ins_Front(){
    if(F == (R+1)%MAX){
        printf("\nOverflow");
    }
    else{
        int ele;
        //printf("Enter element to be inserted: ");
        scanf("%d ",&ele);
        if(F==-1)
            F=R=0;
        else if(F==0)
            F = MAX - 1;
        else
            F = F - 1;
        DEQueue[F] = ele;
        printf("\nF = %d, R = %d (Insertion_Front) | Value inserted = %d",F,R,ele);
    }
}

void Del_Front(){
    if(F==-1){
        printf("\nUnderflow");
    }
    else{
        int ele = DEQueue[F];
        if(F==R)
            F=R=-1;
        else if(F = MAX-1)
            F=0;
        else
            F = F + 1;

        printf("\nF = %d, R = %d (Deletion_Front)",F,R);
        printf("\nDeleted Element = %d",ele);
    }
}

void Ins_Rear(){
    if(F == (R+1)%MAX)
        printf("\nOverflow");
    else{
        int ele;
        //printf("Enter element to be inserted: ");
        scanf("%d ",&ele);
        if(F==-1)
            F = R = 0;
        else
            R = (R+1)%MAX;
        DEQueue[R] = ele;
        printf("\nF = %d, R = %d (Insertion_Rear) || Value inserted = %d ",F,R, ele);
    }
}

void Del_Rear(){
    if(F == -1){
        printf("\nUnderflow");
    }
    else{
        int ele = DEQueue[R];
        if(F==R)
            F=R=-1;
        else if(R==0)
            R = MAX - 1;
        else
            R = R - 1;
        printf("\nF = %d, R = %d (Deletion_Rear)",F,R);
        printf("\nDeleted Element = %d",ele);
    }
}

void Display(){
  int Front = F, Rear = R;
  if(Front==-1)
      printf("\nQueue is Empty\n");
  else{
      printf("\nThe elements in the queue: ");
      if(Front<=Rear){
          while(Front<=Rear){
           printf("%d ",DEQueue[Front]);
           Front++;
          }
      }
      else{
          while(Front<=MAX-1){
           printf(" %d ",DEQueue[Front]);
           Front++;
          }
          Front=0;
          while(Front<=Rear){
           printf(" %d ",DEQueue[Front]);
           Front++;
          }
      }
         printf("\n");
  }
}
