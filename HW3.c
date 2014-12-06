
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

typedef struct treeNode
{
    int data;
    int count;
    struct treeNode *Leftchild;
    struct treeNode *Rightchild;
    

}treeNode;
treeNode *root = NULL;
int key; 

void *search(treeNode * node)
{
//struct treeNode* a=(struct treeNode*)node;

//printf("%4d      %2d\n",node->data ,node->count);
 
if(node==NULL)
    return 0;
if(key==node->data)
  printf("%4d      %2d\n",node->data ,node->count);

//printf("  %d\n",node->num );
search(node->Leftchild);
search(node->Rightchild);
return 0;
}




treeNode * Insert(treeNode *node,int data)
{
if(node==NULL)
{
    treeNode *temp;
    temp = (treeNode *)malloc(sizeof(treeNode));
    temp -> data = data;
    temp -> Leftchild = temp -> Rightchild = NULL;
    temp -> count=1;
    return temp;
}
if (data==node->data)
    node->count++;
else if(data >(node->data))
    node->Rightchild = Insert(node->Rightchild,data);
else if(data < (node->data))
    node->Leftchild = Insert(node->Leftchild,data);
return node;
}






int main()
{
  
  FILE * fp;
  char  line[20]="";
  char *tmp;

  int find[8]={0};
  int data[1000]={0};
  int i=0;
  int c=0;
  //size_t len = 0;
  

  fp = fopen ("test.txt" , "r");
  
  fgets(line,20,fp);
  //getline(&line,&len,fp);
 
  tmp=strtok(line," ");
  while (tmp != NULL) {
    find[i]=atoi(tmp);
    i=i+1;   
    c++;
        //printf("%s\n", tmp);
    tmp = strtok(NULL, " ");
  }
    
  for(i=0;i<c;++i){
    //NUM->find[i=]
    printf("  %d\n", find[i]);
  }
  i=0;
  while( !feof( fp ) ){
    fscanf(fp,"%d",&data[i]);    
    i=i+1;
  }
  fclose (fp);

  for(i=0;i<1000;i++){ 
    printf("%d\n", data[i]);
  }



  



 

  //treeNode *node = NULL;
  
  for(i=0;i<1000;i++){
    root = Insert(root,data[i]);
  }
  printf("element  count\n");

 
  //search(root,);
  pthread_t tid;
  void *ret;
               
  for(i=0;i<c;++i){
    key=find[i];
    //printf("%d\n",root->num);
    //search(root);
    pthread_create(&tid,NULL,search,(void*)root);
    pthread_join(tid, &ret);

  }

   
   return 0;
}